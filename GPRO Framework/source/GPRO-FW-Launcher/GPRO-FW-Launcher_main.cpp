// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "FrAmEwOrK/foo.h"

using namespace std;

int main()
{
	// int test = foo(9000);

	// cout << test << endl;
	srand(time(0));

	char exit = 'n';

	while (exit == 'n')
	{
		int num = rand() % 101;
		int guess;

		cout << "I have a secret number for you to guess (0-100)" << endl;

		do
		{
			guessNumber(guess, num);
		} while (guess != num);

		cout << "Congrats! You guessed the number, it was " << num << endl;

		cout << "Would you like to exit? ";
		cin >> exit;
		exit = tolower(exit);
	}
}
