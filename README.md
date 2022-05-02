# COMP2113 Group Project Group 122
# Spinx Game

__Group Number: 122__ <br/>
__Group Member: <br/>
Li Ka Lam (Andy) (3035767499) <br/>
Havin Chung (3035729772)__

## Game rules:
__Login required and choices are given:__
1) Start new game
2) Load game
3) Leaderboard

> "You need to defeat the Boss monster by answering the questions."

__Boss have 25 HP and every time you answer correctly:__ <br/>
- HP: -5 & Score: +100 points

__Each boss would give you 5 questions based on specific field of study__
1) Math
2) Comp
3) History
4) Physics

__4 Rounds in total:__

Round 1 -> Town -> Round 2 -> Town -> Round 3 -> Town -> Round 4

__HP system:__
- Start with 20 HP
- Wrong answer or Exceed time limits deduct 5 HP (Score: -20 points)
- If HP get to 0 start from town and redo the round you failed

__Items:__
1) Skip question (replace one with another question)
2) Healing potion (Heal 5 HP)

__Every round you have two choices: (need to be done in 1.5 mins)__
1) Answer questions
2) Use item

__Town:__
1) Heal to 20 HP for Free
2) Buy item
3) Save progress

__Rewards:__
1) Well done trophy
2) Score

## File Content:
- cpp file for main menu and main game
- cpp file in game (fight, town, HP system)
- cpp file for pregame (Load, Save, Continue, Leaderboard)
- txt files save the progress (name, score, round, personal info)
- make file
- header file

## Code Requirement:
1) Random generation: choosing random questions from 40 questions per round
2) Gaming status: save progress in txt file use <fstream>
3) The score and and will be stored in user_status.txt
4) Save to txt file, the progress round, no. of items in text, score
5) Three C++ programs, four txt files, one header file and one make file

## Files:

introduction.txt

monster.txt
  
user_status.txt

inGame.cpp, inGame.h

main.cpp

preGame.cpp, preGame.h

Makefile
  
## Functions:

inGame.cpp
- void save_quit
- void questions (read from txt file)
- bool fight (whether answered correct or not)
- void display_status (display hp, items, and coins)
- void shop (display coins, items, price of items, hp, go to next round)
- void useItem
- bool win (if counter == 4, game win)
- bool die (if hp == 0, return shop)
  
preGame.cpp
- void write_file
- void read_file (read status of user)
- void begin (Introduction and Ask user to continue from previous or not)
- struct Status initialize_user (HP, items, coins)
- struct Status initialize_monster (HP)
- void exit
