/*
An implementation of Caesar's cipher, requires an integer as a command line
argument to serve as the key. Then prompts user for a string and returns
the encoded string based on the key provided.
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char* argv[])
{
    //ensure user provided a key at command line
    if (argc != 2)
    {
        printf("Must enter a positive integer on command line for key!\n");
        return 1;
    }
    
    //store key in a variable
    int k = atoi(argv[1]);
    
    //take string from user to encode
    char* s = NULL;
    unsigned long n;
    printf("Enter a message...\n");
    int success;
    success = getline(&s, &n, stdin);
    
    //ensure user provided input
    if (success == -1)
    {
        printf("Must enter a message to encode!\n");
        return 1;
    }
    
    //iterate through each char of the string
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        //if char is a letter, change to ciphertext based on key, using ascii values and print to screen
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
            {
                if ((s[i] + k) < 123)
                {
                    printf("%c", (s[i] + k));
                }
                else
                {
                    printf("%c", (((s[i] - 97) + k) % 26) + 97);
                }
            }
            else
            {
                if ((s[i] + k) < 91)
                {
                    printf("%c", ((s[i] + k)));
                }
                else
                {
                    printf("%c", (((s[i] - 65) + k) % 26) + 65);
                }
            }
        }
        //else if char is not a letter, print to screen as is
        else
        {
            printf("%c", s[i]);
        }
    }
    //print newline once string is complete
    printf("\n");
    return 0;
}
