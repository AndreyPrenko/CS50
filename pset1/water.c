#include <stdio.h>
#include <cs50.h>

int main (void)

{
    printf("How many minute(s) do you take a shower: ?\n");
    int x = GetInt(); //вводим кол-во минут
    int y = x * 12;
    
    printf("You use %i bottle(s) of water during %i minute(s) shower \n", y, x);
}
