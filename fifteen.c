/*  an implementation of the game of fifteen
**  user enters an int for dimensions of board
**  user enters number of tile to be moved
**  if tile is near the empty space, it is moved there
**  game is won when tiles are in numerical order
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// global variable for game board
int board[10][10];

// global variable for dimensions of board
int d;

// prototypes
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(void)
{
    //ask user for dimensions of board
    printf("What size game board?\n");
    scanf("%d", &d);
    
    //check if value is within limits
    if (d < 3 || d > 10)
    {
        printf("Size must be greater than 2 and less than 11!\n");
        return 1;
    }
    
    //greet user
    printf("\nTHE GAME OF FIFTEEN\nenter 0 to quit\n");
    
    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("Congratulations!!!\n");
            break;
        }

        // prompt user for move
        printf("Tile to move: ");
        int tile;
        scanf("%d", &tile);
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
        }
    }

    // game has ended
    return 0;
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
void init(void)
{
    for (int i = 0, p = (d * d - 1); i < d; i++)
    {
        for (int j = 0; j < d; j++, p--)
        {
            board[i][j] = p;
        }
    }
    //if even number of tiles, swap 1 and 2
    if ((d % 2) == 0)
    {
        board[d - 1][d - 2] = 2;
        board[d - 1][d - 3] = 1;
    }
}

//prints the board to the screen
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        printf("\n");
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                printf("    ");
            }
            else if (board[i][j] > 9)
            {
                printf("%i  ", board[i][j]);
            }
            else
            {
                printf(" %i  ", board[i][j]);
            }
        }
    }
    printf("\n\n");
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                if (i != 0)
                {
                    if (board[i -1][j] == 0)
                    {
                        board[i - 1][j] = board[i][j];
                        board[i][j] = 0;
                        return true;
                    }
                }
                if (i != (d - 1))
                {
                    if (board[i + 1][j] == 0)
                    {
                        board[i + 1][j] = board[i][j];
                        board[i][j] = 0;
                        return true;
                    }
                }
                if (j != 0)
                {
                    if (board[i][j - 1] == 0)
                    {
                        board[i][j - 1] = board[i][j];
                        board[i][j] = 0;
                        return true;
                    }
                }
                if ( j != (d - 1))
                {
                    if (board[i][j + 1] == 0)
                    {
                        board[i][j + 1] = board[i][j];
                        board[i][j] = 0;
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}

//checks if board is in winning configuration, returns true if so
bool won(void)
{
    for (int i = 0, p = 1; i < d; i++)
    {
        for (int j = 0; j < d; j++, p++)
        {
            if (board [i][j] != p)
            {
                if ((i == (d - 1)) && (j == (d - 1)))
                {
                    return true;
                }
                return false;
            }
        }
    }
    return false;
}
