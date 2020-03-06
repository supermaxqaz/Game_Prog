
#include <stdio.h>
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------
// DECLARATIONS

#define GS_BATTLESHIP_PLAYERS				2
#define GS_BATTLESHIP_BOARD_WIDTH			10
#define GS_BATTLESHIP_BOARD_HEIGHT			10

enum gs_battleship_space_state
{
	// invalid space state
	gs_battleship_space_invalid = -1,

	// states visible to both players
	gs_battleship_space_open,			// space is open and unguessed
	gs_battleship_space_miss,			// space was guessed and missed
	gs_battleship_space_hit,			// space was guessed and hit

	// states hidden from opponent player
	gs_battleship_space_patrol2,		// 2-unit patrol boat
	gs_battleship_space_submarine3,		// 3-unit submarine
	gs_battleship_space_destroyer3,		// 3-unit destroyer
	gs_battleship_space_battleship4,	// 4-unit battleship
	gs_battleship_space_carrier5,		// 5-unit carrier
};
#ifndef __cplusplus
typedef		enum gs_battleship_space_state	gs_battleship_space_state;
#endif	// !__cplusplus

// battleship game state
typedef		unsigned char					gs_battleship_index;
typedef		gs_battleship_space_state		gs_battleship[GS_BATTLESHIP_PLAYERS][GS_BATTLESHIP_BOARD_WIDTH][GS_BATTLESHIP_BOARD_HEIGHT];


#define	GS_VALIDATE_COORDINATE(x,y,z,w,h,d)		(x < w && y < h && z < d)
#define GS_BATTLESHIP_VALID(p,x,y)				GS_VALIDATE_COORDINATE(x,y,p,GS_BATTLESHIP_BOARD_WIDTH,GS_BATTLESHIP_BOARD_HEIGHT,GS_BATTLESHIP_PLAYERS)


inline gs_battleship_space_state gs_checkers_getSpaceState(gs_battleship const game, gs_battleship_index const player, gs_battleship_index const xpos, gs_battleship_index const ypos)
{
	if (GS_BATTLESHIP_VALID(player, xpos, ypos))
		return (game[player][xpos][ypos]);
	return gs_battleship_space_invalid;
}

inline gs_battleship_space_state gs_checkers_setSpaceState(gs_battleship game, gs_battleship_space_state const state, gs_battleship_index const player, gs_battleship_index const xpos, gs_battleship_index const ypos)
{
	if (GS_BATTLESHIP_VALID(player, xpos, ypos))
		return (game[player][xpos][ypos] = state);
	return gs_battleship_space_invalid;
}

inline gs_battleship_index gs_battleship_reset(gs_battleship game)
{
	gs_battleship_index player, xpos, ypos, total;
	for (player = 0; player < GS_BATTLESHIP_PLAYERS; ++player)
		for (xpos = 0; xpos < GS_BATTLESHIP_BOARD_WIDTH; ++xpos)
			for (ypos = 0; ypos < GS_BATTLESHIP_BOARD_HEIGHT; ++ypos)
				game[player][xpos][ypos] = gs_battleship_space_open;
	total = (player * xpos * ypos);
	return total;
}


//-----------------------------------------------------------------------------
// DEFINITIONS

void drawBoard(gs_battleship const game, gs_battleship_index const player)
{
	for (int i = 0; i < GS_BATTLESHIP_BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < GS_BATTLESHIP_BOARD_WIDTH; j++)
		{
			if (gs_checkers_getSpaceState(game, player, j, i) == gs_battleship_space_patrol2)
			{
				cout << "P ";
			}
			else
			{
				cout << "- ";
			}
		}
		cout << endl;
	}
}

void placeShips(gs_battleship game, gs_battleship_index const player)
{
	int shipRowStart, shipColumnStart, shipRowEnd, shipColumnEnd;
	cout << "You are now placing the Patrol." << endl;
	cout << "Select a starting point (row): ";
	cin >> shipRowStart;
	cout << "Select a starting point (column): ";
	cin >> shipColumnStart;
	cout << "Select an ending point (row): ";
	cin >> shipRowEnd;
	cout << "Select an ending point (column): ";
	cin >> shipColumnEnd;
	if (sqrt(pow(shipRowEnd - shipRowStart, 2) + pow(shipColumnEnd - shipColumnStart, 2)) != 1)
	{
		cout << "Those points will not work." << endl;
		cout << "You are now placing the Patrol." << endl;
		cout << "Select a starting point (row, column): ";
		cin >> shipRowStart >> shipColumnStart;
		cout << "Select an ending point (row, column): ";
		cin >> shipRowEnd >> shipColumnEnd;
	}
	shipRowStart--;
	shipRowEnd--;
	shipColumnStart--;
	shipColumnEnd--;
	if (shipRowEnd != shipRowStart)
	{
		for (int i = shipColumnStart; i < shipColumnEnd; i++)
		{
			gs_checkers_setSpaceState(game, gs_battleship_space_patrol2, player, i, shipRowStart);
		}
	}
	else if (shipColumnEnd != shipColumnStart)
	{
		for (int i = shipRowStart; i < shipRowEnd; i++)
		{
			gs_checkers_setSpaceState(game, gs_battleship_space_patrol2, player, shipColumnStart, i);
		}
	}
	drawBoard(game, 1);

	/*cout << "You are now placing the Submarine." << endl;
	cout << "Select a starting point (row, column): ";
	cin >> shipRowStart >> shipColumnStart;
	cout << "Select an ending point (row, column): ";
	cin >> shipRowEnd >> shipColumnEnd;
	if (sqrt(pow(shipRowEnd - shipRowStart, 2) + pow(shipColumnEnd - shipColumnStart, 2)) != 3)
	{
		cout << "Those points will not work." << endl;
		cout << "You are now placing the Submarine." << endl;
		cout << "Select a starting point (row, column): ";
		cin >> shipRowStart >> shipColumnStart;
		cout << "Select an ending point (row, column): ";
		cin >> shipRowEnd >> shipColumnEnd;
	}

	cout << "You are now placing the Destroyer." << endl;
	cout << "Select a starting point (row, column): ";
	cin >> shipRowStart >> shipColumnStart;
	cout << "Select an ending point (row, column): ";
	cin >> shipRowEnd >> shipColumnEnd;
	if (sqrt(pow(shipRowEnd - shipRowStart, 2) + pow(shipColumnEnd - shipColumnStart, 2)) != 3)
	{
		cout << "Those points will not work." << endl;
		cout << "You are now placing the Destroyer." << endl;
		cout << "Select a starting point (row, column): ";
		cin >> shipRowStart >> shipColumnStart;
		cout << "Select an ending point (row, column): ";
		cin >> shipRowEnd >> shipColumnEnd;
	}

	cout << "You are now placing the Battleship." << endl;
	cout << "Select a starting point (row, column): ";
	cin >> shipRowStart >> shipColumnStart;
	cout << "Select an ending point (row, column): ";
	cin >> shipRowEnd >> shipColumnEnd;
	if (sqrt(pow(shipRowEnd - shipRowStart, 2) + pow(shipColumnEnd - shipColumnStart, 2)) != 4)
	{
		cout << "Those points will not work." << endl;
		cout << "You are now placing the Battleship." << endl;
		cout << "Select a starting point (row, column): ";
		cin >> shipRowStart >> shipColumnStart;
		cout << "Select an ending point (row, column): ";
		cin >> shipRowEnd >> shipColumnEnd;
	}

	cout << "You are now placing the Carrier." << endl;
	cout << "Select a starting point (row, column): ";
	cin >> shipRowStart >> shipColumnStart;
	cout << "Select an ending point (row, column): ";
	cin >> shipRowEnd >> shipColumnEnd;
	if (sqrt(pow(shipRowEnd - shipRowStart, 2) + pow(shipColumnEnd - shipColumnStart, 2)) != 5)
	{
		cout << "Those points will not work." << endl;
		cout << "You are now placing the Carrier." << endl;
		cout << "Select a starting point (row, column): ";
		cin >> shipRowStart >> shipColumnStart;
		cout << "Select an ending point (row, column): ";
		cin >> shipRowEnd >> shipColumnEnd;
	}*/
}

int launchBattleship()
{
	gs_battleship game;// = { 0 };

	gs_battleship_reset(game);

	cout << "Player 1 Board: " << endl;
	drawBoard(game, 1);

	cout << endl;

	cout << "Player 2 Board: " << endl;
	drawBoard(game, 2);

	placeShips(game, 1);
	// create "function" to place all of the ships

	// create full game loop

	// printing during game?

	// profit

	return 0;
}


//-----------------------------------------------------------------------------
