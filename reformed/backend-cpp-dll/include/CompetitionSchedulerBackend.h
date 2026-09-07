#pragma once

#ifdef _WIN32
    #ifdef COMPETITION_SCHEDULER_EXPORTS
        #define API __declspec(dllexport)
    #else
        #define API __declspec(dllimport)
    #endif
#else
    #define API
#endif

extern "C" {
    API int LoadTeams(const char* teamFilePath);
    API int GenerateSchedule(const char* matchesCsvPath, const char* logCsvPath);
    API int SetMatchWinner(int matchId, int winnerTeamId, const char* matchesCsvPath, const char* logCsvPath);
    API int SimulateCurrentRound(const char* matchesCsvPath, const char* logCsvPath);
    API int SimulateFullTournament(const char* matchesCsvPath, const char* logCsvPath);
    API int ResetTournament(const char* matchesCsvPath, const char* logCsvPath);
    API int ExportTeams(const char* teamsCsvPath);
    API int ExportMatches(const char* matchesCsvPath);
    API int ExportLogs(const char* logCsvPath);
    API int ExportReport(const char* reportHtmlPath);
    API int GetTournamentState();
    API int SchedulerGetLastError(char* buffer, int bufferSize);

    // Backward-compatible aliases.
    API int GenerateRoundOne(const char* matchesCsvPath, const char* logCsvPath);
    API int GenerateNextRound(const char* matchesCsvPath, const char* logCsvPath);
    API int SimulateAll(const char* matchesCsvPath, const char* logCsvPath);
}
