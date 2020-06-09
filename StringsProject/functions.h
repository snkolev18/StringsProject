#pragma once
#include <fstream>
#include <string>
#include "structures.h"

void welcome();
int randomInt(int min, int max);
int randomIndexWord(int numberOfQuestions);
void deleteAQuestion(GAME& quiz, int index);
void guessTheWord(int& score);
void results(int score);
bool menu(int& score);