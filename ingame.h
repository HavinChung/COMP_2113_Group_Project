#ifndef ingame_H
#define ingame_H


extern int rounds;
extern int* question_no;
extern int counter;

std::string read_file(std::string textfile,int rand);
void save();
void user_status();
void monster_status();
void reset_status();
int random_num();
bool attack();
void shop();
void die();
void win();
void victory();
void battle();

#endif