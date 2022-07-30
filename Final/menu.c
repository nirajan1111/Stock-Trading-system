#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "find_all_stock_name.c"
#include "find_stock_information.c"


int choice;

void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}

int menu()
{
    int main_exit;
    Main_Menu:
    system("cls");
    printf("\t\t\t\t\xb2\xb2 Welcome to Stock Analyzer \xb2\xb2\n\n");
    choice_enter:
    printf("\n\n\n\t\t\t   \xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    // printf("\n\n\t\t1.Function1\n\t\t2.Function2\n\t\t3.Function3\n\t\t4.Function4\n\t\t5.Exit\n\n\n\n\n\t\t Enter your choice:");
    printf("\n");
    printf("\n\t\t1. Name of All Stocks");
    printf("\n\t\t2. Stock Information");
    printf("\n\t\t2.Function3");
    printf("\n\t\t2.Function4");
    printf("\n\t\t5.Exit");
    printf("\n\n\n\n\n\t\t Enter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    { 
    case 1:
        find_all_stock_name();

        printf("\n1. Goto main menu");
        printf("\n2. Exit");
        printf("\n-->");
        scanf("%d", &choice);
        if (choice == 1)
            goto Main_Menu;
        else if (choice == 2)
            goto End;

        break;

    case 2:
        find_stock_information();

        printf("\n1. Goto main menu");
        printf("\n2. Exit");
        printf("\n-->");
        scanf("%d", &choice);
        if (choice == 1)
            goto Main_Menu;
        else if (choice == 2)
            goto End;

        break;

    case 3:
        break;
    case 4:
        break;
    case 5:
        system("color 7");
        exit(1);
        break;

    default:
        printf("Invalid choice!");
        try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {
            system("cls");
            goto choice_enter;
        }

        else if (main_exit == 0)
        {
            return 2;
        }
        else
        { 
            printf("\nInvalid!");
            goto try;
        }
        system("cls");
        goto choice_enter;
    }
    system("cls");
    End:
    return 0;
}
