// Implementation of a binary search tree for Storing list of teams based on their ranks

#include "team.h"
using namespace std;

class Node {
private:
    Team* data; // Pointer to the team object
    Node* left; // Pointer to the left child
    Node* right; // Pointer to the right child

public:
    Node(Team* data); // Constructor
    friend class BST; // Declaring BST as a friend class
};

class BST {
private:
    Node* root; // Pointer to the root node

    // Helper function to insert a team into the BST
    Node* insertHelper(Node* root, Team* team);

    // Helper function to search for a team in the BST
    Node* searchHelper(Node* root, string name);

    // Helper function to print the BST in-order
    void printInOrderHelper(Node* root);

    // Helper function to delete the BST
    void deleteHelper(Node* root);

public:
    BST(); // Constructor
    ~BST(); // Destructor

    // Insert a team into the BST
    void insert(Team* team);

    // Search for a team in the BST
    Team* search(string name);

    // Print the BST in-order
    void printInOrder();
};
