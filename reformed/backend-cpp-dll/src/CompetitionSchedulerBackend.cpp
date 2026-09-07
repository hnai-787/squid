#define COMPETITION_SCHEDULER_EXPORTS
#include "../include/CompetitionSchedulerBackend.h"

#include <algorithm>
#include <cctype>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <vector>

struct Team { int id{}; std::string name; std::string members; int seedRank{}; int logoId{}; };
struct Match { int id{}; int round{}; std::string roundName; Team teamA; Team teamB; std::string dateText; std::string timeText; bool completed{}; Team winner; };
struct LogEntry { int id{}; std::string message; };

static std::vector<Team> g_teams;
static std::vector<Match> g_matches;
static std::vector<LogEntry> g_logs;
static std::string g_lastError;
static int g_nextLogId = 1;
static std::mt19937 g_rng{ std::random_device{}() };

static Team TBD(){ Team t; t.id=0; t.name="TBD"; t.members=""; t.seedRank=0; t.logoId=0; return t; }
static void setError(const std::string& e){ g_lastError=e; }
static std::string trim(const std::string& s){ const char* ws=" \t\r\n"; auto a=s.find_first_not_of(ws); if(a==std::string::npos)return""; auto b=s.find_last_not_of(ws); return s.substr(a,b-a+1); }
static std::vector<std::string> split(const std::string& text,char d){ std::vector<std::string> p; std::stringstream ss(text); std::string x; while(std::getline(ss,x,d)) p.push_back(trim(x)); return p; }
static std::string csvSafe(std::string v){ for(char& c:v){ if(c==',')c=';'; if(c=='\n'||c=='\r')c=' '; } return v; }
static std::string htmlEscape(const std::string& v){ std::string o; for(char c:v){ switch(c){ case '&':o+="&amp;";break; case '<':o+="&lt;";break; case '>':o+="&gt;";break; case '"':o+="&quot;";break; case '\'':o+="&#39;";break; default:o+=c; }} return o; }
static std::string roundName(int r){ if(r==1)return"Preliminary Round"; if(r==2)return"Round 2"; if(r==3)return"Semi-Finals"; if(r==4)return"Finals"; return"Round "+std::to_string(r); }
static std::string statusText(const Match& m){ if(m.completed)return"Completed"; if(m.teamA.id==0||m.teamB.id==0)return"Pending"; return"Ready"; }
static void logEvent(const std::string& m){ g_logs.push_back({g_nextLogId++,m}); }
static bool parsePositiveInt(const std::string& text,int& value){ std::string s=trim(text); if(s.empty())return false; if(!std::all_of(s.begin(),s.end(),[](unsigned char ch){return std::isdigit(ch)!=0;}))return false; try{ size_t pos=0; int parsed=std::stoi(s,&pos); if(pos!=s.size()||parsed<=0)return false; value=parsed; return true; }catch(...){ return false; } }
static bool hasWritablePath(const char* path,const std::string& label){ if(!path||std::string(path).empty()){ setError(label+" path is empty."); return false; } return true; }
static std::string dateForMatch(int offset){ std::time_t now=std::time(nullptr); std::tm lt{}; 
#ifdef _WIN32
localtime_s(&lt,&now);
#else
localtime_r(&now,&lt);
#endif
lt.tm_mday+=offset; std::mktime(&lt); std::ostringstream out; out<<std::put_time(&lt,"%Y-%m-%d"); return out.str(); }
static Match* findMatch(int id){ for(auto& m:g_matches) if(m.id==id) return &m; return nullptr; }
static bool ready(const Match& m){ return !m.completed && m.teamA.id!=0 && m.teamB.id!=0; }
static int completedMatches(){ int c=0; for(const auto& m:g_matches) if(m.completed)c++; return c; }
static bool hasSchedule(){ return g_matches.size()==15; }
static std::string championName(){ Match* m=findMatch(15); return (m&&m->completed)?m->winner.name:"TBD"; }
static Team chooseWinner(const Team& a,const Team& b){ int aw=std::max(1,100-a.seedRank), bw=std::max(1,100-b.seedRank); std::uniform_int_distribution<int> dist(1,aw+bw); return dist(g_rng)<=aw?a:b; }

static void placeWinnerInNextMatch(int id,const Team& winner){
    int target=0; bool slotA=true;
    if(id>=1&&id<=8){ target=9+((id-1)/2); slotA=((id-1)%2==0); }
    else if(id>=9&&id<=12){ target=13+((id-9)/2); slotA=((id-9)%2==0); }
    else if(id>=13&&id<=14){ target=15; slotA=(id==13); }
    else return;
    Match* next=findMatch(target); if(!next)return;
    if(slotA) next->teamA=winner; else next->teamB=winner;
    logEvent("Advanced "+winner.name+" to Match "+std::to_string(target)+".");
}

static bool completeMatch(int id,const Team& winner){
    Match* m=findMatch(id);
    if(!m){ setError("Match not found."); return false; }
    if(m->completed){ setError("This match is already completed."); return false; }
    if(!ready(*m)){ setError("This match is not ready yet. Complete earlier matches first."); return false; }
    if(winner.id!=m->teamA.id && winner.id!=m->teamB.id){ setError("Winner team does not belong to this match."); return false; }
    m->winner=winner; m->completed=true;
    logEvent("Match "+std::to_string(m->id)+" completed. Winner: "+winner.name+".");
    placeWinnerInNextMatch(m->id,winner);
    if(m->id==15) logEvent("Tournament champion declared: "+winner.name+".");
    return true;
}

static bool writeTeams(const char* path){ if(!hasWritablePath(path,"Teams CSV"))return false; std::ofstream f(path); if(!f){setError("Unable to write teams CSV.");return false;} f<<"TeamNo,TeamLogo,TeamName,TeamMembers,TeamRank\n"; for(const auto& t:g_teams) f<<t.id<<",Logo-"<<t.logoId<<","<<csvSafe(t.name)<<","<<csvSafe(t.members)<<","<<t.seedRank<<"\n"; return true; }
static bool writeMatches(const char* path){ if(!hasWritablePath(path,"Matches CSV"))return false; std::ofstream f(path); if(!f){setError("Unable to write matches CSV.");return false;} f<<"MatchNo,Round,Team1No,Team1,Team1Rank,Team2No,Team2,Team2Rank,Date,Time,Status,WinnerNo,Winner\n"; for(const auto& m:g_matches) f<<m.id<<","<<m.roundName<<","<<m.teamA.id<<","<<csvSafe(m.teamA.name)<<","<<m.teamA.seedRank<<","<<m.teamB.id<<","<<csvSafe(m.teamB.name)<<","<<m.teamB.seedRank<<","<<m.dateText<<","<<m.timeText<<","<<statusText(m)<<","<<(m.completed?std::to_string(m.winner.id):"0")<<","<<(m.completed?csvSafe(m.winner.name):"TBD")<<"\n"; return true; }
static bool writeLogs(const char* path){ if(!hasWritablePath(path,"Logs CSV"))return false; std::ofstream f(path); if(!f){setError("Unable to write logs CSV.");return false;} f<<"No,Event\n"; for(const auto& l:g_logs) f<<l.id<<","<<csvSafe(l.message)<<"\n"; return true; }
static bool writeAll(const char* mp,const char* lp){ if(mp&&std::string(mp).size()>0&&!writeMatches(mp))return false; if(lp&&std::string(lp).size()>0&&!writeLogs(lp))return false; return true; }

static bool loadTeamsFile(const std::string& path,std::vector<Team>& loaded){
    std::ifstream f(path); if(!f)return false; std::string line; int autoId=1;
    while(std::getline(f,line)){
        line=trim(line); if(line.empty())continue; if(line.find("TeamNo")!=std::string::npos||line.find("Id,")==0)continue;
        auto parts=split(line,','); if(parts.size()<3)continue; Team t; t.id=autoId; t.logoId=autoId;
        int parsedId=0, parsedRank=0;
        bool firstNum=parsePositiveInt(parts[0],parsedId);
        if(firstNum&&parts.size()>=4){ if(!parsePositiveInt(parts[2],parsedRank))continue; t.id=parsedId; t.name=parts[1]; t.seedRank=parsedRank; t.members=parts[3]; }
        else { if(!parsePositiveInt(parts[2],parsedRank))continue; t.name=parts[0]; t.members=parts[1]; t.seedRank=parsedRank; }
        if(t.name.empty()||t.members.empty())continue;
        t.logoId=((autoId-1)%22)+1; loaded.push_back(t); autoId++;
    }
    return true;
}

static int currentReadyRound(){
    for(int r=1;r<=4;r++){
        bool any=false;
        for(const auto& m:g_matches) if(m.round==r&&ready(m)) any=true;
        if(any)return r;
    }
    return 0;
}

extern "C" API int LoadTeams(const char* teamFilePath){
    try{ g_lastError.clear(); if(!teamFilePath||std::string(teamFilePath).empty()){setError("Team file path is empty.");return 0;} std::vector<Team> loaded; if(!loadTeamsFile(teamFilePath,loaded)){setError("Unable to open team file.");return 0;} if(loaded.size()!=16){setError("The scheduler requires exactly 16 valid teams.");return 0;} std::sort(loaded.begin(),loaded.end(),[](const Team&a,const Team&b){return a.seedRank<b.seedRank;}); for(size_t i=0;i<loaded.size();++i){loaded[i].id=(int)i+1; loaded[i].logoId=(int)(i%22)+1;} g_teams=loaded; g_matches.clear(); g_logs.clear(); g_nextLogId=1; logEvent("Loaded 16 teams."); return 1; }catch(const std::exception& ex){setError(ex.what());return 0;}
}

extern "C" API int GenerateSchedule(const char* matchesCsvPath,const char* logCsvPath){
    try{
        g_lastError.clear(); if(g_teams.size()!=16){setError("Load exactly 16 teams first.");return 0;}
        g_matches.clear(); Team tbd=TBD();
        for(int i=0;i<8;i++){ Match m; m.id=i+1; m.round=1; m.roundName=roundName(1); m.teamA=g_teams[i]; m.teamB=g_teams[i+8]; m.dateText=dateForMatch(i); m.timeText="2:00 PM"; m.completed=false; m.winner=tbd; g_matches.push_back(m); }
        for(int i=0;i<4;i++){ Match m; m.id=9+i; m.round=2; m.roundName=roundName(2); m.teamA=tbd; m.teamB=tbd; m.dateText=dateForMatch(8+i); m.timeText="2:00 PM"; m.completed=false; m.winner=tbd; g_matches.push_back(m); }
        for(int i=0;i<2;i++){ Match m; m.id=13+i; m.round=3; m.roundName=roundName(3); m.teamA=tbd; m.teamB=tbd; m.dateText=dateForMatch(12+i); m.timeText="2:00 PM"; m.completed=false; m.winner=tbd; g_matches.push_back(m); }
        Match f; f.id=15; f.round=4; f.roundName=roundName(4); f.teamA=tbd; f.teamB=tbd; f.dateText=dateForMatch(14); f.timeText="2:00 PM"; f.completed=false; f.winner=tbd; g_matches.push_back(f);
        logEvent("Generated complete 15-match tournament schedule.");
        return writeAll(matchesCsvPath,logCsvPath)?1:0;
    }catch(const std::exception& ex){setError(ex.what());return 0;}
}

extern "C" API int SetMatchWinner(int matchId,int winnerTeamId,const char* matchesCsvPath,const char* logCsvPath){
    try{ g_lastError.clear(); Match* m=findMatch(matchId); if(!m){setError("Match not found.");return 0;} Team w; if(m->teamA.id==winnerTeamId)w=m->teamA; else if(m->teamB.id==winnerTeamId)w=m->teamB; else {setError("Winner team ID does not belong to selected match.");return 0;} if(!completeMatch(matchId,w))return 0; return writeAll(matchesCsvPath,logCsvPath)?1:0; }catch(const std::exception& ex){setError(ex.what());return 0;}
}

extern "C" API int SimulateCurrentRound(const char* matchesCsvPath,const char* logCsvPath){
    try{ g_lastError.clear(); if(!hasSchedule()){setError("Generate schedule first.");return 0;} int r=currentReadyRound(); if(r==0){setError(completedMatches()==15?"Tournament is already complete.":"No ready round found. Complete earlier matches first.");return 0;} std::vector<int> ids; for(const auto& m:g_matches) if(m.round==r&&ready(m)) ids.push_back(m.id); for(int id:ids){ Match* m=findMatch(id); if(!m)continue; if(!completeMatch(id,chooseWinner(m->teamA,m->teamB)))return 0; } logEvent(roundName(r)+" simulated."); return writeAll(matchesCsvPath,logCsvPath)?1:0; }catch(const std::exception& ex){setError(ex.what());return 0;}
}

extern "C" API int SimulateFullTournament(const char* matchesCsvPath,const char* logCsvPath){
    try{ g_lastError.clear(); if(!hasSchedule()){setError("Generate schedule first.");return 0;} while(completedMatches()<15){ if(SimulateCurrentRound(matchesCsvPath,logCsvPath)==0)return 0; } logEvent("Full tournament simulation completed."); return writeAll(matchesCsvPath,logCsvPath)?1:0; }catch(const std::exception& ex){setError(ex.what());return 0;}
}

extern "C" API int ResetTournament(const char* matchesCsvPath,const char* logCsvPath){ g_lastError.clear(); g_matches.clear(); logEvent("Tournament reset."); return writeAll(matchesCsvPath,logCsvPath)?1:0; }
extern "C" API int ExportTeams(const char* p){ try{g_lastError.clear(); return writeTeams(p)?1:0;}catch(const std::exception& ex){setError(ex.what());return 0;} }
extern "C" API int ExportMatches(const char* p){ try{g_lastError.clear(); return writeMatches(p)?1:0;}catch(const std::exception& ex){setError(ex.what());return 0;} }
extern "C" API int ExportLogs(const char* p){ try{g_lastError.clear(); return writeLogs(p)?1:0;}catch(const std::exception& ex){setError(ex.what());return 0;} }

extern "C" API int ExportReport(const char* reportHtmlPath){
    try{
        g_lastError.clear(); if(!hasWritablePath(reportHtmlPath,"Report HTML"))return 0; std::ofstream f(reportHtmlPath); if(!f){setError("Unable to write HTML report.");return 0;}
        int total=(int)g_matches.size(), done=completedMatches(); std::string champ=championName();
        f<<"<!doctype html><html><head><meta charset='utf-8'><title>Competition Scheduler Tournament Report</title><style>";
        f<<"body{font-family:Segoe UI,Arial,sans-serif;background:#0f1113;color:#e8edf2;margin:0;padding:32px}.page{max-width:1100px;margin:auto}h1{color:#53ebb1;margin-bottom:4px}h2{color:#53ebb1;margin-top:28px;border-bottom:1px solid #2a2f33;padding-bottom:8px}.subtitle{color:#b4bbc2;margin-bottom:24px}.cards{display:grid;grid-template-columns:repeat(4,1fr);gap:14px;margin:20px 0}.card{background:#1a1d1f;padding:18px;border-radius:12px;border:1px solid #2a2f33}.metric{font-size:28px;font-weight:700;color:#53ebb1}.label{color:#b4bbc2;font-size:13px;margin-top:4px}table{width:100%;border-collapse:collapse;background:#1a1d1f;margin-top:12px;border-radius:12px;overflow:hidden}th,td{padding:10px 12px;border-bottom:1px solid #2a2f33;text-align:left;font-size:13px}th{background:#24292d;color:#53ebb1}tr:last-child td{border-bottom:none}.completed{color:#ffd166;font-weight:700}.ready{color:#53ebb1;font-weight:700}.pending{color:#b4bbc2}.footer{margin-top:30px;color:#b4bbc2;font-size:12px;text-align:center}";
        f<<"</style></head><body><div class='page'><h1>Competition Scheduler Tournament Report</h1><div class='subtitle'>16-Team Tournament - C++ DLL Backend + C# WinForms Frontend</div>";
        f<<"<div class='cards'><div class='card'><div class='metric'>"<<g_teams.size()<<"</div><div class='label'>Participating Teams</div></div><div class='card'><div class='metric'>"<<total<<"</div><div class='label'>Scheduled Matches</div></div><div class='card'><div class='metric'>"<<done<<"</div><div class='label'>Completed Matches</div></div><div class='card'><div class='metric'>"<<htmlEscape(champ)<<"</div><div class='label'>Champion</div></div></div>";
        f<<"<h2>Participating Teams</h2><table><tr><th>No.</th><th>Team</th><th>Rank</th><th>Members</th></tr>"; for(const auto& t:g_teams) f<<"<tr><td>"<<t.id<<"</td><td>"<<htmlEscape(t.name)<<"</td><td>"<<t.seedRank<<"</td><td>"<<htmlEscape(t.members)<<"</td></tr>"; f<<"</table>";
        f<<"<h2>Match Schedule</h2><table><tr><th>Match</th><th>Round</th><th>Team 1</th><th>Team 2</th><th>Date</th><th>Time</th><th>Status</th><th>Winner</th></tr>"; for(const auto& m:g_matches){std::string st=statusText(m),cls=st=="Completed"?"completed":(st=="Ready"?"ready":"pending"); f<<"<tr><td>Match "<<m.id<<"</td><td>"<<htmlEscape(m.roundName)<<"</td><td>"<<htmlEscape(m.teamA.name)<<"</td><td>"<<htmlEscape(m.teamB.name)<<"</td><td>"<<m.dateText<<"</td><td>"<<m.timeText<<"</td><td class='"<<cls<<"'>"<<st<<"</td><td>"<<(m.completed?htmlEscape(m.winner.name):"TBD")<<"</td></tr>";} f<<"</table>";
        f<<"<h2>Round Results</h2>"; for(int r=1;r<=4;r++){f<<"<h3>"<<htmlEscape(roundName(r))<<"</h3><table><tr><th>Match</th><th>Fixture</th><th>Status</th><th>Winner</th></tr>"; for(const auto& m:g_matches) if(m.round==r) f<<"<tr><td>Match "<<m.id<<"</td><td>"<<htmlEscape(m.teamA.name)<<" vs "<<htmlEscape(m.teamB.name)<<"</td><td>"<<statusText(m)<<"</td><td>"<<(m.completed?htmlEscape(m.winner.name):"TBD")<<"</td></tr>"; f<<"</table>";}
        f<<"<h2>System Activity Log</h2><table><tr><th>No.</th><th>Event</th></tr>"; for(const auto& l:g_logs) f<<"<tr><td>"<<l.id<<"</td><td>"<<htmlEscape(l.message)<<"</td></tr>"; f<<"</table>";
        f<<"<h2>Technical Notes</h2><div class='card'>Backend: C++ DLL<br>Frontend: C# WinForms<br>Data Structures: vector, queue, sorting, classes/structs<br>Tournament Model: Fixed 16-team knockout bracket with 15 total matches.</div><div class='footer'>Competition Scheduler - Data Structures Academic Project</div></div></body></html>";
        return 1;
    }catch(const std::exception& ex){setError(ex.what());return 0;}
}

extern "C" API int GetTournamentState(){ if(!hasSchedule())return 0; if(completedMatches()==15)return 5; int r=currentReadyRound(); return r!=0?r:0; }
extern "C" API int SchedulerGetLastError(char* buffer,int size){ if(!buffer||size<=0)return 0; int i=0; for(;i<size-1&&i<(int)g_lastError.size();++i)buffer[i]=g_lastError[i]; buffer[i]='\0'; return i; }
extern "C" API int GenerateRoundOne(const char* m,const char* l){ return GenerateSchedule(m,l); }
extern "C" API int GenerateNextRound(const char* m,const char* l){ setError("Rounds are advanced automatically in the Option-A bracket workflow."); writeAll(m,l); return 0; }
extern "C" API int SimulateAll(const char* m,const char* l){ return SimulateFullTournament(m,l); }
