#include "ListMyJosephus.h"

int main() {
    ListMyJosephus game(3, 10);
    game.printAllDestinations();
    game.eliminateDestination();
    game.printAllDestinations();
    return 0;
}