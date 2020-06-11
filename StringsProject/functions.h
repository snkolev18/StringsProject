#pragma once
#include <fstream>
#include <string>
#include "structures.h"

															//////////////////////////////////////////
											////////////////////////******DATA LAYER******////////////////////////
															//////////////////////////////////////////

void readQuestions(GAME& quiz, int& count);

void readAccounts(int& count, USER* users);

int randomInt(int min, int max);

bool checkPassword(string password);

int randomIndexWord(int numberOfQuestions);

void deleteAQuestion(GAME& quiz, int index, int numberOfQuestions);

bool grantAccess(string username, string password, int count, USER* users);

int findUserByUsername(string username, int count, USER* users);

															//////////////////////////////////////////
											////////////////////////******PRESENTATION LAYER******////////////////////////
															//////////////////////////////////////////
void welcome();

void results();

void guessTheWord(USER* users, int user);

void registration(USER* users, int& count);

bool userMenu(int count, USER* users, int user);

void addWordsAndHints();

void showWordsAndHints();

void seeAllUsers(USER* users);

bool adminMenu(int count, USER* users, int user);

void login(int count, USER* users);

bool registrationMenu(int& count, USER* users); //The menu that goes right after the startup text