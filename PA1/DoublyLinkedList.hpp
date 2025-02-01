#include "Node.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



class DoublyLinkedList{
public:
DoublyLinkedList(){ Head = nullptr;
Tail = nullptr; size = 30;}
Node* createNode(Command newCommand);
bool insertFront(Command newCommand);
bool deleteNode(string name);
void printList();

Node* getHead();
Node* getTail();
void setHead(Node* newHead);
void setTail(Node* newTail);

void setSize();
int getSize();

private:
Node* Head, *Tail;
int size;

};