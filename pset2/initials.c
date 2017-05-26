//Takes a users name and returns their initials in capital letters

#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    //ask user to enter a name
    printf("What is your name?\n");
    char* name;
    unsigned long n;
    int success = getline(&name, &n, stdin);
    
    //ensure user entered a name
    if (success == -1)
    {
        printf("Must enter a name!\n");
        return 1;
    }
    
    //print first char as uppercase
    printf("%c", toupper(name[0]));
    
    //iterate through rest of string
    for (int i = 1, l = strlen(name); i < l; i++)
    {
        //if space character is reached, print the next char as capital letter
        if (name[i] == 32)
        {
            printf("%c", toupper(name[i +1]));
        }
    }
    
    //print newline after last initial
    printf("\n");
    return 0;
}
