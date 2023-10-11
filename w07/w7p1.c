/*/////////////////////////////////////////////////////////////////////////
              Workshop - #7 (P1)
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
#define MULT_VALUE 5

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
  int maxMoves;
  int pathLength;
  int bombPlace[MAX_PATH];
  int treasPlace[MAX_PATH];
};

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

  return 0;
}
