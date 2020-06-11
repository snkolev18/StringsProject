#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "structures.h"

using namespace std;

void readQuestions(GAME& quiz, int& count)
{
	ifstream inputFile("words.txt");
	int cnt = 0;
	if (inputFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			if (cnt % 2 == 0) {
				quiz.wordlist[count] = line;
			}
			else {
				quiz.hints[count] = line;
				count++;
			}
			cnt++;
			if (cnt > 1) {
				cnt = 0;
			}
		}
	}
}

void readAccounts(int& count, USER* users) {
	ifstream inputFile("accounts.txt");
	string line;
	while (getline(inputFile, line)) {
		istringstream ss(line);
		ss >> users[count].username >> users[count].password;
		count++;
	}
}

int randomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void welcome() {
	cout << R"(     _     _     _     _              _                          
    | |   (_)   | |   | |            | |                 
    | |__  _  __| | __| | ___ _ __   | |_ ___  __ _ _ __ 
    | '_ \| |/ _` |/ _` |/ _ \ '_ \  | __/ _ \/ _` | '__|
    | | | | | (_| | (_| |  __/ | | | | ||  __/ (_| | |   
    |_| |_|_|\__,_|\__,_|\___|_| |_|  \__\___|\__,_|_|   )" << endl << endl;
}

int randomIndexWord(int numberOfQuestions) {
	int randomInd;
	randomInd = randomInt(0, numberOfQuestions);
	return randomInd;
}

void deleteAQuestion(GAME& quiz, int index,int numberOfQuestions) {
	for (size_t i = index; i < numberOfQuestions; i++) {
		quiz.wordlist[i] = quiz.wordlist[i + 1];
		quiz.hints[i] = quiz.hints[i + 1];
	}
}

void guessTheWord(USER* users,int user) {
	welcome();
	string userInput;
	GAME quiz;
	int countquiz = 0;
	readQuestions(quiz, countquiz);
	int index;
	int numberOfQuestions = countquiz - 1;
	bool checker = true;
	for (size_t i = 0; i < 10; i++) {
		index = randomIndexWord(numberOfQuestions);
		int tries = 3;
		cout << "\nHint" << i + 1 << ": " << quiz.hints[index] << "\nIt contains " << quiz.wordlist[index].length() << " letters";
		cout << endl;
		for (size_t j = 0; j < quiz.wordlist[index].length(); j++) {
			cout << "_";
		}
		cout << endl;
		do {
			cin >> userInput;
			if (userInput == quiz.wordlist[index]) {
				cout << "Congrats you guessed the word" << endl;
				checker = true;
				users[user].score++;
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
		deleteAQuestion(quiz, index, countquiz);
		numberOfQuestions--;
	}
}

void results(USER* users,int user)
{
	cout << "Your score is " << users[user].score << " points" << endl;
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
		if (users[i].username.find(username) != string::npos) {
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
	welcome();
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
	myfile << users[count].username << " " << users[count].password << endl;
	myfile.close();
	count++;
}

//pr
bool userMenu(int count, USER* users, int user) {
	int option;
	cout << "------" << endl;
	cout << "1.   Play guess the word" << endl;
	cout << "2.   Show results" << endl;
	cout << "9.   Sign out" << endl;
	cout << "------" << endl;
	cout << "Choose your option: ";
	while (!(cin >> option)) {
		cout << "Incorrect input. ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Try again: ";
	}
	switch (option) {
	case 1: system("cls");
		guessTheWord(users,user);
		cout << "Thank you for playing our game!!!" << endl;
		break;
	case 2: results(users, user);
		break;
	case 9: return false;
		break;

	default: cout << "That's not a valid option" << endl;
		break;
	}
	return true;
}

//pr
void addWordsAndHints()
{
	welcome();
	ofstream myfile;
	string word, hint;
	myfile.open("words.txt", ios::app);
	cout << "Word: ";
	cin >> word;
	cout << "Hint: ";
	cin.ignore();
	getline(cin, hint);
	myfile << word << endl;
	myfile << hint << endl;
	myfile.close();
}

//pr
void showWordsAndHints()
{
	int count = 0;
	GAME results;
	readQuestions(results, count);
	ifstream inFile;
	int cnt = 0;
	string hint;
	string word;
    inFile.open("words.txt");
    if (!inFile) {
        cout << "Unable to open file";
    }
    
    while (getline(inFile,word)) {
		results.wordlist[cnt++] = word;
		getline(inFile, hint);
		cout << cnt << ": " << word << " - " << hint << endl;
    }
}

void seeAllUsers(USER* users) {
	int count = 0;
	int cnt = 0;
	ifstream file;
	string username;
	file.open("accounts.txt");
	if (!file.is_open()) {
		cout << "Unable to open file";
	}
	while (file >> username) {
		if (count % 2 == 0) {
			users[cnt++].username = username;
			cout << cnt << ": " << username << endl;
		}
		count++;
	}
}



/*
void deleteAUser(int line){

      std::string line;
std::ifstream fin;

fin.open(path);
std::ofstream temp; // contents of path must be copied to a temp file then renamed back to the path file
temp.open("temp.txt");

while (getline(fin, line)) {
    if (line != eraseLine) // write all lines to temp other than the line marked fro erasing
        temp << line << std::endl;
}


temp.close();
fin.close();

const char * p = path.c_str(); // required conversion for remove and rename functions
remove(p);
rename("temp.txt", p);
*/

bool adminMenu(int count, USER* users, int user)
{
	int option;
	welcome();
	cout << "------" << endl;
	cout << "1.   Add new words and hints" << endl;
	cout << "2.   Show a list of all the words and hints" << endl;
	cout << "3.   See all users" << endl;
	cout << "9.   Sign out" << endl;
	cout << "------" << endl;
	cout << "Choose your option: ";
	while (!(cin >> option)) {
		cout << "Incorrect input. ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Try again: ";
	}
	switch (option) {
	case 1: system("cls");
		addWordsAndHints();
		break;
	case 2: showWordsAndHints();
		break;
	case 3: seeAllUsers(users);
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
	welcome();
	int wrongCounter = 0;
	string username = "", password = "";

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
	case 1: system("cls");
		registration(users, count);
		system("cls");
		break;
	case 2: system("cls");
		login(count, users);
		system("cls");
		break;
	default:
		cout << "That's not a valid option!!!" << endl;
		break;
	case 9: 
		return false;
	}
	return true;
}
