#pragma once

using namespace std;


struct GAME{
	string wordlist[100];
	string hints[100];
};


struct USER {
	string username;
	string password;
	int score = 0;
};