#pragma once

using namespace std;


struct GAME{
	string word[100];
	string definitions[100];
};


struct USER {
	string username;
	string password;
	int score = 0;
};