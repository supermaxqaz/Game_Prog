#include <iostream>
#include "FrAmEwOrK/foo.h"

using namespace std;

int foo(int bar)
{
	return (bar + 1);
}

void guessNumber(int& guess, int num)
{
	cout << "Guess a number: ";
	cin >> guess;
	while (guess < 0 || guess > 100)
	{
		cout << "That is not a valid guess. Please try another number: ";
		cin >> guess;
	}

	if (guess > num)
	{
		cout << "Lower!" << endl;
	}
	else if (guess < num)
	{
		cout << "Higher!" << endl;
	}
}