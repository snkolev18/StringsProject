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
	srand(time(NULL));
	bool Menu = true;
	do {
		Menu = menu();
	} while (Menu);
}