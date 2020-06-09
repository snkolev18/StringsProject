#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "structures.h"

using namespace std;

void welcome() {
	cout << R"(                                                
    | |   (_)   | |   | |            | |                 
    | |__  _  __| | __| | ___ _ __   | |_ ___  __ _ _ __ 
    | '_ \| |/ _` |/ _` |/ _ \ '_ \  | __/ _ \/ _` | '__|
    | | | | | (_| | (_| |  __/ | | | | ||  __/ (_| | |   
    |_| |_|_|\__,_|\__,_|\___|_| |_|  \__\___|\__,_|_|   )" << endl;
}

int randomIndexWord() {
	int randomInd = 0;
	randomInd = rand() % 10;
	return randomInd;
}

void guessTheWord() {
	string userInput;
	GAME gameParts;
	int index;
	bool checker = true;
	index = randomIndexWord();
	int tries = 3;
	cout << "\nHint: " << gameParts.hints[index] << "\nIt contains " << gameParts.wordlist[index].length() << " letters";
	cout << endl;
	for (size_t j = 0; j < gameParts.wordlist[index].length(); j++) {
		cout << "_";
	}
	cout << endl;
	do {
		cin >> userInput;
		if (userInput == gameParts.wordlist[index]) {
			cout << "Congrats you guessed the word" << endl;
			checker = true;
		}
		else {
			tries -= 1;
			if (tries == 1)
			{
				cout << "You have " << tries << " try left" << endl;
			}
			else
			{
				cout << "You have " << tries << " tries left" << endl;
			}
			cout << "Your input doesn't match the given word. Try again!!!" << endl;
			checker = false;
		}
		if (tries == 0) {
			cout << "You get 0 score from this word" << endl;
			checker = true;
		}
	} while (checker == false);
}
bool menu() {
	int option;
	welcome();
	cout << "------" << endl;
	cout << "1.   Play guess the word" << endl;
	cout << "2.   Show results" << endl;
	cout << "3.   Continue playing" << endl;
	cout << "4.   Stop playing" << endl;
	cout << "------" << endl;
	cout << "Choose your option: ";
	while (!(cin >> option)) {
		cout << "Incorrect input. ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Try again: ";
	}
	switch (option)
	{
	case 1:
		guessTheWord();
		return true;
		break;
	case 2:

		return true;
		break;
	case 3:

		return true;
		break;
	case 4:

		return false;
		break;
	}
}