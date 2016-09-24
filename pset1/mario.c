#include <stdio.h>
#include <cs50.h>

int main (void)

{
  int h = 0; //задаем переменную высоты (этажности)
  while ( h < 1 || h > 23)
  {
    printf ("Enter height number 1 - 23: ?\n"); //запрашиваем число от 1 до 23
    h = GetInt(); //ожидаем ввода кол-во рядов (этажей)
  }
  
  int w = h + 1;
  printf ("height = %i block(s), width = %i block(s)\n", h, w ); 
  
  for (int i = 1; i <= h; i++) 
  {
    int space = (w - 2) - i + 1;
    int hash = (2) + i - 1;
    while (space > 0 )
   {
    printf (" ");
    space--;
   }
   while (hash > 0 )
   {
    printf ("#");
    hash--;
   }
   printf ("\n");
   
  }
}

