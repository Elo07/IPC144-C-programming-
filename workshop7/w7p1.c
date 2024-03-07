/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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

#define MAXIMUM_PATH_LENGTH 70

#include <stdio.h>

struct PlayerInfo
{
    int lives;
    char playerCharacter;
    int treasureCount;
    int past_position_history[MAXIMUM_PATH_LENGTH];
};

struct GameInfo
{
    int moves;
    int pathLength;
    int bombPosition[MAXIMUM_PATH_LENGTH];
    int treasurePosition[MAXIMUM_PATH_LENGTH];
};



int main(void)
{
    const int MAXIMUM_LIVES = 10;
    const int MINIMUM_PATH_LENGTH = 10;
    const int MINIMUM_LIVES = 1;
    const int MULTIPLE = 5;
    int i, j, k;

    struct PlayerInfo player; 
    struct GameInfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playerCharacter);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        if (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }
           
    } while (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES);

    printf("Player configuration set-up is complete\n");
    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);

        if ((game.pathLength < MINIMUM_PATH_LENGTH || game.pathLength > MAXIMUM_PATH_LENGTH)|| (game.pathLength % MULTIPLE != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
        
    } while ((game.pathLength < MINIMUM_PATH_LENGTH || game.pathLength > MAXIMUM_PATH_LENGTH)|| (game.pathLength % MULTIPLE != 0));

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);

        if (game.moves < player.lives || game.moves > (int)(game.pathLength * 0.75))
        {
            printf("    Value must be between %d and %d\n", player.lives, (int)(game.pathLength * 0.75));
        }
        
    } while (game.moves < player.lives || game.moves > (int)(game.pathLength * 0.75));
    printf("\n");

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    for (i = 0; i < game.pathLength; i+=5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombPosition[i], &game.bombPosition[i + 1], &game.bombPosition[i + 2], &game.bombPosition[i + 3], &game.bombPosition[i + 4]);
    };
    
    printf("BOMB placement set\n");
    printf("\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    for (i = 0; i < game.pathLength; i+=5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasurePosition[i], &game.treasurePosition[i + 1], &game.treasurePosition[i + 2], &game.treasurePosition[i + 3], &game.treasurePosition[i + 4]);
    };
    
    printf("TREASURE placement set\n");
    printf("\n");

    printf("GAME configuration set-up is complete...\n");
    printf("\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.playerCharacter);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (j = 0; j < game.pathLength; j++)
    {
        printf("%d", game.bombPosition[j]);
    }
    printf("\n");
    
    printf("   Treasure   : ");
    for (k = 0; k < game.pathLength; k++)
    {
        printf("%d", game.treasurePosition[k]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    printf("\n");    

    return 0;
}
