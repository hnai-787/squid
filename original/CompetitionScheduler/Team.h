#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Team {
private:
	int teamId;
    string teamName;
    vector<string> members;
    int rank;

public:
    // Constructor
    Team(int teamID, string name, vector<string> membersList, int rank) {
		this->teamId = teamID;
        this->teamName = name;
        this->members = membersList;
        this->rank = rank;
    }

    // Getters and Setters
    string getTeamName() const {
        return teamName;
    }

    string getMembers() const {
		string membersStr;
		for (const string& member : members) {
			membersStr += member + "\n";
		}
		return membersStr;
    }

    int getRank() const {
        return rank;
    }

	int getTeamId() const {
		return teamId;
	}

	void setTeamId(int id) {
		teamId = id;
	}

	// Increment the rank of the team
	void incrementRank(int increment) {
		rank += increment;
	}

	// Display team details
    void displayTeam() const {
        cout << "Team: " << teamName << " | Rank: " << rank << " | Members: ";
        for (const string& member : members) {
            cout << member << " ";
        }
        cout << endl;
    }

    // Comparison operator to sort teams based on rank
    bool operator<(const Team& other) const {
        return this->rank < other.rank;
    }
};
