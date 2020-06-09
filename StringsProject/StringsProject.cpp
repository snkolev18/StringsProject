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
	int index = randomIndexWord();
	bool Menu = true;
	do{
		Menu = menu(index);
	} while (Menu);
}

