#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
#include "functions.h"
#include "structures.h"

using namespace std;


int main()
{
	USER users[64];
	GAME quiz[64];
	int count = 0, gameCount = 0;
	readAccounts(count,users);
	srand(time(NULL));
	bool Menu = true;
	do {
		Menu = registrationMenu(count, users);
	} while (Menu);
}