// Keywords_II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	char again;
	int sims = 1;  // Create an int var to count the number of simulations being run starting at 1
	do
	{ 
	//setup
	const int MAX_WRONG = 8;  //maximum number of incorrect guesses allowed
	
	vector<string> words;   //collection of possible 10 words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("SPY");
	words.push_back("ESPIONAGE");
	words.push_back("BLACKBIRD");
	words.push_back("YALE");
	words.push_back("SURVEILLANCE");
	words.push_back("UNDERCOVER");
	words.push_back("INTEL");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0]; //word to guess
	int wrong = 0; //number of incorrect guesses
	string soFar(THE_WORD.size(), '-');//words guessed so far
	string used =""; //letters already guessed
	string name;
	//Display Title of program to user
	cout << "Welcome to Hangman.\n";
	// Display an overview of what Keywords II is to the recruit 
	cout << "In this game there are a list of secret code words. Its your job to guess the word!\n";
	// Display an directions to the recruit on how to use Keywords
	cout << "Try guessing the word one letter at a time. But be careful you dont guess the wrong letter\n";
	cout << "If you geuss 8 wrong letters, the Hangman will get you! You will be shown what letters you have\n";
	cout << "already used and what you currently have. Good Luck!\n";
	cout << "starting simulation # " << sims << ".\n";
	//Ask the recruit to login using thier name
	cout << "Please enter your name\n";
	cin >> name;// Hold the recruit's name in a var, and address them by it throughout the simulation.
	//main loop

		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{ 
			// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			cout << "\n\nYou have " << (MAX_WRONG - wrong);//  Tell recruit how many incorrect guesses he or she has left
			cout << " incorrect guesses left, " << name << "\n";//   Show recruit the letters he or she has guessed
			cout << "\nYou’ve used the following letters:\n" << used << endl; //  Show recruit the letters he or she has guessed
			cout << "\nSo far, the word is:\n" << soFar << endl;  //  Show player how much of the secret word he or she has guessed
		
		 
			char guess;
			cout << "\n\nEnter your guess " << name << ":";  //  Get recruit's next guess
			cin >> guess;
			guess = toupper(guess); //make uppercase since secret word is in uppercase
			while (used.find(guess) != string::npos)
			{
				cout << "\nYou've already guessed " << guess << endl;  //  While recruit has entered a letter that he or she has already guessed
				cout << "Enter your guess " << name << "\n";  //  Get recruit's guess
				cin >> guess;
				guess = toupper(guess);
			}

			used += guess;  //  Add the new guess to the group of used letter

			if (THE_WORD.find(guess) != string::npos) //  If the guess is in the secret word
			{
				cout << "thats right " << name << "!" << guess << "is in the word.\n";  //  Tell the recruit the guess is correct
				//update soFar to include newly guessed letter
				for (int i = 0; i < THE_WORD.length(); ++i)
				{
					if (THE_WORD[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}
			else  //Otherwise
			{
				cout << "Sorry," << name << " " << guess << "isnt in the word.\n"; //  Tell the recruit the guess is incorrect
				++wrong;
			}
		}
		//shutdown
		if (wrong == MAX_WRONG)  // If the recruit has made too many incorrect guesses
		{
			cout << "\nYouve been hanged!";  //  Tell the recruit that he or she has failed the Keywords II course.
		}
		else  //Otherwise
		{
			cout << "\nYou guessed it " << name << "!";  // Congratulate the recruit on guessing the secret word
		}

		cout << "\nThe word was " << THE_WORD << endl;
		cout << "would you like to play again? y/n?";  // Ask the recruit if they would like to run the simulation again
		cin >> again;
	} while (again == 'y');
	if (again == 'y')// If the recruit wants to run the simulation again
	{
		return ++sims;  // Increment the number of simiulations ran counte
	}
	else  //Otherwise
	{
		cout << "End Of Simulation\n";  // Display End of Simulations to the recruit

	}

	system("pause");  // Pause the Simulation with press any key to continue
    return 0;
}

