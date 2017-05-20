//Given an amount of money from the user, calculates fewest number of coins that can be given as change
#include <stdio.h>
#include <math.h>

int main(void)
{
    //ask user for amount of money and store in variable
    printf("How much change is owed?\n");
    float money;
    scanf("%f", &money);
    
    //convert money into cents, then cast to int for rounding after division, and modulo operation
    money = round(money * 100);
    int change = money;
    
    //create variable to track number of coins, divide by 25, 10, and 5 to account for quarters, dimes, and nickels
    //use modulo operator after each division to track how much money remains
    int num_coins = change / 25;
    change %= 25;
    
    num_coins += change / 10;
    change %= 10;
    
    num_coins += change / 5;
    change %= 5;
    
    num_coins += change;
    //print result to screen
    printf("%d is the fewest coins that can be given!\n", num_coins);
}
