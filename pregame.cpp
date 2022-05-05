#include <iostream>
#include <string>
#include <fstream>
#include "ingame.h"

using namespace std;

int hp = 20;
int num_of_coins = 0;
int num_of_potion = 0;
int monster_hp = 100;

void begin_new_game(){
    ofstream fout;
    fout.open("user_status.txt");
    fout << hp << " " << num_of_coins << ' ' << num_of_potion << ' ' << monster_hp << ' ' << rounds; 
    fout.close();
    ifstream fin;
    fin.open("user_status.txt");
    fin >> hp >> num_of_coins >> num_of_potion >> monster_hp >> rounds;
    fin.close();
    cout << "Your HP: " << hp << endl;
    cout << "Your number of coins: " <<num_of_coins << endl;
    cout << "Your number of potion: "<< num_of_potion << endl;
    cout << "Monster HP: " << monster_hp << endl;
    cout << "Round: " << rounds + 1 << endl;

    shop();
}

void continue_game(){
    int hp, num_of_coins,num_of_potion,monster_hp,rounds;
    ifstream fin;
    fin.open("user_status.txt");
    fin >> hp >> num_of_coins >> num_of_potion >> monster_hp >> rounds;
    fin.close();
    cout << "Your HP: " << hp << endl;
    cout << "Your number of coins: " <<num_of_coins << endl;
    cout << "Your number of potion: "<< num_of_potion << endl;
    cout << "Monster HP: " << monster_hp << endl;
    cout << "Round: " << rounds + 1 << endl;

    shop();
}
void exit_1(){
    cout << "Your status has been saved, see you next time!!!";
    ofstream fout;
    fout.open("user_status.txt");
    fout << hp << " " << num_of_coins << ' ' << num_of_potion << ' ' << monster_hp << ' ' << rounds; 
    fout.close();
}

