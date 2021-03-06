/*
Keywords
Kieli Adkins
CSC215
May 20, 2018
*/

// Including standard libraries
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Adkins_Keywords_1v.h"

// Using std namespace
using namespace std;

// Initializing main function
int main()
{
	// Declaring playAgain variable
	char playAgain; 

	// Initializing game loop
	do
	{
		// Enumerator to store word and hint elements 
		enum fields {WORD, HINT, NUM_FIELDS};

		// Declaring a constant with the amount of rows within the array
		const int NUM_WORDS = 10; 

		// Creating the two-dimensional array
		const string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			// Code words and the hints associated with each one
			{"destroy", "The action of breaking something down."},
			{"imperial", "Darth Vader is the leader of what force?"},
			{"cherish", "To love something dearly."},
			{"firewall", "A computer uses what to defend itself from viruses?"},
			{"cardinal", "A bird that is bright red in color."},
			{"seattle", "The capital of Washington state."},
			{"marigold", "A bright yellow flower."},
			{"texas", "The second largest state in the United States."},
			{"phoenix", "The capital of Arizona."},
			{"platypus", "A mysterious creature that appears to be a cross between a duck and a beaver."},
		};

		// // // // //
		//
		// Welcome Sequence
		//
		// // // // //

		// Instructions for game
		cout << "----------\nWelcome to Keywords\n----------\n\n";
		cout << "Keywords is a code breaking simulator, that will be used to help prepare you for your position at the CIA.\n\n";
		cout << "Your task, should you choose to accept it, is to unscramble the letters to create the correct word.\n";
		cout << "If you get stuck on a word, enter 'hint' to receive a hint.\n\n\n";


		// // // // //
		//
		// Gameplay
		//
		// // // // //

		// Declaring success variable
		int success = 0; 

		// Initializing for loop
		for (int r = 0; r < 3; ++r)
		{
			// Seeding the random number generator
			srand(static_cast<unsigned int>(time(0)));

			// Generating a random word
			int choice = (rand() % NUM_WORDS);

			// Picking the word that will be guessed
			string theWord = WORDS[choice][WORD];

			// Retrieving the corresponding hint
			string theHint = WORDS[choice][HINT];

			// Setting up the copy of the original words to scramble them
			string scramble = theWord;

			// Retrieving the word size
			int length = scramble.size();

			// for loop regarding letter scramble
			for (int i = 0; i < length; ++i)
			{
				// Grabbing index position to begin "scrambling"
				int index1 = (rand() % length);
				int index2 = (rand() % length);

				// Storing the index 1 scramble as a character
				char temp = scramble[index1];

				// Further scrambling processes
				scramble[index1] = scramble[index2];
				scramble[index2] = temp;
			}

			// Starting game
			cout << "----------\nThe keyword to unscramble is: " << scramble << "\n----------\n\n";

			// Capturing player guess input
			string playerGuess;
			cout << "Your guess is: ";
			cin >> playerGuess;

			// Declaring tries variable
			int tries = 0;

			// While loop for hint/incorrect sequence
			while (playerGuess != theWord)
			{
				// If statement regarding hint entry
				if (playerGuess == "hint")
				{
					cout << "\n" << theHint;
				}

				// Else statement regarding incorrect answer
				else
				{
					++tries;
					cout << "----------\nSorry, that is incorrect.\n----------\n";
				}

				// Capturing secondary guess
				cout << "\nYour guess: ";
				cin >> playerGuess;
			}

			// If correct answer is given
			++success;
			++tries;
			cout << "\n----------\nCongratulations! You have unscrambled the word correctly.\n";
			cout << "It resulted in a total of " << tries << " tries to achieve the correct answer.\n----------\n\n";
		}



		// // // // //
		//
		// Results Sequence
		//
		// // // // //

		// if statement regarding correct words
		if (success == 1)
		{
			cout << "Your code breaking skills need improvement. Please run simulation again.\n\n";
		}

		else if (success == 2)
		{
			cout << "Your getting a hang of it! We suggest more practice to polish code breaking skills.\n\n";
		}

		else
		{
			cout << "You have mastered this simulation! Please contact instructor for next simulation module.\n\n";
		}

		// Simulation quit?
		cout << "If you would like to play simulation again enter 'y', if not press any key to exit.";
		cin >> playAgain;

	} 
	while (playAgain != 'y' || playAgain != 'Y');
    return 0;
}

