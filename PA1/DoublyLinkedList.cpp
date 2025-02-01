#include "DoublyLinkedList.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>



   Node *DoublyLinkedList::createNode(Command newCommand) {
        //printf("hola 112\n");
        Node* newNode = new Node(newCommand);
        if (!newNode) {
            cerr << "Memory allocation failed" << endl;
             return nullptr;
        }
        // Initialize next and prev pointers
        newNode->setNext(nullptr);
        newNode->setPrev(nullptr);
        //printf("hola 110\n");
        return newNode;
    }

    // Function to insert a new record at the front of the list
    bool DoublyLinkedList::insertFront(Command newCommand) {
        Node* newNode = createNode(newCommand);
        if (!newNode) {
            return false; // Indicate failure
        }

        // Insert the new node at the front of the list
        newNode->setNext(this->Head);
        newNode->setPrev(nullptr);

        if (this->Head != nullptr) {
            this->Head->setPrev(newNode);
        }
        else {
            // If the list was empty, the new node is also the tail
            this->Tail = newNode;
        }

        this->Head = newNode;
        //printList(list);

        return true; // Indicate success
    }

    bool DoublyLinkedList::deleteNode(string name)
    {
        
        Node* temp = this->Head;
       while (temp != nullptr) {
        if (temp->getCommand().name == name) {
            // If the node to be deleted is the head
            if (temp == this->Head) {
                this->Head = temp->getNext();
                if (this->Head) {
                    this->Head->setPrev(nullptr);
                } else {
                    this->Tail = nullptr; // If the list is now empty
                }
            }
            // If the node to be deleted is the tail
            else if (temp == this->Tail) {
                this->Tail = temp->getPrev();
                if (this->Tail) {
                    this->Tail->setNext(nullptr);
                } else {
                    this->Head = nullptr; // If the list is now empty
                }
            }
            // If the node is in the middle
            else {
                temp->getPrev()->setNext(temp->getNext());
                temp->getNext()->setPrev(temp->getPrev());
            }

            delete temp; // Free memory
            return true;
            }else{
            temp = temp->getNext();
            }
        }
        return false;
    }

    void DoublyLinkedList::printList()
    {
        Node* temp = this->Head;
        while (temp != NULL) {
            cout << "Command: " << temp->getCommand().name << ", Description: " 
            << temp->getCommand().description << endl;
            temp = temp->getNext();
        }
    }

    Node *DoublyLinkedList::getHead()
    {
        return Head;
    }

    Node *DoublyLinkedList::getTail()
    {
        return Tail;
    }

    void DoublyLinkedList::setHead(Node *newHead)
    {
        Head = newHead;
    }

    void DoublyLinkedList::setTail(Node *newTail)
    {
        Tail = newTail;
    }

    void DoublyLinkedList::setSize()
    {
        size++;
    }

    int DoublyLinkedList::getSize()
    {
        return size;
    }
