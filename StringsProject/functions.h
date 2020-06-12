#pragma once
#include <fstream>
#include <string>
#include "structures.h"

//==================================================================\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==================================================================//

void readQuestions(GAME& quiz, int& count);

void readAccounts(int& count, USER* users);

void asteriskInput(string& password);

int randomInt(int min, int max);

int randomIndexWord(int numberOfQuestions);

bool checkPassword(string password);

bool grantAccess(string username, string password, int count, USER* users);

int findUserByUsername(string username, int count, USER* users);

void deleteAQuestion(GAME& quiz, int index, int numberOfQuestions);

//==========================================================================\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==========================================================================//

void welcome();

void lineDesignUp();

void lineDesignDown();

void registration(USER* users, int& count);

void results(USER* users, int user);

void guessTheWord(USER* users, int user);

bool userMenu(int count, USER* users, int indexOfTheUser);

void addWordsAndHints();

void showWordsAndHints();

void seeAllUsers(USER* users);

bool adminMenu(int count, USER* users, int user);

void login(int count, USER* users);

bool registrationMenu(int& count, USER* users);