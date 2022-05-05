#ifndef ingame_H
#define ingame_H


extern int rounds;
extern std::string* question;
extern std::string* answer;

void initialize_question();
void initialize_answer();
void save();
void user_status();
void monster_status();
void reset_status();
int random_num();
void attack();
void shop();
void die();
void win();
void victory();
void options();
void battle();

#endif