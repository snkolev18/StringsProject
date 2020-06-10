#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "structures.h"

using namespace std;
void readAccounts(int& count,USER* users) {
	ifstream inputFile("accounts.txt");
	string line;
	while (getline(inputFile, line))
	{
		istringstream ss(line);
		ss >> users[count].username >> users[count].password >> users[count].score;
		count++;
	}
}
int randomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void welcome() {
	cout << R"(                                                
    | |   (_)   | |   | |            | |                 
    | |__  _  __| | __| | ___ _ __   | |_ ___  __ _ _ __ 
    | '_ \| |/ _` |/ _` |/ _ \ '_ \  | __/ _ \/ _` | '__|
    | | | | | (_| | (_| |  __/ | | | | ||  __/ (_| | |   
    |_| |_|_|\__,_|\__,_|\___|_| |_|  \__\___|\__,_|_|   )" << endl;
}

int randomIndexWord(int numberOfQuestions) {
	int randomInd;
	randomInd = randomInt(0, numberOfQuestions);
	return randomInd;
}

void deleteAQuestion(GAME& quiz, int index) {
	for (size_t i = index; i < 9; i++) {
		quiz.wordlist[i] = quiz.wordlist[i + 1];
		quiz.hints[i] = quiz.hints[i + 1];
	}
}

void guessTheWord() {
	string userInput;
	GAME gameParts;
	int index;
	int numberOfQuestions = 14;
	bool checker = true;
	for (size_t i = 0; i < 10; i++) {
		index = randomIndexWord(numberOfQuestions);
		int tries = 3;
		cout << "\nHint" << i + 1 << ": " << gameParts.hints[index] << "\nIt contains " << gameParts.wordlist[index].length() << " letters";
		cout << endl;
		for (size_t j = 0; j < gameParts.wordlist[index].length(); j++) {
			cout << "_" << " ";
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
				if (tries == 1) {
					cout << "You have " << tries << " try left" << endl;
				}
				else {
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
		deleteAQuestion(gameParts, index);
		numberOfQuestions--;
	}
}

void results()
{
	cout << "Your score is " << "10" << " points" << endl;
}

bool grantAccess(string username, string password, int count, USER* users)
{
	for (size_t i = 0; i < count; i++) {
		if (users[i].username == username && users[i].password == password) {
			return true;
		}
	}
	return false;
}

int findUserByUsername(string username, int count, USER* users)
{
	for (int i = 0; i < count; i++) {
		if (users[i].username == username) {
			return i;
		}
	}
	return -1;
}

bool checkPassword(string password)
{
	int countLowLetters = 0, countUpLetters = 0;
	for (size_t i = 0; i < password.size(); i++) {
		if (password[i] >= 'A' && password[i] <= 'Z') {
			countUpLetters++;
		}
		else if (password[i] >= 'a' && password[i] <= 'z') {
			countLowLetters++;
		}
	}
	if (password.size() < 8 or countLowLetters == 0 or countUpLetters == 0) {
		return false;
	}
	return true;

}

void registration(USER* users, int& count)
{
	cout << "Username: ";
	cin.ignore();
	getline(cin, users[count].username);

	while (findUserByUsername(users[count].username, count, users) != -1) {
		cout << "This username is already taken!" << endl;
		cout << "Try with another username: ";
		getline(cin, users[count].username);
	}
	cout << "Password: ";
	getline(cin, users[count].password);
	while (!checkPassword(users[count].password)) {
		cout << "Your password must have at least 8 symbols, 1 small letter and 1 big letter" << endl;
		cout << "Try with another password: ";
		getline(cin, users[count].password);
	}
	ofstream myfile;
	myfile.open("accounts.txt", ios::app);
	myfile << users[count].username << " " << users[count].password << " 0" << endl;
	myfile.close();
	count++;
}

bool userMenu(int count, USER* users, int user) {
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
	switch (option) {
	case 1: guessTheWord();
		break;
	case 2: results();
		break;
	case 3:
		break;
	case 9: cout << "Thank you for playing our game!!!" << endl;
		return false;

	default: cout << "That's not a valid option" << endl;
		break;
	}
	return true;
}
void addWordsAndHints()
{

}
void showWordsAndHints()
{

}
bool adminMenu(int count, USER* users, int user)
{
	int option;
	welcome();
	cout << "------" << endl;
	cout << "1.   Add new words and hints" << endl;
	cout << "2.   Show a list of all the words and hints" << endl;
	cout << "3.   See all users" << endl;
	cout << "4.   Delete a user" << endl;
	cout << "9.   " << endl;
	cout << "------" << endl;
	cout << "Choose your option: ";
	while (!(cin >> option)) {
		cout << "Incorrect input. ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Try again: ";
	}
	switch (option) {
	case 1: addWordsAndHints();
		break;
	case 2: showWordsAndHints();
		break;
	case 3:
		break;
	case 4:
		break;

	default:
		cout << "That's not a valid option" << endl;
		break;
	case 9: return false;
	}
	return true;
}
void login(int count, USER* users)
{
	int wrongCounter = 0;
	string username, password;

	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	while (!grantAccess(username, password, count, users) && wrongCounter != 3) {
		cout << "Your username/password is incorrect" << endl;
		cout << "Please try again" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		wrongCounter++;
	}

	int user = findUserByUsername(username, count, users);

	if (grantAccess(username, password, count, users) && wrongCounter != 3) {
		system("cls");
		welcome();
		bool showMenu;
		if (username == users[0].username && password == users[0].password)
		{
			do {
				showMenu = adminMenu(count, users, user);
			} while (showMenu);
		}
		else
		{
			do {
				showMenu = userMenu(count, users, user);
			} while (showMenu);
		}
	}
}

bool registrationMenu(int& count, USER* users) //The menu that goes right after the startup text
{
	welcome();
	bool showRulesMenu = true;
	int choice;
	cout << "------" << endl;
	cout << "1.   Register" << endl;
	cout << "2.   Login" << endl;
	cout << "9.   Exit" << endl;
	cout << "------" << endl;
	cout << "Enter your choice: ";
	while (!(cin >> choice)) {
		cout << "Incorrect input. ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Try again: ";
	}
	switch (choice)
	{
	case 1:
		registration(users, count);
		break;
	case 2:
		login(count, users);
		break;
	default:
		cout << "That's not a valid option!!!" << endl;
		break;
	case 9:
		return false;
	}
	return true;
}
