#pragma once

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <ctime>
#include "Team.h"
#include "Match.h"
using namespace std;

class Scheduler {
private:
    vector<Team*> teams;        // List of 16 teams sorted by rank
    vector<Match*> allMatches;  // List of all matches (preserve history)
    vector<Match*> currentMatches; // Matches for the current round
    int currentRound;           // Tracks the current round (1, 2, 3, 4)
    string currentMatchDate;    // Tracks the date of the next match

    // Helper function to initialize the match dates
    void initializeMatchDates() {
        currentMatchDate = Match::initializeFirstMatchDate(); // Set to current date
    }

    // Helper function to create a new match with an incremented date
    Match* createMatch(Team* team1, Team* team2) {
        Match* match = new Match(team1, team2, currentMatchDate);
        currentMatchDate = Match::incrementDate(currentMatchDate); // Increment the date for the next match
        allMatches.push_back(match); // Preserve in allMatches for history
        currentMatches.push_back(match); // Add to current round matches
        return match;
    }

public:
    // Constructor
    Scheduler() : currentRound(0) {
        initializeMatchDates();
    }

    // Add teams to the scheduler and sort them by rank
    void addTeams(const vector<Team*>& teamList) {
        teams = teamList;
        sort(teams.begin(), teams.end(), [](Team* t1, Team* t2) {
            return t1->getRank() < t2->getRank();
            });
    }

	// Sort teams by rank
	void sortTeams() {
		sort(teams.begin(), teams.end(), [](Team* t1, Team* t2) {
			return t1->getRank() < t2->getRank();
		});
	}

    // Round 1
    void round1() {
        if (currentRound != 0) {
            cout << "Invalid state for Round 1." << endl;
            return;
        }

		sortTeams();

        currentRound = 1;
        queue<Team*> groupA, groupB;

        for (int i = 0; i < 8; i++) {
            groupA.push(teams[i]);
            groupB.push(teams[i + 8]);
        }

        // Schedule matches for Round 1
        currentMatches.clear();
        while (!groupA.empty() && !groupB.empty()) {
            Team* teamA = groupA.front(); groupA.pop();
            Team* teamB = groupB.front(); groupB.pop();
            createMatch(teamA, teamB);
        }
    }

    // Round 2
    void round2() {
        if (currentRound != 1) {
            cout << "Invalid state for Round 2." << endl;
            return;
        }
        currentRound = 2;
        vector<Team*> winners;

        // Get winners from Round 1
        for (Match* match : currentMatches) {
            if (match->getStatus() == 1) {
                winners.push_back(match->getWinner());
            }
        }

        // Divide winners into two groups
        queue<Team*> groupA, groupB;
        for (int i = 0; i < 4; i++) {
            groupA.push(winners[i]);
            groupB.push(winners[i + 4]);
        }

        // Schedule matches for Round 2
        currentMatches.clear();
        while (!groupA.empty() && !groupB.empty()) {
            Team* teamA = groupA.front(); groupA.pop();
            Team* teamB = groupB.front(); groupB.pop();
            createMatch(teamA, teamB);
        }
    }

    // Semi-Final
    void semiFinal() {
        if (currentRound != 2) {
            cout << "Invalid state for Semi-Final." << endl;
            return;
        }
        currentRound = 3;
        vector<Team*> winners;

        // Get winners from Round 2
        for (Match* match : currentMatches) {
            if (match->getStatus() == 1) {
                winners.push_back(match->getWinner());
            }
        }

        // Schedule matches for Semi-Final
        currentMatches.clear();
        createMatch(winners[0], winners[1]);
        createMatch(winners[2], winners[3]);
    }

    // Final
    void finalRound() {
        if (currentRound != 3) {
            cout << "Invalid state for Final." << endl;
            return;
        }
        currentRound = 4;
        vector<Team*> winners;

        // Get winners from Semi-Final
        for (Match* match : currentMatches) {
            if (match->getStatus() == 1) {
                winners.push_back(match->getWinner());
            }
        }

        // Schedule the final match
        currentMatches.clear();
        createMatch(winners[0], winners[1]);
    }

    // Simulate matches and update winners
    void simulateMatches() {
        for (Match* match : currentMatches) {
            if (!match->getStatus()) {
                Team* winner = (rand() % 16 > 8) ? match->getTeam1() : match->getTeam2();
                match->setWinner(winner);
                match->setStatus(1); // Mark match as completed
				switch (currentRound) {
				case 1:
					winner->incrementRank(1);
					break;
				case 2:
					winner->incrementRank(2);
					break;
				case 3:
					winner->incrementRank(4);
					break;
				case 4:
					winner->incrementRank(8);
					break;
				}
            }
        }
    }

    // Reset the tournament
    void resetTournament() {
        teams.clear();
        for (Match* match : allMatches) {
            delete match;
        }
        allMatches.clear();
        currentMatches.clear();
        currentRound = 0;
        initializeMatchDates();
    }

	// Get all teams
	const vector<Team*>& getTeams() const {
		return teams;
	}

    // Get all matches
    const vector<Match*>& getMatches() const {
        return allMatches;
    }

	// Get Match by index
	Match* getMatch(int index) {
		return allMatches[index];
	}

    // Get current round
    int getCurrentRound() const {
        return currentRound;
    }
};
