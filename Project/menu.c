#include <stdio.h>
#include <conio.h>

void menu()
{
    int i;
    char ch = 'y';
    printf("Menu: ");
    printf("\n");


    while (ch!='n')
    {
        printf(
            "\nStock Analyser"
            "\nPress"
            "\n1 - Overview of today\'s stock market"
            "\n2 - Analyse a stock"
            "\n3 - My stocks"
            "\n"
        );
        scanf("%d", &i);

        // switch (i)
        // {
        // case 1:
        //     overview();
        //     break;
        // case 2:
        //     analyse_stock();
        //     break;
        // case 3:
        //     my_stocks();
        
        // default:
        //     break;
        // }

        printf("\nDo you want to continue? (y/n)");
        scanf(" %c", &ch);
    }
}