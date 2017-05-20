//Prints a staircase to the screen based on user's input
#include <stdio.h>

int main(void)
{
    //create variable for height and ask user for input
    int height = 0;
    printf("Enter height of stairs:\n");
    scanf("%d", &height);
    
    //ensure user's input is within limits
    if (height < 1 || height > 24)
    {
        printf("Height must be greater than 0 and less than 24!\n");
        return 1;
    }
    //print stairs to screen
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < (height - i); j++)
        {
            printf(" ");
        }
        for (int k = -2; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}
