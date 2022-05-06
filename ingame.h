#ifndef ingame_H
#define ingame_H


extern int rounds;


void initialize_question();
void initialize_answer();
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

#endif