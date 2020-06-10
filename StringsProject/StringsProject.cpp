#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "functions.h"
#include "structures.h"

using namespace std;


int main()
{
	USER users[64];
	int score = 0, count = 0;
	srand(time(NULL));
	bool Menu = true;
	do {
		Menu = registrationMenu(count, users);
	} while (Menu);
}