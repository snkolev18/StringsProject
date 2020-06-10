#pragma once

using namespace std;

struct GAME{
	string wordlist[15] = { "woman", "jump", "copper", "calendar", "boyfriend", "king", "album", "monkey", "objective", "laptop", "banana", "apple", "school", "gold", "banknote" };

	string hints[15]{
		"It's like a man, but not actually",
		"Move suddenly and quickly in a specified way",
		"A red-brown metal, the chemical element of atomic number 29",
		"A chart or series of pages showing the days, weeks, and months of a particular year, or giving particular seasonal information",
		"A person's regular male companion with whom they have a romantic or sexual relationship",
		"The male ruler of an independent state, especially one who inherits the position by right of birth",
		"A blank book for the insertion of photographs, stamps, or pictures",
		"A small to medium-sized primate that typically has a long tail, most kinds of which live in trees in tropical countries.",
		"A thing aimed at or sought; a goal.",
		"A computer that is portable and suitable for use while travelling.",
		"A long curved fruit which grows in clusters and has soft pulpy flesh and yellow skin when ripe.",
		"A round red fruit.",
		"An institution for educating children.",
		"A yellow precious metal, the chemical element of atomic number 79",
		"A piece of paper money"
	};
};


struct USER {
	string username;
	string password;
	int score = 0;
};