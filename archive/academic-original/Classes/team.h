/*
Description: Represents a team participating in the competition.
Data Members:
string name - Name of the team.
string members[4] - Array of strings for team member names (max 4 members per team).
int memberCount - Number of members in the team.
int rank - Rank assigned to the team.
*/

#include <string>
using namespace std;

class Team {
private:
    string name; // Name of the team
    string members[4]; // Array of strings for team member names (max 4 members per team)
    int memberCount; // Number of members in the team
    int rank; // Rank assigned to the team

public:
    // Default constructor
    Team();
    
    // Parameterized constructor
    Team(string name, string members[], int memberCount);
    
    //Getters
    string getName() const;
    string getMemberByIndex(int index) const;
    int getRank() const;
    int getMembersCount() const;

    // Setters
    void setRank(int newRank);
};