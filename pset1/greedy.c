#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (int argc, string argv[])
{
  // узнаем необходимую сдачу  
  float change = 0;
  while (change <= 0 )  
  { printf ("What is your change? ");
    change = GetFloat ();
    change = roundf (change * 100);
  }
  // номиналы монет
  float quarters = 25; 
  float dimes = 10;
  float nickels = 5;
  float pennies = 1;
  // количество монет
  int quartersCount = 0;
  int dimesCount = 0;
  int nickelsCount = 0;
  int penniesCount = 0;
  
  while (change - quarters >= 0.00)
    {
      change = change - quarters;
      quartersCount++;
    }
    
  while (change - dimes >= 0.00)
    {
      change = change - dimes;
      dimesCount++;
    }
  while (change - nickels >= 0.00)
    {
      change = change - nickels;
      nickelsCount++;
    }
    while (change - pennies >= 0.00) 
    {
      change = change - pennies;
      penniesCount++;
    }
  printf ("quarters - %i coin(s)\n", quartersCount);
  printf ("dimes - %i coin(s)\n", dimesCount);
  printf ("nickels - %i coin(s)\n", nickelsCount);
  printf ("pennies - %i coin(s)\n", penniesCount);
  
  printf ("change - %f \n", change);
  
  printf ("%i coin(s)\n", quartersCount + dimesCount + nickelsCount + penniesCount);
}
