#pragma once

#include "Team.h" // Include the Team header file
#include <string>
#include <iostream>
#include <ctime>  // For handling date and time
using namespace std;

class Match {
private:
    Team* team1;
    Team* team2;
    string date;  // Match date
    bool status;      // 0 for "Scheduled", 1 for "Completed"
    Team* winner;

public:
    // Constructor
    Match(Team* t1, Team* t2, string matchDate) {
        this->team1 = t1;
        this->team2 = t2;
        this->date = matchDate;
        this->status = false;  // Default status is "Scheduled"
        this->winner = nullptr;
    }

    // Getters and Setters
    Team* getTeam1() const {
        return team1;
    }

    Team* getTeam2() const {
        return team2;
    }

    string getDate() const {
        return date;
    }

    bool getStatus() const {
        return status;
    }

    Team* getWinner() const {
        return winner;
    }

    void setStatus(bool status) {
        this->status = status;
    }

    void setWinner(Team* winner) {
        this->winner = winner;
    }

    // Display match details
    void displayMatch() const {
        cout << "Match between " << team1->getTeamName() << " vs " << team2->getTeamName()
            << " | Date: " << date
            << " | Time: 2:00 PM"
            << " | Status: " << (status ? "Completed" : "Scheduled");

        if (status) {
            cout << " | Winner: " << winner->getTeamName();
        }
        cout << endl;
    }

    // Static function to initialize the first match's date
    static string initializeFirstMatchDate() {
        time_t now = time(nullptr);
        struct tm timeInfo;
        localtime_s(&timeInfo, &now);

        char buffer[11]; // Format: YYYY-MM-DD
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeInfo);
        return string(buffer);
    }

    static string incrementDate(const string& previousDate) {
        struct tm timeInfo = {};
        if (sscanf_s(previousDate.c_str(), "%d-%d-%d", &timeInfo.tm_year, &timeInfo.tm_mon, &timeInfo.tm_mday) != 3) {
            // Handle error
            cerr << "Error parsing date string: " << previousDate << endl;
            return "";
        }
        timeInfo.tm_year -= 1900; // Adjust year
        timeInfo.tm_mon -= 1;    // Adjust month (0-based)
        timeInfo.tm_mday += 1;   // Increment the day by 1

        time_t updatedTime = mktime(&timeInfo);
        localtime_s(&timeInfo, &updatedTime);

        char buffer[11]; // Format: YYYY-MM-DD
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeInfo);
        return string(buffer);
    }
};

