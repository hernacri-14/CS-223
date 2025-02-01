#include <iostream>
#include <unordered_set>
#include <string>
#include <forward_list>
#include <iterator> 
#include "DoublyLinkedList.cpp"
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void loadCommands(DoublyLinkedList& commands) {
    ifstream file("commands.csv");
    if (!file) {
        cerr << "Error: Could not open commands.csv" << endl;
        return;
    }

    string name, description, pointsStr;
    int points;

    while (getline(file, name, ',') && getline(file, description, ',') && getline(file, pointsStr)) {
        // Remove surrounding quotes from description if they exist
        if (!description.empty() && description.front() == '"' && description.back() == '"') {
            description = description.substr(1, description.size() - 2);
        }

        points = stoi(pointsStr); // Convert points to an integer

        Command newCommand(name, description, points);
        commands.insertFront(newCommand);
    }

    file.close();
}

void loadGame(DoublyLinkedList& commands, int& pointsTotal, int& lives) {
    ifstream file("prevGame.csv");
    if (!file) {
        cerr << "Error: Could not open prevGame.csv" << endl;
        return;
    }

    string name, description, pointsStr;
    int points;
    

    while (getline(file, name, ',')) {
        if (name == "SAVED_GAME") {
            string type, valueStr;
            getline(file, type, ',');
            getline(file, valueStr);

            if (type == "POINTS") {
                pointsTotal = stoi(valueStr);
            } else if (type == "LIVES") {
                lives = stoi(valueStr);
            }
            continue; // Skip saving this as a command
        }

        if (getline(file, description, ',') && getline(file, pointsStr)) {
            points = stoi(pointsStr);
            Command newCommand(name, description, points);
            commands.insertFront(newCommand);
        }
    }

    file.close();
}

void saveCommands(DoublyLinkedList& commands, int pointsTotal, int lives) {
    ofstream outFile("prevGame.csv");

    if (!outFile) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    Node* temp = commands.getHead();
    while (temp != nullptr) {
        outFile << temp->getCommand().name << ","
                << temp->getCommand().description << ","
                << temp->getCommand().points << "\n";
        temp = temp->getNext();
    }

    // Save points and lives at the end of the file
    outFile << "SAVED_GAME,POINTS," << pointsTotal << "\n";
    outFile << "SAVED_GAME,LIVES," << lives << "\n";

    outFile.close();
}

void playGame(DoublyLinkedList* commands, int& pointsTotal, int& lives) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, commands->getSize()), dist2(1, 3);

    unordered_set<int> usedNumbers;
    string wrong1, wrong2, right;
    int correctNumber, answer, list = commands->getSize();

    if (lives == 0) {
        cout << "You have no lives left! Start a new game." << endl;
        return;
    }

    Node* temp = commands->getHead();
    Node* correct;

    while (true) {
        if (lives == 0) {
            cout << "Game over! You ran out of lives." << endl;
            break;
        }

        usedNumbers.clear(); // Reset for each round

        while (usedNumbers.size() < 3) {
            int number = dist(gen);
            if (usedNumbers.insert(number).second) {
                Node* selected = nullptr;

                if (number == 1) {
                    selected = commands->getHead();
                } else if (number == list) {
                    selected = commands->getTail();
                } else if (number < list / 2) {
                    selected = commands->getHead();
                    for (int j = 1; j < number && selected->getNext() != nullptr; j++) {
                        selected = selected->getNext();
                    }
                } else {
                    selected = commands->getTail();
                    for (int j = list; j > number && selected->getPrev() != nullptr; j--) {
                        selected = selected->getPrev();
                    }
                }

                if (usedNumbers.size() == 1) {
                    correct = selected;
                    right = correct->getCommand().description;
                } else if (usedNumbers.size() == 2) {
                    wrong1 = selected->getCommand().description;
                } else if (usedNumbers.size() == 3) {
                    wrong2 = selected->getCommand().description;
                }
            }
        }

        cout << "What does the command: " << correct->getCommand().name << " do?" << endl;
        vector<string> options = {right, wrong1, wrong2};
        shuffle(options.begin(), options.end(), gen);

        for (int x = 0; x < 3; x++) {
            cout << x + 1 << ". " << options[x] << endl;
            if (options[x] == right) {
                correctNumber = x + 1;
            }
        }

        cout << "Insert 4 to return to the menu" << endl;
        cin >> answer;

        if (answer == 4) {
            break;
        } else {
            if (answer == correctNumber) {
                pointsTotal += correct->getCommand().points;
                cout << "Correct! Points: " << pointsTotal << endl;
            } else {
                lives--;
                cout << "Incorrect! Lives left: " << lives << endl;
            }

            temp = temp->getNext();
            if (!temp) {
                temp = commands->getHead();
            }
        }
    }
}

void addCommand(DoublyLinkedList* commands){
    string name, description;
    int points;

    cout << "Name of the command: ";
    cin >> name;
    cin.ignore(); 

    cout << "Description of the command: ";
    getline(cin, description); 

    cout << "Point value: ";
    while (!(cin >> points)) { 
        cout << "Invalid input. Please enter a number: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    Command newCommand(name, description, points);
    commands->insertFront(newCommand);

    cout << "The Command was added succesfully" << endl;
}

void removeCommand(DoublyLinkedList* commands){
    string name;
    
    cout << "Name of the command: ";
    cin >> name;

    Node* temp = commands->getHead();

    while (temp != nullptr) {
        if (temp->getCommand().name == name) {
            // Case 1: If the node to be deleted is the head
            if (temp == commands->getHead()) {
                commands->setHead(temp->getNext());
                if (commands->getHead()) {
                    commands->getHead()->setPrev(nullptr);
                } else {
                    commands->setTail(nullptr); // If list is now empty
                }
            }
            // Case 2: If the node to be deleted is the tail
            else if (temp == commands->getTail()) {
                commands->setTail(temp->getPrev());
                if (commands->getTail()) {
                    commands->getTail()->setNext(nullptr);
                }
            }
            // Case 3: If the node is in the middle
            else {
                temp->getPrev()->setNext(temp->getNext());
                temp->getNext()->setPrev(temp->getPrev());
            }

            delete temp; // Free memory
            cout << "Command '" << name << "' removed successfully." << endl;
            return;
        }
        temp = temp->getNext();
    }


    cout << "Command '" << name << "' not found." << endl;

}
int main(){
    int input, pointsTotal = 0, lives = 3;;
    DoublyLinkedList commands;
    while (true){
        cout << "1: Game Rules\n2: Play New Game\n3: Load previous Game\n4: Add Command" <<
        "\n5: Remove Command\n6: Display All Commands\n7: Save and Exit" << endl;
        cout << "enter choice: ";

        cin >> input;
        switch (input)
        {
        case 1:
            cout << "Game Rules: \n";
            cout << "The game will present a Linux command and multiple possible descriptions.\n";
            cout << "The player must choose the correct description for the command.\n";
            cout << "The Player has 3 lives\n";
            cout << "Correct answer: +n point(depends on the question up to +4 points).\nIncorrect answer: -1 live\n"; 
            cout <<"There is no fixed score to win the goal is to get the highest score possible.\n";
            cout <<"If the player reaches 0 lives, the game ends.\nScores persist across sessions.\n\n";
            break;
         case 2:
            loadCommands(commands);
            playGame(&commands, pointsTotal, lives);
            break;
        case 3:
            loadGame(commands, pointsTotal, lives);
            playGame(&commands, pointsTotal, lives);
            break;
        case 4:
            addCommand(&commands);
            break;
        case 5:
            removeCommand(&commands);
            break;
        case 6:
            commands.printList();
            break;
         case 7:
            saveCommands(commands, pointsTotal, lives);
            cout << "save succesfully, goodbye";
            return 0;
        default:
            break;
        }
    }
    return 0;
};