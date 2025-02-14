#include "VectorMyJosephus.h"

int main() {
    VectorMyJosephus game(3, 10);
    game.printAllDestinations();
    game.eliminateDestination();
    game.printAllDestinations();
    return 0;
}