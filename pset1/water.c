#include <stdio.h>

/*
    Given that a shower uses 192 ounces of water per minute, and that typical bottled water is 16 ounces
    per bottle, a shower uses 12 bottles of water per minute.  This program asks the user how long of
    a shower they are taking in minutes, and will calculate how many bottles of water are used
    
*/

int main(void)
{
    //get value from user
    printf("How many minutes is your shower?\n");
    int x;
    scanf("%d", &x);
    //calculate number of bottles and output
    x = (x * 192) / 16;
    printf("You used %d bottles of water!\n", x);
}
