#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <conio.h>
#include "structures.h"

using namespace std;


//==================================================================\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******DATA LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==================================================================//


void readQuestions(GAME& quiz, int& countQuestions) //Stores the words with their definitions in a structure
{
	ifstream inputFile("questions.txt");
	int firstAndSecondLine = 0;
	string line;
	if (inputFile.is_open()) 
	{
		while (getline(inputFile, line)) 
		{
			if (firstAndSecondLine % 2 == 0) 
			{
				quiz.word[countQuestions] = line;
			}
			else 
			{
				quiz.definitions[countQuestions] = line;
				countQuestions++;
			}
			firstAndSecondLine++;
			if (firstAndSecondLine > 1) 
			{
				firstAndSecondLine = 0;
			}
		}
	}
}

void readAccounts(int& countUsers, USER* users) //Stores the accounts in a structure
{
	ifstream inputFile("accounts.txt");
	int firstAndSecondLine = 0;
	string line;
	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			if (firstAndSecondLine % 2 == 0)
			{
				users[countUsers].username = line;
			}
			else
			{
				users[countUsers].password = line;
				countUsers++;
			}
			firstAndSecondLine++;
			if (firstAndSecondLine > 1)
			{
				firstAndSecondLine = 0;
			}
		}
	}
}

void asteriskInput(string& password) //Displays the user passowrd with * 
{
	char asteriskPassword;
	asteriskPassword = _getch();
	while (asteriskPassword != 13) //If he clicks "Enter", the loop will stop
	{
		if (asteriskPassword == 8) //If he clicks "Backspace", he will delete the last symbol as it should happen
		{
			if (password.length() > 0) 
			{
				cout << "\b \b";
				password.erase(password.length() - 1);
			}
		}
		else 
		{
			cout << "*";
			password += asteriskPassword;
		}
		asteriskPassword = _getch();
	}
}

int randomInt(int min, int max) //Returns a random number in the closed interval of the given numbers
{
	return rand() % (max - min + 1) + min;
}

int randomIndexWord(int lastIndexOfQuestions) //Returns a random index in the closed interval of 0 and the number of questions which are not used
{
	int randomIndex;
	randomIndex = randomInt(0, lastIndexOfQuestions);
	return randomIndex;
}

bool checkUsername(string username) //Checks if the username contains enough symbols
{
	if (username.size() < 6) //If it contains less than 6 symbols, it will return false
	{
		return false;
	}
	return true; //If it contains more than 5 symbols, it will return true
}

bool checkPassword(string password) //Checks if the password passes all the requirements
{
	int countLowLetters = 0, countUpLetters = 0;
	for (size_t i = 0; i < password.size(); i++) 
	{
		if (password[i] >= 'A' && password[i] <= 'Z') 
		{
			countUpLetters++;
		}
		else if (password[i] >= 'a' && password[i] <= 'z') {
			countLowLetters++;
		}
	}
	if (password.size() < 8 or countLowLetters == 0 or countUpLetters == 0) //If the password does not contain one lowercase letter, one uppercase letter and 8 symbols, it will return false
	{
		return false;
	} //If it pass all the requirements, it will return true
	return true;
}

bool grantAccess(string username, string password, int count, USER* users) //Checks for user with the given username and password
{
	for (int i = 0; i < count; i++) 
	{
		if (users[i].username == username && users[i].password == password) //If there is a user with the given username and password, it will return true
		{
			return true;
		}
	}
	return false; //If there are not any users with the given username and password, it will return false
}

int findUserByUsername(string username, int count, USER* users) //Returns the index of a user with the given username
{
	for (int i = 0; i < count; i++) 
	{
		if (users[i].username == username)
		{
			return i;
		}
	}
	return -1; //If there are not any users with that username, it will return -1
}

void deleteAQuestion(GAME& quiz, int index, int countQuestions) //Deletes the question with the given index
{
	for (size_t i = index; i < countQuestions; i++) 
	{
		quiz.word[i] = quiz.word[i + 1];
		quiz.definitions[i] = quiz.definitions[i + 1];
	}
}


//==========================================================================\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////******PRESENTATION LAYER******\\\\\\\\\\\\\\\\\\\\\\\\
\\==========================================================================//


void welcome() //Header
{
	cout << R"(     _     _     _     _              _                          
    | |   (_)   | |   | |            | |                 
    | |__  _  __| | __| | ___ _ __   | |_ ___  __ _ _ __ 
    | '_ \| |/ _` |/ _` |/ _ \ '_ \  | __/ _ \/ _` | '__|
    | | | | | (_| | (_| |  __/ | | | | ||  __/ (_| | |   
    |_| |_|_|\__,_|\__,_|\___|_| |_|  \__\___|\__,_|_|   )" << endl << endl;
}

void lineDesignUp() //Line for the design 
{
	cout << "/==============\\" << endl;
}

void lineDesignDown() //Line for the design
{
	cout << "\\==============/" << endl;
}

void registration(USER* users, int& countUsers) //Registers a user
{
	welcome();
	int wrongCount = 0;
	cout << "Username: ";
	cin.ignore();
	getline(cin, users[countUsers].username);
	if (users[countUsers].username.find(' ')!=string::npos)
	{
		wrongCount++;
	}
	while (findUserByUsername(users[countUsers].username, countUsers, users) != -1 or wrongCount != 0 or !checkUsername(users[countUsers].username))
	{
		if (wrongCount > 0)
		{
			cout << "Your username must not contain spaces!" << endl;
		}
		if (findUserByUsername(users[countUsers].username, countUsers, users) != -1)
		{
			cout << "This username is already taken!" << endl;
		}
		if (!checkUsername(users[countUsers].username))
		{
			cout << "Your username must contain more than five characters!" << endl;
		}
		cout << "Try with another username: ";
		getline(cin, users[countUsers].username);
		wrongCount = 0;
		if (users[countUsers].username.find(' ') != string::npos)
		{
			wrongCount++;
		}
	}
	cout << "Password: ";
	asteriskInput(users[countUsers].password);
	while (!checkPassword(users[countUsers].password)) 
	{
		cout << "\nYour password must have at least 8 symbols, 1 small letter and 1 big letter" << endl;
		cout << "Try with another password: ";
		asteriskInput(users[countUsers].password);
	}
	ofstream inFile;
	inFile.open("accounts.txt", ios::app);
	inFile << users[countUsers].username << endl; //Stores the word in a text file
	inFile << users[countUsers].password << endl; //Stores the definition in a text file
	inFile.close();
	countUsers++;
}

void showScore(USER* users, int loggedUser) //Shows the score of the user
{
	welcome();
	if (users[loggedUser].score == 1)
	{
		cout << "\nYour score is " << users[loggedUser].score << " point\n" << endl;
	}
	else
	{
		cout << "\nYour score is " << users[loggedUser].score << " points\n" << endl;
	}
}

void guessTheWord(USER* users, int loggedUser) //Runs a game called "Guess the word"
{
	welcome();
	string answer;
	GAME quiz;
	int countQuestions = 0;
	readQuestions(quiz, countQuestions);
	int randomIndex;
	int lastIndexOfQuestions = countQuestions - 1;
	bool rightAnswer = true;
	for (size_t i = 0; i < 10; i++) {
		randomIndex = randomIndexWord(lastIndexOfQuestions);
		int tries = 3;
		cout << endl;
		cout << i + 1 << ". Definition: " << quiz.definitions[randomIndex] << "\nIt contains " << quiz.word[randomIndex].length() << " letters";
		cout << endl;
		for (size_t j = 0; j < quiz.word[randomIndex].length(); j++) 
		{
			cout << "_";
		}
		cout << endl;
		do 
		{
			cin >> answer;
			for (size_t i = 0; i < answer.length(); i++)
			{
				answer[i] = tolower(answer[i]);
			}
			if (answer == quiz.word[randomIndex]) 
			{
				cout << "\nCongrats you guessed the word!" << endl;
				cout << "You get 1 point for guessing it!" << endl;
				rightAnswer = true;
				users[loggedUser].score++;
			}
			else if (tries > 0)
			{
				tries -= 1;
				if (tries == 1) 
				{
					cout << "You have " << tries << " try left!" << endl;
				}
				else 
				{
					cout << "You have " << tries << " tries left!" << endl;
				}
				cout << "Your input doesn't match the given word. Try again!" << endl;
				rightAnswer = false;
				for (size_t j = 0; j < quiz.word[randomIndex].length(); j++) 
				{
					cout << "_";
				}
				cout << endl;
			}
			if (tries == 0) 
			{
				cout << "You have " << tries << " tries left!" << endl;
				cout << "You get 0 points from this question!" << endl;
				rightAnswer = true;
			}
		} while (rightAnswer == false);
		deleteAQuestion(quiz, randomIndex, countQuestions);
		lastIndexOfQuestions--;
	}
}

bool userMenu(int count, USER* users, int loggedUser) //Gives the user a menu
{
	int choice;
	lineDesignUp();
	cout << "1. Play guess the word" << endl;
	cout << "2. Show results" << endl;
	cout << "9. Sign out" << endl;
	lineDesignDown();
	cout << "Choose your option: ";
	while (!(cin >> choice)) //input validation. If it's string literall prompts the user to enter an option again
	{
		cout << "That's not a valid option!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Try again: ";
	}
	switch (choice) 
	{
	case 1: system("cls");
		guessTheWord(users, loggedUser);
		cout << "Thank you for playing our game!!!" << endl << endl;
		break;

	case 2: system("cls");
		showScore(users, loggedUser);
		break;

	case 9: return false;
		break;

	default: cout << "That's not a valid option" << endl;
		break;
	}
	return true;
}

void addWordsAndDefinitions() //Adds a new word with its definition
{
	welcome();
	ofstream myFile;
	string word, definition;
	myFile.open("questions.txt", ios::app);
	cout << "Word: ";
	cin >> word;
	for (size_t i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}
	cout << "Definition: ";
	cin.ignore();
	getline(cin, definition);
	myFile << word << endl; //Stores the word in a text file
	myFile << definition << endl; //Stores the definition in a text file
	myFile.close();
}

void showWordsAndDefinitions() //Prints out all the words with their definitions which are in the text file
{
	system("cls");
	welcome();
	int countQuestions = 0;
	GAME results;
	readQuestions(results, countQuestions);
	ifstream inFile;
	int numberOfQuestion = 0;
	string definition;
	string word;
	inFile.open("questions.txt");
	if (!inFile) 
	{
		cout << "Unable to open file";
	}
	while (getline(inFile, word)) 
	{
		numberOfQuestion++;
		getline(inFile, definition);
		cout << numberOfQuestion << ": " << word << " - " << definition << endl; //Prints out the word with its definition
	}
	cout << endl;
}

void showAllUsers() //Prints out all the usernames which are in the text file
{
	system("cls");
	welcome();
	int countUsers = 0;
	ifstream inFile;
	string username;
	inFile.open("accounts.txt");
	if (!inFile.is_open()) {
		cout << "Unable to open file";
	}
	while (getline(inFile, username))
	{
		countUsers++;
		cout << countUsers << ". Username: " << username << endl;
		getline(inFile, username);
	}
	cout << endl;
}

bool adminMenu(USER* users) //Gives the admin a menu
{
	int choice;
	lineDesignUp();
	cout << "1. Add a new word with its definition" << endl;
	cout << "2. Show a list of all words with their definitions" << endl;
	cout << "3. Show a list of all users" << endl;
	cout << "9. Sign out" << endl;
	lineDesignDown();
	cout << "Choose your option: ";
	while (!(cin >> choice)) //Input validation. If it is a string, it will prompt the user to enter an option again
	{
		cout << "That's not a valid option!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Try again: ";
	}
	switch (choice) {
	case 1: system("cls");
		addWordsAndDefinitions();
		break;
	case 2: showWordsAndDefinitions();
		break;
	case 3: showAllUsers();
		break;
	default:
		cout << "That's not a valid option" << endl;
		break;
	case 9: return false;
	}
	return true;
}

void login(int countUsers, USER* users) //Shows a menu depending on the credentials
{
	welcome();
	int wrongCounter = 0;
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	asteriskInput(password);

	while (!grantAccess(username, password, countUsers, users) && wrongCounter != 3) {
		cout << "\nYour username/password is incorrect!" << endl;
		cout << "Please try again!" << endl;
		username = "";
		password = "";
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		asteriskInput(password);
		wrongCounter++;
	}

	int loggedUser = findUserByUsername(username, countUsers, users);

	if (grantAccess(username, password, countUsers, users) && wrongCounter != 3) {
		system("cls");
		welcome();
		bool showMenu;
		if (username == users[0].username && password == users[0].password) //Checks if admin credentials
		{
			do {
				showMenu = adminMenu(users);
			} while (showMenu);
		}
		else
		{
			do {
				showMenu = userMenu(countUsers, users, loggedUser);
			} while (showMenu);
		}
	}
}

bool menu(int& countUsers, USER* users) //The menu that asks you if you want to register, login or exit
{
	welcome();
	bool showRulesMenu = true;
	int choice;

	lineDesignUp();
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "9. Exit" << endl;
	lineDesignDown();
	cout << "Enter your choice: ";

	while (!(cin >> choice)) //Input validation. If it's string literall prompts the user to enter an option again
	{
		cout << "That's not a valid option!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Try again: ";
	}

	switch (choice)
	{
	case 1: system("cls");
		registration(users, countUsers);
		system("cls");
		break;
	case 2: system("cls");
		login(countUsers, users);
		system("cls");
		break;
	default: system("cls");
		cout << "That was not a valid option!" << endl;
		break;
	case 9:
		return false;
	}

	return true;
}
