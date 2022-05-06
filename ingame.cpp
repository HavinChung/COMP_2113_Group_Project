#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include "pregame.h"

using namespace std;

const int MAX = 50;

int rounds = 0;

void save();
void user_status();
void monster_status();
void remove_question(int num);
void attack();
void shop();
void buy_potion();
void use_potion();
void die();
void win();
void victory();
void battle();


void save(){
    ofstream file("user_status.txt");

    if (file.is_open()){
        file << hp << " " << num_of_coins << " " << num_of_potion << " " << monster_hp;
    }

    file.close();
}

void user_status(){
    cout << "HP: " << hp << endl;
    cout << "Potions: " << num_of_potion << endl;
    cout << "Coins: " << num_of_coins << endl;
    cout << "Round: " << rounds+1 << endl;
    cout << endl;
}

void monster_status(){
    cout << "Monster HP: " << monster_hp <<endl;
    cout << endl;
    if (monster_hp == 100){
        cout << "[oooo|oooo|oooo|oooo]" << endl;
    } 
    else if (monster_hp == 75){
        cout << "[oooo|oooo|oooo|----]" << endl;
    }
    else if (monster_hp == 50){
        cout << "[oooo|oooo|----|----]" << endl;
    }
    else if (monster_hp == 25){
        cout << "[oooo|----|----|----]" << endl;
    }
    else if (monster_hp == 0){
        cout << "[----|----|----|----]" << endl;
        cout << endl;
        cout << "Sphinx: You....Killed....Me" << endl;
    }  
    cout << endl;
}

void remove_question(int num){
    question[num] = "NULL";
    answer[num] = "NULL";
}

void attack(){

    srand(time(NULL));
    int num = rand() % MAX;
    string user_input;

    while (question[num] == "NULL"){
        int num = rand() % MAX;
    }

    if (question[num] != "NULL"){
        cout << question[num] << endl;
        cout << "Answer: " << endl;
        getline(cin, user_input);
        cout << endl;

        if (user_input == answer[num]){
            cout << "Correct!" << endl;
            cout << "Attack the monster!! (-25)" << endl;
            monster_hp -= 25;
            monster_status();
            cout << endl;
            remove_question(num);
        }

        else if (user_input != answer[num]){
            cout << "Wrong Answer!" << endl;
            cout << "The answer was " << answer[num] << endl;
            cout << "Monster have attacked you!! (-5)" << endl;
            hp -= 5;
            user_status();
            cout << endl;
        }


    }


}

void shop(){
    if (monster_hp == 0){
        monster_hp = 100;
    }

    if (hp == 0){
        hp = 20;
    }

    char choice;
    cout << "Hello Adventurer! Welcome to the town!" << endl;
    cout << "USER STATUS:" << endl;
    user_status();
    cout << "Please choose from options below: (Enter a Number)" << endl;
    cout << "| 1. Start Adventure          |" << endl;
    cout << "| 2. Buy Potion (1 coin)      |" << endl;
    cout << "| 3. Save and Exit            |" << endl;
    cout << "Choice: ";
    cin >> choice;

    cout << endl;

    while(choice != '1' && choice != '2' && choice != '3'){
        cout << "Invalid input! please indicate your choice again!" << endl;
        cin >> choice;
    }

    if (choice == '1'){
        battle();
    }

    else if (choice == '2'){
        buy_potion();
    }

    else if (choice == '3'){
        exit_1();
    }

}

void buy_potion(){
    if (num_of_coins == 0){
        cout << "Not Enough Coin!!" << endl;
        shop();
    }

    else if (num_of_coins > 0){
        cout << "Purchase Successful" << endl;
        num_of_coins -= 1;
        num_of_potion += 1;
        cout << "Number of Potions: " << num_of_potion << endl;
        shop();
    }
}

void use_potion(){
    if (num_of_potion > 0){
        cout << "Healed 5 hp" << endl;
        hp += 5;
        num_of_potion--;
    }

    else if (num_of_potion == 0){
        cout << "Not enough potion!!" << endl;
    }
}

void die(){
    cout << "The player have slained by the monster!" << endl;
    cout << "Returning to the town..." << endl;
    cout << endl;
    shop();
}

void win(){
    cout << "Conguratulation! You have slained the monster!" << endl;
    cout << "Returning to the town..." << endl;
    cout << endl;
    num_of_coins += 1;
    rounds += 1;

    if (rounds == 5){
        victory();
    }

    else{
        shop();
    }

}

void victory(){
    cout << "VICTORY!!!" << endl;
}


void battle(){
    char input;
    cout << "You have encountered the Sphinx" << endl;

    while (hp != 0 && monster_hp != 0){
        cout << "Please choose from options below: (Enter a Number)" << endl;
        cout << "| 1. Attack                   |" << endl;
        cout << "| 2. Use Potion               |" << endl;
        cout << "| 3. Save and Exit            |" << endl;
        cout << "Choice: ";
        cin >> input;
        cout << endl;

        while(input != '1' && input != '2' && input != '3'){
            cout << "Invalid input! please indicate your choice again!" << endl;
            cout << "Choice: ";
            cin >> input;
            cout << endl;
        }

        if (input == '1'){
            attack();
        }

        else if (input == '2'){
            use_potion();
        }

        else if (input == '3'){
            break;
        }
    }

    if (hp == 0){
        die();
    }

    else if (monster_hp == 0){
        win();
        rounds++;
    }

    else if (input == '3'){
        exit_1();
    }
}