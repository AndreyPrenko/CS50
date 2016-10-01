/**
  * initials.c
  *
  * Andrey Prenko
  * andreyprenko@gmail.com
  *
  * problem set2 of CS50
  * problem initials
  */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
   
    string name = GetString ();
    
    if (name != NULL) //check the input is not empty
    {
        for (int i = 0, n = strlen(name); i < n; i++) //iterate entered characters
        {
            if (i == 0 || name[i-1] == ' ')  
            {
            printf("%c", toupper (name[i])); // print the first character and the character after the space
            }
        }
    }
    printf("\n");
}
  