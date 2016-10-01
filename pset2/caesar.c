/**
  * caesar.c
  *
  * Andrey Prenko
  * andreyprenko@gmail.com
  *
  * problem set2 of CS50
  * problem caesar
  */

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc !=2) // check that two arguments entered
    {
    printf ("Usage: ./caeser key\n");    
    return 1;
    }
    int key = atoi(argv[1]); // initiating key
    if (key < 0) // key length check
    {
        return 1;
    }   
    string input_text = GetString(); // text input in the console

    for (int i = 0, n = strlen(input_text); i < n; i++) 
    {
        char letter = input_text[i];   
        if (isalpha(letter))
        {
            int ascii_step = 0;
            if (isupper(letter))
            {
                ascii_step = 65;
            }
            else
            {
                ascii_step = 97;
            }
            int result = (letter - ascii_step + key)%26 + ascii_step;
            
            printf("%c", result); // print out coded signs
        } 
        else 
        {
            printf("%c", letter); // print out the unencrypted signs
        }
    }
    return 0;
}
