#ifndef LISTMYJOSEPHUS_H
#define LISTMYJOSEPHUS_H

#include <iostream>
#include <list>
#include "Destination.h"

class ListMyJosephus {
private:
    int M, N;
    list<Destination> destinations;

public:
    // Constructor
    ListMyJosephus(int m, int n);

    // Destructor
    ~ListMyJosephus();

    // Public Methods
    void clear();
    int currentSize() const;
    bool isEmpty() const;
    void eliminateDestination();
    void printAllDestinations() const;
};

#endif //