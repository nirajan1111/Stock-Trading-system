#include <stdio.h>
#include <conio.h>

// PROGRAM TO CHANGE CASE TO UPPERCASE

void to_upper_case(char stock_code[])
{
    int i=0;
    while (stock_code[i]!='\0')
    {
        if (stock_code[i]>='a' && stock_code[i]<='z')
        {
            stock_code[i]-=32;
        }
        i++;
    }
}