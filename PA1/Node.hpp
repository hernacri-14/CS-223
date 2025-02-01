#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Command.hpp"

class Node{
public:
    Node(Command newCommand): command(newCommand), next(nullptr), prev(nullptr){}

    Command getCommand();
    void setCommand(Command newCommand);
    Node* getNext();
    Node* getPrev();
    void setPrev(Node* prev);
    void setNext(Node* next);
private:
Node* next, *prev;
Command command;

};