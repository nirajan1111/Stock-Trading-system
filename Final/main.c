#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menu.c"

int choice;

int main()
{
    int main_exit;
    int i, c;
    char pass[10], password[10] = "codewithc";
main:
    system("cls");
    system("color 9");
    printf("\n\n\t\tEnter the password to login: ");
    scanf("%s", pass);
    if (strcmp(pass, password) == 0)
    {
        printf("\n\nPassword Match!\nLOADING");
        for (i = 0; i <= 6; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        c = menu();
        if (c == 2)
            goto main;
    }
    else
    {
        printf("\n\nWrong password!!\a\a\a");
    login_try:
        printf("\nEnter 1 to try again and 0 to exit: ");
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {
            system("cls");
            goto main;
        }
        else if (main_exit == 0)
        {
            system("color 7");
            system("cls");
            exit(1);
        }
        else
        {
            printf("\nInvalid!");
            goto login_try;
        }
    }
    printf("\n\nPress any key to exit!");
    getch();
    system("cls");
    system("color 7");
    return 0;
}