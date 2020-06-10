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

	int count = 0;
	USER users[64];
	bool Menu = true;

	readAccounts(count, users);

	do {
		Menu = registrationMenu(count, users);
	} while (Menu);

}