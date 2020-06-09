#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "structures.h"

using namespace std;

vector<string> Words = { "woman", "jump", "copper", "calendar", "boyfriend", "king", "album", "monkey", "objective", "laptop" };

void welcome() {
	cout << R"(                                                
    | |   (_)   | |   | |            | |                 
    | |__  _  __| | __| | ___ _ __   | |_ ___  __ _ _ __ 
    | '_ \| |/ _` |/ _` |/ _ \ '_ \  | __/ _ \/ _` | '__|
    | | | | | (_| | (_| |  __/ | | | | ||  __/ (_| | |   
    |_| |_|_|\__,_|\__,_|\___|_| |_|  \__\___|\__,_|_|   )" << endl;
}

int randomIndexWord() {
	srand(time(NULL));
	int randomInd = rand();
	randomInd = rand() % 10 + 1;
	return randomInd;
}

GAME getRandomWord(int& index) {
	GAME game;
	game.wordlist[index];
	game.hints[index];
	return game;
}


void guessTheWord(int& index) {
	string word, hint, userInput;
	GAME gameParts;
	int tries = 3;
	bool checker = true;
	word = gameParts.wordlist[index];
	hint = gameParts.hints[index];
	cout << "Hint: " << hint << "It contains " << word.length() << " letters";
	cout << endl;
	for (size_t i = 0; i < word.length(); i++){
		cout << "_";
	}
	do{
		cin >> userInput;
		if (userInput.compare(word) == 0) {
			cout << "Congrats you guessed the word" << endl;
			checker = true;
		}
		else {
			cout << "Your input doesn't match the given word. Try again!!!" << endl;
			tries -= 1;
			checker = false;
		}
		if (tries == 0) {
			cout << "You lost" << endl;
			break;
		}
	} while (checker == false);
}


/*string getRandomWord(int& index) {
	return Words[index];
}

string getHint(int& index) {
	ifstream hints;
	string hint;
	int hintInd = 1;
	hints.open("hints.txt", ios::in);
	getline(hints, hint);
	if (hintInd == index) {
		return hint;
	}
}*/

/*string hint()
{
	string hints[10];
	ifstream inFile;
	inFile.open("hints.txt");
	for (int i = 1; i <= 10; i++)
	{
		while (getline(inFile, hints[i]))
		{
			cout << hints[i];
		}
	}
}
*/


bool menu(int& index) {
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
		guessTheWord(index);
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