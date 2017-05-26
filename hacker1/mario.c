//takes an int less than 24 to serve as the height of two half-pyramids to be printed to the screen

#include <stdio.h>

int main(void)
{
    //create variable to store height of pyramids
    int height;
    
    //ask user for value and store in height variable
    printf("Height: ");
    scanf("%d", &height);
    
    //ensure user's input is within range of 1-23
    if (height < 1 || height > 23)
    {
        printf("Height must be within range of 1-23!\n");
        return 1;
    }
    
    //loop for each line
    for (int row = 0; row < height; row++)
    {
        //loop to print spaces before first pyramid
        for (int i = 0; i < (height - (row + 1)); i++)
        {
            printf(" ");
        }
        
        //loop to print first pyramid
        for (int i = 0; i < (row + 1); i++)
        {
            printf("#");
        }
        
        //print spaces between pyramids
        printf("  ");
        
        //loop to print second pyramid
        for (int i = 0; i < (row + 1); i++)
        {
            printf("#");
        }
        
        //loop to print spaces after second pyramid
        for (int i = 0; i < (height - (row + 1)); i++)
        {
            printf(" ");
        }
        
        //print newline before advancing to next row
        printf("\n");
    }
}
