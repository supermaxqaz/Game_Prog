
#include <stdio.h>
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------
// DECLARATIONS

#define GS_TICTACTOE_PLAYERS					2
#define GS_TICTACTOE_BOARD_WIDTH				3
#define GS_TICTACTOE_BOARD_HEIGHT				3

enum gs_tictactoe_space_state
{
	// invalid space state
	gs_tictactoe_space_invalid = -1,

	// states visible to both players
	gs_tictactoe_space_open,	// space is open
	gs_tictactoe_space_o,		// space is taken by O player
	gs_tictactoe_space_x,		// space is taken by X player
};
#ifndef __cplusplus
typedef		enum gs_tictactoe_space_state		gs_tictactoe_space_state;
#endif	// !__cplusplus

// tic-tac-toe game state
typedef		unsigned char						gs_tictactoe_index;
typedef		gs_tictactoe_space_state			gs_tictactoe[GS_TICTACTOE_BOARD_WIDTH][GS_TICTACTOE_BOARD_HEIGHT];


#define	GS_VALIDATE_COORDINATE(x,y,w,h)			(x < w && y < h)
#define GS_TICTACTOE_VALID(x,y)					GS_VALIDATE_COORDINATE(x,y,GS_TICTACTOE_BOARD_WIDTH,GS_TICTACTOE_BOARD_HEIGHT)


inline gs_tictactoe_space_state gs_tictactoe_getSpaceState(gs_tictactoe const game, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos]);
	return gs_tictactoe_space_invalid;
}

inline gs_tictactoe_space_state gs_tictactoe_setSpaceState(gs_tictactoe game, gs_tictactoe_space_state const state, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos] = state);
	return gs_tictactoe_space_invalid;
}

inline gs_tictactoe_index gs_tictactoe_reset(gs_tictactoe game)
{
	gs_tictactoe_index xpos, ypos, total;
	for (xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos)
		for (ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos)
			game[xpos][ypos] = gs_tictactoe_space_open;
	total = (xpos * ypos);
	return total;
}


//-----------------------------------------------------------------------------
// DEFINITIONS

void drawBoard(gs_tictactoe const game)
{
	for (int i = 0; i < GS_TICTACTOE_BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < GS_TICTACTOE_BOARD_WIDTH; j++)
		{
			cout << gs_tictactoe_getSpaceState(game, j, i) << " ";
		}
		cout << endl;
	}
}

int launchTicTacToe()
{
	gs_tictactoe game; //= { 0 };

	gs_tictactoe_reset(game);

	gs_tictactoe_space_state player = gs_tictactoe_space_o;
	bool playerWon = false;
	gs_tictactoe_space_state winner;	
	int playerRow, playerColumn;
	
	while (!playerWon)
	{
		drawBoard(game);

		cout << "Player " << player << "'s turn" << endl;
		cout << "Which row would you like to place your piece? ";
		cin >> playerRow;
		cout << "Which column would you like to place your piece? ";
		cin >> playerColumn;

		while (gs_tictactoe_getSpaceState(game, playerColumn, playerRow) == gs_tictactoe_space_invalid)
		{

		}
	}

	return 0;
}


//-----------------------------------------------------------------------------
