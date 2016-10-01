/**
  * water.c
  *
  * Andrey Prenko
  * andreyprenko@gmail.com
  *
  * problem set1 of CS50
  * problem water
  */

#include <stdio.h>
#include <cs50.h>

int main (void)

{
    printf("How many minute(s) do you take a shower: ?\n"); //ask user for input
    int x = GetInt(); 
    int y = x * 12; // do the math
    
    printf("You use %i bottle(s) of water during %i minute(s) shower \n", y, x); //print result
}

