/*
takes a visa, mastercard, or amex credit card number 
as input from user, checks if number is mathematically valid.
if so, determines card type
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    //ask user for credit card number and store in a string
    printf("Enter a credit card number:\n");
    char* cc = NULL;
    int success;
    unsigned long n;
    success = getline(&cc, &n, stdin);
    //ensure user entered input
    if (success == -1)
    {
        printf("Must provide 13, 15, or 16 digit credit card number!\n");
        return 1;
    }
    //remove newline char
    int len = strlen(cc) - 1;
    cc[len] = '\0';
    //ensure input has correct length
    if (len != 13 && len != 15 && len != 16)
    {
        printf("Must provide 13, 15, or 16 digit credit card number!\n");
        free(cc);
        return 1;
    }
    //ensure input is all numeric
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(cc[i]))
        {
            printf("Must enter only numbers!\n");
            free(cc);
            return 1;
        }
    }
    //variable to keep track of total of calculations
    int total = 0;
    //starting with second to last digit, multiply every other digit by two, add those products' digits together
    for (int i = len - 2; i >= 0; i -= 2)
    {
        //convert char to int
        int tmp = cc[i] - '0';
        tmp *= 2;
        if (tmp < 10)
            total += tmp;
        else
        {
            tmp -= 10;
            total += 1 + tmp;
        }
    }
    //add remaining digits to total
    for (int i = len - 1; i >= 0; i -= 2)
    {
        //convert char to int
        total += (cc[i] - '0');
    }
    //if total's last digit is 0, number is valid
    if (total % 10 == 0)
    {
        //if 15 digits-amex
        if (len == 15)
        {
            printf("AMEX\n");
            free(cc);
            return 0;
        }
        //13 digits visa
        else if (len == 13)
        {
            printf("VISA\n");
            free(cc);
            return 0;
        }
        //16 digits could be visa or mastercard, visa always starts with 4, mastercard starts with 5
        else
        {
            if (cc[0] == '4')
            {
                printf("VISA\n");
                free(cc);
                return 0;
            }
            else
            {
                printf("MASTERCARD\n");
                free(cc);
                return 0;
            }
        }
    }
    //if last digit of total is not 0, not a valid card number
    else
    {
        printf("INVALID\n");
        free(cc);
        return 0;
    }
}
