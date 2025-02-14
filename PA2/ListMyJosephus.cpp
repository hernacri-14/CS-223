#include "ListMyJosephus.h"

// Constructor
ListMyJosephus::ListMyJosephus(int m, int n) : M(m), N(n) {
    for (int i = 0; i < N; i++) {
        destinations.emplace_back(i, "City_" + to_string(i));
    }
}

// Destructor
ListMyJosephus::~ListMyJosephus() { clear(); }

// Clear list
void ListMyJosephus::clear() { destinations.clear(); }

// Return current size
int ListMyJosephus::currentSize() const { return destinations.size(); }

// Check if empty
bool ListMyJosephus::isEmpty() const { return destinations.empty(); }

// Eliminate destinations based on Josephus elimination
void ListMyJosephus::eliminateDestination() {
    auto it = destinations.begin();
    while (destinations.size() > 1) {
        for (int count = 1; count < M; ++count) {
            ++it;
            if (it == destinations.end()) it = destinations.begin();
        }
        cout << "Eliminating: ";
        it->printDestinationName();
        it = destinations.erase(it);
        if (it == destinations.end()) it = destinations.begin();
    }
}

// Print all remaining destinations
void ListMyJosephus::printAllDestinations() const {
    for (const auto &d : destinations) {
        d.printDestinationName();
    }
}