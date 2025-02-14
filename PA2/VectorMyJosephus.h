#ifndef VECTORMYJOSEPHUS_H
#define VECTORMYJOSEPHUS_H

#include <iostream>
#include <vector>
#include "Destination.h"

class VectorMyJosephus {
private:
    int M, N;
    vector<Destination> destinations;

public:
    // Constructor
    VectorMyJosephus(int m, int n);

    // Destructor
    ~VectorMyJosephus();

    // Public Methods
    void clear();
    int currentSize() const;
    bool isEmpty() const;
    void eliminateDestination();
    void printAllDestinations() const;
};

#endif 