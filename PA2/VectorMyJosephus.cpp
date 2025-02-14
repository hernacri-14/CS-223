#include "VectorMyJosephus.h"

// Constructor
VectorMyJosephus::VectorMyJosephus(int m, int n) : M(m), N(n) {
    for (int i = 0; i < N; i++) {
        destinations.emplace_back(i, "City_" + to_string(i));
    }
}

// Destructor
VectorMyJosephus::~VectorMyJosephus() { clear(); }

// Clear vector
void VectorMyJosephus::clear() { destinations.clear(); }

// Return current size
int VectorMyJosephus::currentSize() const { return destinations.size(); }

// Check if empty
bool VectorMyJosephus::isEmpty() const { return destinations.empty(); }

// Eliminate destinations based on Josephus elimination
void VectorMyJosephus::eliminateDestination() {
    int index = 0;
    while (destinations.size() > 1) {
        index = (index + M - 1) % destinations.size();
        cout << "Eliminating: ";
        destinations[index].printDestinationName();
        destinations.erase(destinations.begin() + index);
    }
}

// Print all remaining destinations
void VectorMyJosephus::printAllDestinations() const {
    for (const auto &d : destinations) {
        d.printDestinationName();
    }
}