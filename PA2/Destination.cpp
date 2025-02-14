#include "Destination.h"

// Constructor
Destination::Destination(int pos, std::string cityName) : position(pos), name(cityName) {}

// Destructor
Destination::~Destination() {}

// Print position
void Destination::printPosition() const {
    cout << "Position: " << position << std::endl;
}

// Print destination name
void Destination::printDestinationName() const {
    cout << "Destination: " << name << std::endl;
}