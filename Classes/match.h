/*
Description: Represents a single match between two teams.
Data Members:
Team* teamA - Pointer to the first team.
Team* teamB - Pointer to the second team.
dateTime - Date and time of the match.
bool status - Status of the match ("Scheduled" or "Completed").
Team* winner - Pointer to the winning team (nullptr if not completed).
*/
#include <string>
#include <ctime> 
#include "team.h"
using namespace std;

class Match {
private:
    Team* teamA; // Pointer to the first team
    Team* teamB; // Pointer to the second team
    time_t dateTime; // Date and time of the match
    bool status; // Status of the match ("Scheduled" or "Completed")
    Team* winner; // Pointer to the winning team (nullptr if not completed)

public:
    // Default constructor
    Match();

    // Parameterized constructor
    Match(Team* teamA, Team* teamB, time_t dateTime);

    // Update the status of the match
    void updateStatus(bool newStatus);

    // Update the winner of the match
    void setWinner(Team* winningTeam);

    // Getters
    Team* getWinner() const;
    string getStatus() const;
    time_t getDateTime() const;

    // Setters
    void setDateTime(time_t newDateTime);
};