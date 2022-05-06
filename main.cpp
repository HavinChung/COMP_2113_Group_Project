#include <iostream>
#include <string>
#include <fstream>
#include "pregame.h"
#include "ingame.h"

using namespace std;

int main(){
    
    ifstream monster_file ("monster.txt");

    if (monster_file.is_open()){
        string line1;
        while (getline(monster_file, line1)){
            cout << line1 << endl;
        }
    }
    
    ifstream story_file ("story.txt");

    if (story_file.is_open()){
        string line2;
        while (getline(story_file, line2)){
            cout << line2 << endl;
        }
    }


    cout << "Welcome to the spinx game" << endl;
    cout << "Introduction:" << endl;
    cout << "You need to kill the Sphinx by solving question!!" << endl;
    cout << "All answers need to be strictly in CAPTIAL LETTERS!!" << endl;
    cout << endl;
    cout << "what would you like to do?" << endl;
    cout << "1. Start a new game!"<< endl;
    cout << "2. Load Game"<< endl;
    cout << "3. Exit the game."<< endl;
    cout << "Please enter you choice.(1/2/3) "<< endl;
    cout << "Choice: ";
    char choice;
    cin >> choice;
    cout << endl;



    while(choice != '1' && choice != '2' && choice != '3'){
        cout << "Invalid input! please indicate your choice again!" << endl;
        cout << "Choice: ";
        cin >> choice;
    }
    if (choice == '1'){
        begin_new_game();
    }
    else if(choice == '2'){
        continue_game();
    }
    else if(choice == '3'){
        exit_1();
    }

    return 0;
}