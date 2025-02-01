#include <iostream>
#include <string>
#include <forward_list>
#include <iterator> 

using namespace std;

 class Command {
    public:
    string name;
    string description;
    int points;
    Command(string n, string d, int p) : name(n), description(d), points(p) {}
};