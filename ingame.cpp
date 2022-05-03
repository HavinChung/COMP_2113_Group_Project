#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include "ingame.h"

using namespace std;

int round = 0;
int hp = 20;
int num_of_coins = 0;
int num_of_magic_power = 0;
int num_of_potion = 0;
int monster_hp = 100;
int* question_no = new int[50];
int counter = 0;

string read_file(string textfile,int rand){
    ifstream file (textfile);
    string line;

    if (file.is_open()){
        for (int i = 1; getline(file, line) && i < rand+1; i++){
            if (i == rand){
                break;
            }
        }
    }

    file.close();
    return line;
}

void save(){
    ofstream file("user_status.txt");

    if (file.is_open()){
        file << hp << " " << num_of_coins << " " << num_of_magic_power << " " << num_of_potion << " " << monster_hp;
    }

    file.close();
}

void user_status(){
    cout << "HP: " << hp << endl;
    cout << "Potions: " << num_of_potion << endl;
    cout << "Coins: " << num_of_coins << endl;
}

void monster_status(){
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
}

void reset_status(){
    hp = 20;
    monster_hp = 100;
}

int random_num(){
    int MIN = 1;
    int MAX = 50;
    srand(time(NULL));

    int num = rand() % MAX;

    return num;
}

bool attack(){
    string user_input;
    int num = random_num();
    bool found;
    
    do{
        for(int i = 0; i < counter; i++){
            if (question_no[i] == num){
                found == true;
            }
        }
        num = random_num();

    } while (found != false);

    string question = read_file("Question.txt", num);
    string answer = read_file("Answer.txt", num);

    cout << question << endl;
    cin >> user_input;


    if (user_input == answer){
        question_no[counter] = num;
        counter++;
        return true;
    }

    else{
        return false;
    }
}

void shop(){
    string option;

    reset_status();
    cout << "Hello Adventurer! Welcome to the town!" << endl;
    cout << "Please choose from options below: (Enter a Number)" << endl;
    cout << "| 1. Go to Next Round         |" << endl;
    cout << "| 2. Buy Potion (1 coin)      |" << endl;
    cout << "| 3. Buy Magic Power (1 coin) |" << endl;
    cout << "| 4. Save Game                |" << endl;

    cin >> option;

    if (option == "1"){
        battle();
    }

    if (option == "2"){
        if (coin == 0){
            cout << "Not Enough Coin!!" << endl;
            shop();
        }
        if (coin > 0){
            cout << "Purchase Successful" << endl;
            num_of_coins -= 1;
            num_of_potion += 1;
            cout << "Number of Potions: " << num_of_potion << endl;
            shop();
        }
    }
    
    if (option == "3"){
        if (coin == 0){
            cout << "Not Enough Coin!!" << endl;
            shop();
        }
        if (coin > 0){
            cout << "Purchase Successful" << endl;
            num_of_coins -= 1;
            num_of_magic_power += 1;
            cout << "Number of Magic Power: " << num_of_magic_power << endl;
            shop();
        }
    }

    if (option == "4"){
        save();
        shop();
    }

}

void die(){
    cout << "The player have slained by the monster!" << endl;
    cout << "Returning to the town..." << endl;
    shop();
}

void win(){
    cout << "Conguratulation! You have slained the monster!" << endl;
    cout << "Returning to the town..." << endl;
    num_of_coins += 1;
    round += 1;
    shop();

}

void victory(){
    cout << "VICTORY!!!" << endl;
}

void battle(){
    if (round < 5){
        while (hp != 0 && monster_hp != 0){
            if (attack() == true){
                cout << "Attack was Successful!" << endl;
                monster_hp -= 25;
            }
            if (attack() == false){
                cout << "Monster attacked you! (x_x)" << endl;
                hp -= 5;
            }

            user_status();
            monster_status();
        }

        if (hp == 0){
            die();
        }

        if (monster_hp == 0){
            win();
            round++;
        }
    }

    if (round == 5){
        victory();
    }
}