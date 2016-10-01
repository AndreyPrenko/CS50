/**
  * mario.c
  *
  * Andrey Prenko
  * andreyprenko@gmail.com
  *
  * problem set1 of CS50
  * problem mario
  */

#include <stdio.h>
#include <cs50.h>

int main (void)

{
  int h = 0;      
  printf ("Enter height number 1 - 23: ?\n"); //ask for a number from 1 to 23 
    do
    {
        printf ("height: %i\n", h); // print the number of rows (floors)
        h = GetInt(); //expect the number of rows (floors)
        if (h == 0) {  
            return 0;
        }
    }
    while ( h < 1 || h > 23); // a necessary condition for the number of rows (floors)
    
    int w = h + 1;  // calculation width
 
  for (int i = 1; i <= h; i++) // calculation  " " and "#"
  {
    int space = (w - 2) - i + 1;
    int hash = (2) + i - 1;
    while (space > 0 )
   {
    printf (" ");  // printing " "
    space--;
   }
   while (hash > 0 )
   {
    printf ("#");  // printing "#"
    hash--;
   }
   printf ("\n");
   
  }
}