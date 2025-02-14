#ifndef DESTINATION_H
#define DESTINATION_H

#include <iostream>
#include <string>

using namespace std;

class Destination {
private:
    int position;
    std::string name;

public:
    // Constructor
    Destination(int pos, std::string cityName);

    // Destructor
    ~Destination();

    // Getters
    void printPosition() const;
    void printDestinationName() const;
};

#endif // DESTINATION_H