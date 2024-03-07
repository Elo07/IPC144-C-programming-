/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  :Ehimwenma Larry Okuonghae
Student ID#:145203238
Email      :elokuonghae@myseneca.ca
Section    :NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_PATH_LENGTH 70

#include <stdio.h>

struct PlayerInfo
{

  int lives;
  char symbol;
  int treasures;
  int history[MAX_PATH_LENGTH];
};

struct GameInfo
{
  int move;
  int pathLength;
  int bombPosition[MAX_PATH_LENGTH];
  int treasurePosition[MAX_PATH_LENGTH];
};

int main(void)
{
 
  const int MAX_LIVES = 10;
  const int MULTIPLE = 5;
  const int MIN_PATH_LENGTH = 10;
  int valid, i, j;
  struct PlayerInfo player = {0};
  struct GameInfo game = {0};
  int nextMove = -1;
  char board[MAX_PATH_LENGTH];

  printf("================================\n");
  printf("         Treasure Hunt!\n");
  printf("================================\n\n");

  printf("PLAYER Configuration\n");
  printf("--------------------\n");
  printf("Enter a single character to represent the player: ");
  scanf(" %c", &player.symbol);

  
  do
  {
    valid = 1;
    printf("Set the number of lives: ");
    scanf("%d", &player.lives);

    if ((player.lives < (MAX_LIVES - MAX_LIVES + 1)) || (player.lives > MAX_LIVES))
    {
      printf("     Must be between 1 and 10!\n");
      valid = 0;
    }
  } while (!valid);
  printf("Player configuration set-up is complete\n\n");

  
  for (i = 0; i < MAX_PATH_LENGTH; i++)
  {
    player.history[i] = -1;
  }

  printf("GAME Configuration\n");
  printf("------------------\n");
  do
  {
    valid = 1;
    printf("Set the path length (a multiple of 5 between 10-70): ");
    scanf("%d", &game.pathLength);
    if (game.pathLength % MULTIPLE != 0 || game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH)
    {
      printf("     Must be a multiple of 5 and between 10-70!!!\n");
      valid = 0;
    }
  } while (!valid);

  do
  {
    valid = 1;
    printf("Set the limit for number of moves allowed: ");
    scanf("%d", &game.move);
    if (game.move < player.lives || (game.move > (int)(0.75 * game.pathLength)))
    {
      printf("    Value must be between %d and %d\n", player.lives, (int)(0.75 * game.pathLength));
      valid = 0;
    }

  } while (!valid);
  printf("\n");

  printf("BOMB Placement\n");
  printf("--------------\n");
  printf("Enter the bomb positions in sets of 5 where a value\n");
  printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
  printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
  for (i = 0; i < game.pathLength; i += MULTIPLE)
  {
    printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
    for (j = i; j < i + MULTIPLE; j++)
    {
      scanf("%d", &game.bombPosition[j]);
    }
  }
  printf("BOMB placement set\n\n");
  printf("TREASURE Placement\n");
  printf("------------------\n");

  printf("Enter the treasure placements in sets of 5 where a value\n");
  printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
  printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
  for (i = 0; i < game.pathLength; i += MULTIPLE)
  {
    printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
    for (j = i; j < i + MULTIPLE; j++)
    {
      scanf("%d", &game.treasurePosition[j]);
    }
  }
  printf("TREASURE placement set\n");
  printf("\n");
  printf("GAME configuration set-up is complete...\n");
  printf("\n");

  printf("------------------------------------\n");
  printf("TREASURE HUNT Configuration Settings\n");
  printf("------------------------------------\n");
  printf("Player:\n");
  printf("   Symbol     : %c\n", player.symbol);
  printf("   Lives      : %d\n", player.lives);
  printf("   Treasure   : [ready for gameplay]\n");
  printf("   History    : [ready for gameplay]\n\n");

  printf("Game:\n");
  printf("   Path Length: %d\n", game.pathLength);
  printf("   Bombs      : ");
  for (i = 0; i < game.pathLength; i++)
  {
    printf("%d", game.bombPosition[i]);
  }
  printf("\n");
  printf("   Treasure   : ");
  for (i = 0; i < game.pathLength; i++)
  {
    printf("%d", game.treasurePosition[i]);
  }
  printf("\n\n");

  printf("====================================\n");
  printf("~ Get ready to play TREASURE HUNT! ~\n");
  printf("====================================\n");

  for (i = 0; i < game.pathLength; i++)
  {
    board[i] = '-';
  }

  while (player.lives > 0 && game.move > 0)
  {

    valid = 1;
    if (nextMove != -1)
    {
      printf("\n  ");
      for (i = 0; i < game.pathLength && valid != 0; i++)
      {
        if (i == nextMove - 1)
        {
          printf("%c", player.symbol);
          valid = 0;
        }
        else
        {
          printf(" ");
        }
      }
    }
    printf("\n  ");
    for (i = 0; i < game.pathLength; i++)
    {
      printf("%c", board[i]);
    }
    printf("\n  ");
    for (i = 0; i < game.pathLength; i++)
    {
      if ((i + 1) % 10 != 0)
      {
        printf("|");
      }
      else
      {
        printf("%d", (i + 1) / 10);
      }
    }
    printf("\n  ");
    for (i = 0; i < game.pathLength; i++)
    {
      printf("%d", (i + 1) % 10);
    }

    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasures, game.move);
    printf("+---------------------------------------------------+\n");
    printf("Next Move [1-%d]: ", game.pathLength);
    scanf("%d", &nextMove);

    while (nextMove < 1 || nextMove > game.pathLength)
    {
      printf("  Out of Range!!!\n");
      printf("Next Move [1-%d]: ", game.pathLength);
      scanf("%d", &nextMove);
    }
    printf("\n");

    if (player.history[nextMove - 1] == 1)
    {
      printf("===============> Dope! You've been here before!\n");
    }
    else
    {
      player.history[nextMove - 1] = 1;
      game.move -= 1;
      if (game.bombPosition[nextMove - 1] == 1 && game.treasurePosition[nextMove - 1] == 1)
      {
        player.lives -= 1;
        player.treasures += 1;
        printf("===============> [&] !!! BOOOOOM !!! [&]\n");
        printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
        board[nextMove - 1] = '&';
      }
      else if (game.bombPosition[nextMove - 1] == 1)
      {
        player.lives -= 1;
        printf("===============> [!] !!! BOOOOOM !!! [!]\n");
        board[nextMove - 1] = '!';
      }
      else if (game.treasurePosition[nextMove - 1] == 1)
      {
        player.treasures += 1;
        printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
        board[nextMove - 1] = '$';
      }
      else
      {
        printf("===============> [.] ...Nothing found here... [.]\n");
        board[nextMove - 1] = '.';
      }
    }
  }

  printf("\nNo more LIVES remaining!\n");
  printf("\n  ");
  valid = 1;
  for (i = 0; i < game.pathLength && valid != 0; i++)
  {
    if (i == nextMove - 1)
    {
      printf("%c", player.symbol);
      valid = 0;
    }
    else
    {
      printf(" ");
    }
  }
  printf("\n  ");
  for (i = 0; i < game.pathLength; i++)
  {
    printf("%c", board[i]);
  }
  printf("\n  ");

  for (i = 0; i < game.pathLength; i++)
  {
    if ((i + 1) % 10 != 0)
    {
      printf("|");
    }
    else
    {
      printf("%d", (i + 1) / 10);
    }
  }
  printf("\n  ");

  for (i = 0; i < game.pathLength; i++)
  {
    printf("%d", (i + 1) % 10);
  }
  printf("\n+---------------------------------------------------+\n");
  printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasures, game.move);
  printf("+---------------------------------------------------+\n");
  printf("\n##################\n");
  printf("#   Game over!   #\n");
  printf("##################\n\n");
  printf("You should play again and try to beat your score!\n");
  return 0;
}