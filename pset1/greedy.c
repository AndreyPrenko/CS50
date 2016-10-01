  /**
  * greedy.c
  *
  * Andrey Prenko
  * andreyprenko@gmail.com
  *
  * problem set1 of CS50
  * problem greedy
  */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (int argc, string argv[])
{
  // learn needed number 
  float change = 0;
  while (change <= 0 )  
  { printf ("What is your change? ");
    change = GetFloat ();
    change = roundf (change * 100);
  }
  // nominal values coins
  float quarters = 25; 
  float dimes = 10;
  float nickels = 5;
  float pennies = 1;
  // amount of coins
  int quartersCount = 0;
  int dimesCount = 0;
  int nickelsCount = 0;
  int penniesCount = 0;
  
  while (change - quarters >= 0.00) // amount of coins quarters
    {
      change = change - quarters;
      quartersCount++;
    }
    
  while (change - dimes >= 0.00) // amount of coins dimes
    {
      change = change - dimes;
      dimesCount++;
    }
  while (change - nickels >= 0.00) // amount of coins nickels
    {
      change = change - nickels;
      nickelsCount++;
    }
    while (change - pennies >= 0.00)  // amount of coins pennies
    {
      change = change - pennies;
      penniesCount++;
    }

  printf ("%i\n", quartersCount + dimesCount + nickelsCount + penniesCount); //output of results 
}
