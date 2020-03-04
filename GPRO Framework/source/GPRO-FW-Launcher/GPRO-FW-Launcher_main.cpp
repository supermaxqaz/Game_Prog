#include <iostream>
#include <string>
// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

int launchTicTacToe();
int launchBattleship();
int main()
{
	int choice = 0;
cout << "Do you want to play TicTacToe (1) or Battleship (2)?" << endl;
	cin >> choice;
	if (choice == 1)
	{
		launchTicTacToe();
	}
	else if (choice == 2)
	{
		launchBattleship();
	}
	cout << "" << endl;
}
