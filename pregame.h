#ifndef pregame_H
#define pregame_H

#include <string>


extern int hp;
extern int num_of_coins;
extern int num_of_potion;
extern int monster_hp;
extern std::string* question;
extern std::string* answer;

void begin_new_game();
void continue_game();
void exit_1();

#endif