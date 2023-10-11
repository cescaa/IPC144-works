/*/////////////////////////////////////////////////////////////////////////
							Workshop - #7 (P2)
Full Name  : Anna Francesca Dela Cruz
Student ID#: 123123150
Email      : afgdela-cruz@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MIN_PATH 10
#define MAX_PATH 70
#define MIN_LIVES 1
#define MAX_LIVES 10
#define MULT_VALUE 5 // DON'T FORGET THIS!!!!!!!!!!!!!!

#include <stdio.h>

struct PlayerInfo
{
	int numLives;
	char charSymbol;
	int numTreas;
	int movesHistory[MAX_PATH];
};

struct GameInfo
{
	int maxMoves; // max num of moves + counter
	int pathLength;
	int bombPlace[MAX_PATH];
	int treasPlace[MAX_PATH];
};

// function prototypes
int makeRulers(int pathLength);
int promptPlayer(int pathLength);
int findResult(int nextMove, int bombPlace[], int treasPlace[]);
int makeScoreboard(int lives, int treas, int moves);
int resultMsg(int result);
int printSymbol(char charSymbol, int nextMove, int pathLength);
int printPath(char dashArr[], int pathLength);

int main()
{
	struct PlayerInfo player1;
	struct GameInfo game1;

	printf("================================\n");
	printf("         Treasure Hunt!\n");
	printf("================================\n\n");

	////////////// PLAYER Configuration //////////////
	printf("PLAYER Configuration\n--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player1.charSymbol);
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &player1.numLives);
		if (!(player1.numLives >= MIN_LIVES && player1.numLives <= MAX_LIVES))
		{
			printf("     Must be between 1 and 10!\n");
		}
	} while (!(player1.numLives >= MIN_LIVES && player1.numLives <= MAX_LIVES));

	// reset player's moves from previous game
	int i;
	for (i = 0; i < MAX_PATH; i++)
	{
		player1.movesHistory[i] = 0;
	}
	printf("Player configuration set-up is complete\n\n");

	// define treasure tracker
	player1.numTreas = 0;

	////////////// GAME Configuration //////////////
	printf("GAME Configuration\n------------------\n");
	do // get path length
	{
		printf("Set the path length (a multiple of %d between %d-%d): ", MULT_VALUE, MIN_PATH, MAX_PATH);
		scanf("%d", &game1.pathLength);
		if (!(game1.pathLength >= MIN_PATH && game1.pathLength <= MAX_PATH && game1.pathLength % MULT_VALUE == 0))
		{
			printf("     Must be a multiple of %d and between %d-%d!!!\n", MULT_VALUE, MIN_PATH, MAX_PATH);
		}
	} while (!(game1.pathLength >= MIN_PATH && game1.pathLength <= MAX_PATH && game1.pathLength % MULT_VALUE == 0));

	// 75% of the game’s path length
	int pathLength75 = (double)game1.pathLength * 0.75;

	do // get limit of moves
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game1.maxMoves);
		if (!(game1.maxMoves >= player1.numLives && game1.maxMoves <= pathLength75))
		{
			printf("    Value must be between %d and %d\n", player1.numLives, pathLength75);
		}
	} while (!(game1.maxMoves >= player1.numLives && game1.maxMoves <= pathLength75));
	printf("\n");

	// BOMB Placement
	printf("BOMB Placement\n--------------\n");
	printf("Enter the bomb positions in sets of %d where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", MULT_VALUE, game1.pathLength);

	int rows = game1.pathLength / MULT_VALUE;
	int rowArr[MULT_VALUE];
	int posCounter = 0;
	int idx = 0;

	int j;
	for (j = 0; j < rows; j++)
	{
		printf("   Positions [%2d-%2d]: ", posCounter + 1, posCounter + MULT_VALUE);
		int z; // get bomb placements
		for (z = 0; z < MULT_VALUE; z++)
		{
			scanf("%d", &rowArr[z]);
			game1.bombPlace[idx] = rowArr[z];
			idx++;
		}
		posCounter += MULT_VALUE;
	}
	posCounter = 0;
	idx = 0;
	printf("BOMB placement set\n\n");

	// TREASURE Placement
	printf("TREASURE Placement\n------------------\n");
	printf("Enter the treasure placements in sets of %d where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", MULT_VALUE, game1.pathLength);

	int k;
	for (k = 0; k < rows; k++)
	{
		printf("   Positions [%2d-%2d]: ", posCounter + 1, posCounter + MULT_VALUE);
		int y; // get treasure placements
		for (y = 0; y < MULT_VALUE; y++)
		{
			scanf("%d", &rowArr[y]);
			game1.treasPlace[idx] = rowArr[y];
			idx++;
		}
		posCounter += MULT_VALUE;
	}
	posCounter = 0;
	printf("TREASURE placement set\n\n");

	////////////// print SUMMARY //////////////
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\nTREASURE HUNT Configuration Settings\n------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player1.charSymbol);
	printf("   Lives      : %d\n", player1.numLives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");

	printf("Game:\n");
	printf("   Path Length: %d\n", game1.pathLength);
	printf("   Bombs      : ");
	int p; // ptint array
	for (p = 0; p < game1.pathLength; p++)
	{
		printf("%d", game1.bombPlace[p]);
	}
	printf("\n   Treasure   : ");
	int q; // print array
	for (q = 0; q < game1.pathLength; q++)
	{
		printf("%d", game1.treasPlace[q]);
	}
	printf("\n\n====================================\n~ Get ready to play TREASURE HUNT! ~\n====================================\n\n");

	////////////////////////////////////////// PART 2 //////////////////////////////////////////

	// make path and store in dashArr[]
	printf("  ");
	char dashArr[game1.pathLength];
	int d;
	for (d = 0; d < game1.pathLength; d++)
	{
		dashArr[d] = '-';
		printf("%c", dashArr[d]);
	}

	do // do until user loses all lives OR moves
	{
		makeRulers(game1.pathLength);																				// make rulers
		makeScoreboard(player1.numLives, player1.numTreas, game1.maxMoves); // make scoreboard
		int nextMove = promptPlayer(game1.pathLength);											// get and validate user's next move

		// update path, scoreboard, and move history
		if (player1.movesHistory[nextMove - 1] == 0) // if not visited
		{
			// assign a number according to result
			int result = findResult(nextMove, game1.bombPlace, game1.treasPlace);
			resultMsg(result); // display message according to result

			if (result == 1) // if bomb found
			{
				dashArr[nextMove - 1] = '!';						// update path
				player1.numLives--;											// update num of lives
				game1.maxMoves--;												// update num of moves left
				player1.movesHistory[nextMove - 1] = 1; // record history of move
			}
			else if (result == 2) // if treasure found
			{
				dashArr[nextMove - 1] = '$';
				player1.numTreas++; // update num of treasures
				game1.maxMoves--;
				player1.movesHistory[nextMove - 1] = 1;
			}
			else if (result == 3) // if both found
			{
				dashArr[nextMove - 1] = '&';
				player1.numLives--;
				player1.numTreas++;
				game1.maxMoves--;
				player1.movesHistory[nextMove - 1] = 1;
			}
			else if (result == 4) // if none found
			{
				dashArr[nextMove - 1] = '.';
				game1.maxMoves--;
				player1.movesHistory[nextMove - 1] = 1;
			}
		}
		else // if move was picked already, display according message
		{
			int result = 5;
			resultMsg(result);
		}

		if (player1.numLives == 0 || game1.maxMoves == 0)
		{
			printf("No more LIVES remaining!\n\n");
		}

		// display player's symbol above path
		printSymbol(player1.charSymbol, nextMove, game1.pathLength);
		printPath(dashArr, game1.pathLength);
	} while (!(player1.numLives == 0 || game1.maxMoves == 0));

	makeRulers(game1.pathLength);
	makeScoreboard(player1.numLives, player1.numTreas, game1.maxMoves);

	printf("\n##################\n#   Game over!   #\n##################\n\n");
	printf("You should play again and try to beat your score!\n");

	return 0;
}

////////////// FUNCTIONS //////////////

// make rulers
int makeRulers(int pathLength)
{
	printf("\n");
	printf("  ");
	// major
	int i;
	for (i = 0; i < pathLength; i++)
	{
		if ((i + 1) % 10 == 0)
		{
			printf("%d", (i / 10) + 1);
		}
		else
		{
			printf("|");
		}
	}
	printf("\n");

	// minor
	printf("  ");
	int j;
	int m = 0;
	for (j = 0; j < pathLength; j++)
	{
		if ((m + 1) == 10)
		{
			m = 0;
			printf("%d", m);
		}
		else
		{
			printf("%d", m + 1);
			m++;
		}
	}
	printf("\n");
	return 0;
}

// prompt player
int promptPlayer(int pathLength)
{
	int nextMove;
	do
	{
		printf("Next Move [1-%d]: ", pathLength);
		scanf("%d", &nextMove);
		if (!(nextMove >= 1 && nextMove <= pathLength))
		{
			printf("  Out of Range!!!\n");
		}
	} while (!(nextMove >= 1 && nextMove <= pathLength));

	return nextMove;
}

// assign number to each result after user picks move
int findResult(int nextMove, int bombPlace[], int treasPlace[])
{
	if (bombPlace[nextMove - 1] == 1 && treasPlace[nextMove - 1] == 0)
	{
		return 1; // if bomb found
	}
	else if (bombPlace[nextMove - 1] == 0 && treasPlace[nextMove - 1] == 1)
	{
		return 2; // if treasure found
	}
	else if (bombPlace[nextMove - 1] == 1 && treasPlace[nextMove - 1] == 1)
	{
		return 3; // if both found
	}
	else // if (bombPlace[nextMove - 1] == 0 && treasPlace[nextMove - 1] == 0)
	{
		return 4; // if none found
	}
}

// make scoreboard
int makeScoreboard(int lives, int treas, int moves)
{
	printf("+---------------------------------------------------+\n");
	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", lives, treas, moves);
	printf("+---------------------------------------------------+\n");
	return 0;
}

// display result message
int resultMsg(int result)
{
	if (result == 1)
	{ // found bomb
		printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
	}
	else if (result == 2)
	{
		// found treasure
		printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
	}
	else if (result == 3)
	{
		// found both
		printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
		printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
	}
	else if (result == 4)
	{ // found none
		printf("\n===============> [.] ...Nothing found here... [.]\n\n");
	}
	else // if move picked already
	{
		printf("\n===============> Dope! You've been here before!\n\n");
	}
	return 0;
}

// print symbol above path, based on user's move
int printSymbol(char charSymbol, int nextMove, int pathLength)
{
	printf("  ");
	int i;
	for (i = 0; i < pathLength; i++)
	{
		if (i == nextMove - 1)
		{
			printf("%c", charSymbol);
			i = pathLength;
		}
		else
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

// print path ----------
int printPath(char dashArr[], int pathLength)
{
	printf("  ");
	int i;
	for (i = 0; i < pathLength; i++)
	{
		printf("%c", dashArr[i]);
	}
	return 0;
}
