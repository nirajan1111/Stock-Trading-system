#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "notification_sound.c"

void sell();
void buy();

// void to_upper_case(char stock_code[])
// {
//     int i=0;
//     while (stock_code[i]!='\0')
//     {
//         if (stock_code[i]>='a' && stock_code[i]<='z')
//         {
//             stock_code[i]-=32;
//         }
//         i++;
//     }
// }

void stalk() 
{
    char ch;
    Buy_Sell:
    printf("Do you want to buy/sell? (b/s): ");
    scanf(" %c", &ch);
    switch (ch)
    {
    case 'b':
    case 'B':
        buy();
        break;

    case 's':
    case 'S':
        sell();
        break;
    
    default:
        break;
    }
}

void buy()
{
    FILE *fp;
    struct data
    {
        char symbol[10];
        char ltp[10];
        char percentage_change[10];
        char open[10];
        char high[10];
        char low[10];
        char quantity[10];
        char pclose[10];
        char difference[10];
    }d1;
    char ch;
    char stock_code[10];
    float buying_price;
    float price;
    char n[100];
    char n2[100] = "CompanyDetail.aspx?symbol=";
    int count = strlen(n2);
    int stock_code_len;
    int i = 0;

    printf("Enter the code of the stock you want to follow: ");
    scanf("%s", stock_code);
    to_upper_case(stock_code);
    stock_code_len = strlen(stock_code);
    count += stock_code_len;
    count++;
    printf("Enter the price per share of stock you want to buy: ");
    scanf("%f", &buying_price);
    strcat(n2, stock_code);

    printf("Please wait while price of %s falls to %.2f", stock_code, buying_price);

    while (price>buying_price)
    {
        system("cd C:/Users/Aakriti/Documents/Computer Engineering/1st SEMESTER/Subjects/C/Project/Final/");
        system("gcc downloader_for_stock_information.c -lcurl -o downloader_for_stock_information.exe");
        system("downloader_for_stock_information");
        fp = fopen("hello.txt", "r");

        // Finding the stock symbol
        while (ch != EOF)
        {
            ch = fgetc(fp);
            if (ch == '/')
            {
                fgets(n, count, fp);
                if (strcmp(n, n2) == 0)
                {
                    printf("\nProcessing!\n");
                    // Finding the data
                    // Finding the symbol
                    Symbol:
                    while (ch != EOF)
                    {
                        ch = fgetc(fp);
                        if (ch == '>')
                        {
                            i = 0;
                            while (ch != EOF)
                            {
                                ch = fgetc(fp);
                                if (ch != '<')
                                {
                                    d1.symbol[i] = ch;
                                    i++;
                                }
                                else
                                {
                                    goto LTP;
                                }
                            }
                        }
                    }
                    // Finding the LTP
                    LTP:
                    while (ch != EOF)
                    {
                        ch = fgetc(fp);
                        if (ch == '>')
                        {
                            ch = fgetc(fp);
                            if (ch >= 48 && ch <= 57)
                            {
                                i = 0;
                                d1.ltp[i] = ch;
                                i++;
                                while (ch != EOF)
                                {
                                    ch = fgetc(fp);
                                    if (ch != '<')
                                    {
                                        d1.ltp[i] = ch;
                                        i++;
                                    }
                                    else
                                    {
                                        goto there;
                                    }
                                }
                            }
                        }
                    }
                    goto here;
                }
            }
        }

        printf("\nNot Found!");
        goto EndLoop;
        goto here;

        // Printing the informations
        there:
        {
            price = atof(d1.ltp);
        }

        here:
        {
            fclose(fp);
        }
        Sleep(10000);
    }
    EndLoop:
    if (price<=buying_price)
    {
        printf("\nStock price has been reached! YAY!\n");
        notification_sound();
    }
}

void sell()
{
    FILE *fp;
    struct data
    {
        char symbol[10];
        char ltp[10];
        char percentage_change[10];
        char open[10];
        char high[10];
        char low[10];
        char quantity[10];
        char pclose[10];
        char difference[10];
    }d1;
    char ch;
    char stock_code[10];
    float selling_price;
    float price;
    char n[100];
    char n2[100] = "CompanyDetail.aspx?symbol=";
    int count = strlen(n2);
    int stock_code_len;
    int i = 0;

    printf("Enter the code of the stock you want to follow: ");
    scanf("%s", stock_code);
    to_upper_case(stock_code);
    stock_code_len = strlen(stock_code);
    count += stock_code_len;
    count++;
    printf("Enter the price per share of stock you want to sell: ");
    scanf("%f", &selling_price);
    strcat(n2, stock_code);

    printf("Please wait while price of %s rises to %.2f", stock_code, selling_price);

    while (price<selling_price)
    {
        system("cd C:/Users/Aakriti/Documents/Computer Engineering/1st SEMESTER/Subjects/C/Project/Final/");
        system("gcc downloader_for_stock_information.c -lcurl -o downloader_for_stock_information.exe");
        system("downloader_for_stock_information");
        fp = fopen("hello.txt", "r");

        // Finding the stock symbol
        while (ch != EOF)
        {
            ch = fgetc(fp);
            if (ch == '/')
            {
                fgets(n, count, fp);
                if (strcmp(n, n2) == 0)
                {
                    printf("\nProcessing!\n");
                    // Finding the data
                    // Finding the symbol
                    Symbol:
                    while (ch != EOF)
                    {
                        ch = fgetc(fp);
                        if (ch == '>')
                        {
                            i = 0;
                            while (ch != EOF)
                            {
                                ch = fgetc(fp);
                                if (ch != '<')
                                {
                                    d1.symbol[i] = ch;
                                    i++;
                                }
                                else
                                {
                                    goto LTP;
                                }
                            }
                        }
                    }
                    // Finding the LTP
                    LTP:
                    while (ch != EOF)
                    {
                        ch = fgetc(fp);
                        if (ch == '>')
                        {
                            ch = fgetc(fp);
                            if (ch >= 48 && ch <= 57)
                            {
                                i = 0;
                                d1.ltp[i] = ch;
                                i++;
                                while (ch != EOF)
                                {
                                    ch = fgetc(fp);
                                    if (ch != '<')
                                    {
                                        d1.ltp[i] = ch;
                                        i++;
                                    }
                                    else
                                    {
                                        goto there;
                                    }
                                }
                            }
                        }
                    }
                    goto here;
                }
            }
        }

        printf("\nNot Found!");
        goto EndLoop;
        goto here;

        // Printing the informations
        there:
        {
            price = atof(d1.ltp);
        }

        here:
        {
            fclose(fp);
        }
        Sleep(10000);
    }
    EndLoop:
    if (price>=selling_price)
    {
        printf("\nStock price has been reached! YAY!\n");
        notification_sound();
    }
}
