#pragma once
#include <fstream>
#include <string>
#include "structures.h"


//==================================================================\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==================================================================//


void readQuestions(GAME& quiz, int& countQuestions); //Stores the words with their definitions in a structure

void readAccounts(int& countUsers, USER* users); //Stores the accounts in a structure

void asteriskInput(string& password); //Displays the user passowrd with *

int randomInt(int min, int max); //Returns a random number in the closed interval of the given numbers

int randomIndexWord(int lastIndexOfQuestions); //Returns a random index in the closed interval of 0 and the number of questions which are not used

bool checkUsername(string username); //Checks if the username contains enough symbols

bool checkPassword(string password); //Checks if the password passes all the requirements

bool grantAccess(string username, string password, int count, USER* users); //Checks for user with the given username and password

int findUserByUsername(string username, int count, USER* users); //Returns the index of a user with the given username

void deleteAQuestion(GAME& quiz, int index, int countQuestions); //Deletes the question with the given index


//==========================================================================\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==========================================================================//


void welcome(); //Header

void lineDesignUp(); //Line for the design 

void lineDesignDown(); //Line for the design

void registration(USER* users, int& countUsers); //Registers a user

void showScore(USER* users, int loggedUser); //Shows the score of the user

void guessTheWord(USER* users, int loggedUser); //Runs a game called "Guess the word"

bool userMenu(int count, USER* users, int loggedUser); //Gives the user a menu

void addWordsAndDefinitions(); //Adds a new word with its definition

void showWordsAndDefinitions(); //Prints out all the words with their definitions which are in the text file

void showAllUsers(); //Prints out all the usernames which are in the text file

bool adminMenu(USER* users); //Gives the admin a menu

void login(int countUsers, USER* users); //Shows a menu depending on the credentials

bool menu(int& countUsers, USER* users); //The menu that asks you if you want to register, login or exit