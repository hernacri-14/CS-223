#include "Node.hpp"

Command Node::getCommand()
{
    return command;
}

void Node::setCommand(Command newCommand)
{
    command = newCommand;
}

Node *Node::getNext()
{
    return next;
}

Node *Node::getPrev()
{
    return prev;
}

void Node::setPrev(Node *newPrev)
{
    prev = newPrev;
}

void Node::setNext(Node *newNext)
{
    next = newNext;
}
