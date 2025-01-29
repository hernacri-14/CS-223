#include <iostream>
#include <string>
#include <forward_list>
#include <iterator> 

using namespace std;

int main(){
    int input;
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
            cout << "Correct answer: +1 point.\nIncorrect answer: -1 live\n"; 
            cout <<"There is no fixed score to win the goal is to get the highest score possible.\n";
            cout <<"If the player reaches 0 lives, the game ends.\nScores persist across sessions.\n\n";
            break;
         case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
         case 7:
            //save and exit
            cout << "save succesfully, goodbye";
            return 0;
        default:
            break;
        }
    }
    return 0;
};