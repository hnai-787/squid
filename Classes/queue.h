// Implementation of Queue for scheduling matches

#include "match.h"
using namespace std;

class Node {
private:
    Match* data; // Pointer to the match object
    Node* next; // Pointer to the next node
};

class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear; // Pointer to the rear of the queue

public:
    Queue(); // Constructor
    ~Queue(); // Destructor

    // Check if the queue is empty
    bool isEmpty();

    // Enqueue a match into the queue
    void enqueue(Match* match);

    // Dequeue a match from the queue
    Match* dequeue();
};