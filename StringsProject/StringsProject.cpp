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
	srand(time(NULL));

	int countUsers = 0;
	USER users[64];
	bool Menu = true;

	readAccounts(countUsers, users);

	do {
		Menu = menu(countUsers, users);
	} while (Menu);

}