/*
Description: Manages the entire competition, including team registration, match scheduling, and progression of rounds.

Data Members:
BST<Team> teams - List of all teams.
Queue<Match> matches - Queue for scheduling matches.
int currentRound - The current round of the competition (1 to 4).
*/

#include "team.h"
#include "match.h"
#include "bst.h"
#include "queue.h"
#include <iostream>
#include <ctime>
using namespace std;

class Scheduler {
private:
    BST teams; // List of all teams
    Queue matches; // Queue for scheduling matches
    int currentRound; // The current round of the competition (1 to 4)

public:
    // Default constructor
    Scheduler();

    // Load teams from a file
    void loadTeamsFromFile(string filename);

    // Divide teams into groups based on their ranks
    void divideTeamsIntoGroups();

    // Schedule matches for the current round
    void scheduleMatches();

    // Simulate Progress of the a round
    void simulateRound();

    // Get match data
    void displayScheduledMatches();
    void displayCompletedMatches();
        
    // Destructor
    ~Scheduler();
};