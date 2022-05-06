#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include "pregame.h"

using namespace std;

int rounds = 0;

void save();
void user_status();
void monster_status();
void reset_status();
void attack();
void shop();
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
    cout << endl;
    cout << "HP: " << hp << endl;
    cout << "Potions: " << num_of_potion << endl;
    cout << "Coins: " << num_of_coins << endl;
    cout << "Round: " << rounds+1 << endl;
    cout << endl;
}

void monster_status(){
    cout << endl;
    cout << "Monster HP: " << monster_hp <<endl;
    if (monster_hp == 100){
        cout << "[oooo|oooo|oooo|oooo]" << endl;
    } 
    if (monster_hp == 75){
        cout << "[oooo|oooo|oooo|----]" << endl;
    }
    if (monster_hp == 50){
        cout << "[oooo|oooo|----|----]" << endl;
    }
    if (monster_hp == 25){
        cout << "[oooo|----|----|----]" << endl;
    }
    if (monster_hp == 0){
        cout << "[----|----|----|----]" << endl;
        cout << "Sphinx: You....Killed....Me" << endl;
    }  
    cout << endl;
}

void reset_status(){
    hp = 20;
    monster_hp = 100;
}

void attack(){
    int MIN = 1;
    int MAX = 50;
    srand(time(NULL));
    int num = rand() % MAX;
    string user_input;

    while (question[num] == " "){
        int num = rand() % MAX;
    }

    if (question[num] != " "){
        cout << question[num] << endl;
        cout << "Answer: " << endl;
        cin >> user_input;

        if (user_input == "Skip"){
            cout << endl;
            attack();
        }

        else if (user_input == answer[num]){
            question[num] = " ";
            answer[num] = " ";
            cout << "Correct!" << endl;
            cout << "Attack the monster!! (-25)" << endl;
            monster_hp -= 25;
            cout << endl;
        }

        else if (user_input != answer[num]){
            cout << "Wrong Answer!" << endl;
            cout << "Monster have attacked you!! (-5)" << endl;
            hp -= 5;
            cout << endl;
        }


    }


}

void shop(){
    string option;

    reset_status();
    cout << endl;
    cout << "Hello Adventurer! Welcome to the town!" << endl;
    cout << "Please choose from options below: (Enter a Number)" << endl;
    cout << "| 1. Start Adventure          |" << endl;
    cout << "| 2. Buy Potion (1 coin)      |" << endl;
    cout << "| 3. Save and Exit            |" << endl;
    cout << endl;

    cin >> option;

    if (option == "1"){
        battle();
    }

    if (option == "2"){
        if (num_of_coins == 0){
            cout << "Not Enough Coin!!" << endl;
            shop();
        }
        if (num_of_coins > 0){
            cout << "Purchase Successful" << endl;
            num_of_coins -= 1;
            num_of_potion += 1;
            cout << "Number of Potions: " << num_of_potion << endl;
            shop();
        }
    }

    if (option == "3"){
        exit_1();
    }

    if(option != "1" && option != "2" && option != "3"){
        cout << "Invalid Choice" << endl;
        shop();
    }

}

void use_potion(){
    if (num_of_potion > 0){
        cout << "Healed 5 hp" << endl;
        hp += 5;
        num_of_potion--;
    }

    if (num_of_potion == 0){
        cout << "Not enough potion!!" << endl;
    }
}

void die(){
    cout << endl;
    cout << "The player have slained by the monster!" << endl;
    cout << "Returning to the town..." << endl;
    cout << endl;
    shop();
}

void win(){
    cout << endl;
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
    if (rounds < 5){
        cout << "You have encountered the Sphinx" << endl;
        while (hp != 0 && monster_hp != 0){
            cout << endl;
            cout << "Please choose from options below: (Enter a Number)" << endl;
            cout << "| 1. Attack                   |" << endl;
            cout << "| 2. Use Potion               |" << endl;
            cout << "| 3. Save and Exit            |" << endl;
            cout << endl;
            string input;
            cin >> input;

            if (input == "1"){
                cout << "Please enter 'Skip' if you want to skip the question!" << endl;
                attack();
            }

            if (input == "2"){
                use_potion();
            }

            if (input == "3"){
                exit_1();
                break;
            }
        }

        if (hp == 0){
            die();
        }

        if (monster_hp == 0){
            win();
            rounds++;
        }
    }
}