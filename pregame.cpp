#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int hp = 20;
int num_of_coins = 0;
int num_of_magic_power = 0;
int num_of_potion = 0;
int monster_hp = 100;

void begin_new_game(){
    ofstream fout;
    fout.open("user_status.txt");
    fout << hp << " " << num_of_coins << ' ' << num_of_magic_power << ' ' << num_of_potion << ' ' << monster_hp; 
    fout.close();
    ifstream fin;
    fin.open("user_status.txt");
    fin >> hp >> num_of_coins >> num_of_magic_power >> num_of_potion >> monster_hp;
    fin.close();
    cout << "Your HP: " << hp << endl;
    cout << "Your number of coins: " <<num_of_coins << endl;
    cout << "Your number of magic power: " << num_of_magic_power << endl;
    cout << "Your number of potion: "<< num_of_potion << endl;
    cout << "Monster HP: " << monster_hp << endl;
}

void continue_game(){
    int hp, num_of_coins,num_of_magic_power,num_of_potion,monster_hp;
    ifstream fin;
    fin.open("user_status.txt");
    fin >> hp >> num_of_coins >> num_of_magic_power >> num_of_potion >>monster_hp;
    fin.close();
    cout << "Your HP: " << hp << endl;
    cout << "Your number of coins: " <<num_of_coins << endl;
    cout << "Your number of magic power: " << num_of_magic_power << endl;
    cout << "Your number of potion: "<< num_of_potion << endl;
    cout << "Monster HP: " << monster_hp << endl;
}
void exit_1(){
    cout << "Your status has been saved, see you next time!!!";
    ifstream fin;
    fin.open("user_status.txt");
    fin >> hp >> num_of_coins  >> num_of_magic_power  >> num_of_potion  >> monster_hp; 
    fin.close();
}




int main(){
    cout << "Welcome to the spinx game" << endl;
    cout << "what would you like to do?" << endl;
    cout << "1. Start a new game!"<< endl;
    cout << "2. Purchase some items!"<< endl;
    cout << "3. To exit the game."<< endl;
    cout << "Please enter you choice.(1/2/3) "<< endl;
char choice;
cin >> choice;
while(choice != '1' && choice != '2' && choice != '3'){
  cout << "Invalid input! please indicate your choice again!" << endl;
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
