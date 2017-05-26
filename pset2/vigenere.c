/*an implementation of Vigenere's cipher, takes a word as a command
line argument to serve as the key, then prompts user for a string
to encode, which is then printed to the screen
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//prototype
int UpdateKey (int, int);

int main (int argc, char* argv[])
{
    //ensure correct usage
    if (argc != 2)
    {
        printf("Must supply a key at command line: single word, letters only!\n");
        return 1;
    }
    //iterate through key provided at command line
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        //if user entered any chars that are not letters, return error
        if (!isalpha(argv[1][i]))
        {
            printf("Must supply a key at command line: single word, letters only!\n");
            return 1;
        }
        //convert any lowercase letters to uppercase
        if (islower(argv[1][i]))
        {
            argv[1][i] = toupper(argv[1][i]);
        }
    }
    //get string from user
    printf("Enter a message...\n");
    char* s = NULL;
    unsigned long n;
    int success = getline(&s, &n, stdin);
    
    //return error if no input from user
    if (success == -1)
    {
        printf("Must enter a message!\n");
        return 1;
    }
    
    //iterate through each char of sting provided by user
    for (int i = 0, j = 0, l = strlen(s); i < l; i++)
    {
        //if char is a letter, encode based on key
        if (isalpha(s[i]))
        {
            //if current letter is lowercase
            if (islower(s[i]))
            {
                //add key to char if it will still be a lowercase letter and print to screen
                if ((s[i] + (argv[1][j] - 65)) < 123)
                {
                    printf("%c", (s[i] + (argv[1][j] - 65)));
                    //move key to next letter
                    j = UpdateKey(j, strlen(argv[1]));
                }
                //if key plus char > 122, need to modulo 26 to stay in alphabet
                else
                {
                    printf("%c", ((((s[i] - 96) + (argv[1][j] - 65)) % 26) + 96));
                    //move key to next letter
                    j = UpdateKey(j, strlen(argv[1]));
                }
            }
            //else if uppercase letter
            else
            {
                //add key to char if it will still be an uppercase letter and print to screen
                if ((s[i] + (argv[1][j] - 65) < 91))
                {
                    printf("%c", (s[i] + (argv[1][j] - 65)));
                    //move key to next letter
                    j = UpdateKey(j, strlen(argv[1]));
                }
                //if key plus char > 90, need to modulo 26 to stay in alphabet
                else
                {
                    printf("%c", ((((s[i] - 64) + (argv[1][j] - 65)) % 26) + 64));
                    //move key to next letter
                    j = UpdateKey(j, strlen(argv[1]));
                }
            }
        }
        //if char is not a letter, print as is
        else
        {
            printf("%c", s[i]);
        }
    }
    //after entire message is encoded, print newline
    printf("\n");
}
//function to track which letter of the key to use, x tracks the current letter, y is the length of the key
int UpdateKey (int x, int y)
{
    //move to next letter of key
    x = x + 1;
    
    //if end of key is reached, return to the beginning
    if (x == y)
    {
        x = 0;
        return x;
    }
    //else return next letter
    else
    {
        return x;
    }
}
