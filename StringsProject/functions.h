#pragma once
#include <fstream>
#include <string>
#include "structures.h"

void welcome();
int randomInt(int min, int max);
int randomIndexWord(int numberOfQuestions);
void deleteAQuestion(GAME& quiz, int index);
void guessTheWord();
void results();
int findUserByUsername(string username, int count, USER* users);
void registration(USER* users, int& count);
void login(int count, USER* users);
bool checkPassword(string password);
bool grantAccess(string username, string password, int count, USER* users);
bool registrationMenu(int& count, USER* users);
bool userMenu(int count, USER* users, int user);
void readAccounts(int& count, USER* users);