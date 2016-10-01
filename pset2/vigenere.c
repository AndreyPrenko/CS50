/**
  * vigenere.c
  *
  * Andrey Prenko
  * andreyprenko@gmail.com
  *
  * problem set2 of CS50
  * problem vigenere
  */

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc !=2) // check the presence of two arguments
    {
    printf ("Usage: ./vigenere key\n"); // run the program from the key input
    return 1;
    }
    string key = argv[1]; // key value
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        char key_letter = key[i];
        if (!isalpha(key_letter))
        {
            printf ("rejects \"%s\" as keyword\n", key);
            return 1;
        }   
    }
    string input_text = GetString(); // input encoded by text in the console
    char output_text [strlen(input_text)];
    for (int i = 0, j = 0, n = strlen(input_text), m = strlen(key); i < n; i++)
    {
        char letter = input_text[i];   
        if (isalpha(letter))
        {
            int ascii_step = 0;
            if (isupper(letter)) //check register letters entered text
            {
                ascii_step = 65;
            }
            else
            {
                ascii_step = 97;
            }
            char key_letter = key[j%m];
            j++;
            int ascii_step_key = 0;
            if (isupper(key_letter)) //check register key letters
            {
                ascii_step_key = 65;
            }
            else
            {
                ascii_step_key = 97;
            }
            int result = (letter - ascii_step + key_letter - ascii_step_key)%26 + ascii_step;
            output_text [i] = result;
        } 
        else 
        {
            output_text [i] = letter;
        }
    }
    
    printf ("encrypts \"%s\" as \"%s\" using \"%s\" as keyword\n", input_text, output_text, key); // print result
    return 0;
}
