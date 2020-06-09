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
	int score = 0;
	srand(time(NULL));
	bool Menu = true;
	do {
		Menu = menu(score);
	} while (Menu);
}