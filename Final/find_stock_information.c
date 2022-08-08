#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

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
};

void find_stock_information()
{
    // Declarations
    FILE *fp;
    // int fp_position=0;
    char ch;
    char stock_code[10];
    char n[100];
    char n2[100] = "CompanyDetail.aspx?symbol=";
    int count = strlen(n2);
    int stock_code_len;
    struct data d1;
    int i = 0;

    // Don't mind the folowing three comments. They are just for testing.
    // system("cd C:/Users/Aakriti/Documents/Computer Engineering/1st SEMESTER/Subjects/C/Project/Final/");
    // system("gcc downloader_for_stock_information.c -lcurl -o downloader_for_stock_information.exe");
    // system("downloader_for_stock_information");

    // User Inputs
    {
        printf("\nEnter the code of the stock you want to see: ");
        scanf("%s", stock_code);
        to_upper_case(stock_code);
        stock_code_len = strlen(stock_code);
        count += stock_code_len;
        count++;
        printf("%s", stock_code);
        strcat(n2, stock_code);
        // printf("\n%s\n", n2);
    }

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
                printf("\nFound!\n");
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
                                    goto PercentageChange;
                                }
                            }
                        }
                    }
                }
            // Finding Percentage Change
            PercentageChange:
                while (ch != EOF)
                {
                    ch = fgetc(fp);
                    if (ch == '>')
                    {
                        ch = fgetc(fp);
                        // If the percentage change is negative
                        if (ch == '-')
                        {
                            ch = fgetc(fp);
                            if (ch >= 48 && ch <= 57)
                            {
                                i = 0;
                                d1.percentage_change[i] = '-';
                                i++;
                                d1.percentage_change[i] = ch;
                                i++;
                                while (ch != EOF)
                                {
                                    ch = fgetc(fp);
                                    if (ch != '<')
                                    {
                                        d1.percentage_change[i] = ch;
                                        i++;
                                    }
                                    else
                                    {
                                        goto High;
                                    }
                                }
                            }
                        }
                        // If the percentage change is negative
                        else if (ch >= 48 && ch <= 57)
                        {
                            i = 0;
                            d1.percentage_change[i] = ch;
                            i++;
                            while (ch != EOF)
                            {
                                ch = fgetc(fp);
                                if (ch != '<')
                                {
                                    d1.percentage_change[i] = ch;
                                    i++;
                                }
                                else
                                {
                                    goto High;
                                }
                            }
                        }
                    }
                }
            // Finding Today's Highest Price
            High:
                while (ch != EOF)
                {
                    ch = fgetc(fp);
                    if (ch == '>')
                    {
                        ch = fgetc(fp);
                        if (ch >= 48 && ch <= 57)
                        {
                            i = 0;
                            d1.high[i] = ch;
                            i++;
                            while (ch != EOF)
                            {
                                ch = fgetc(fp);
                                if (ch != '<')
                                {
                                    d1.high[i] = ch;
                                    i++;
                                }
                                else
                                {
                                    goto Low;
                                }
                            }
                        }
                    }
                }
            Low:
                while (ch != EOF)
                {
                    ch = fgetc(fp);
                    if (ch == '>')
                    {
                        ch = fgetc(fp);
                        if (ch >= 48 && ch <= 57)
                        {
                            i = 0;
                            d1.low[i] = ch;
                            i++;
                            while (ch != EOF)
                            {
                                ch = fgetc(fp);
                                if (ch != '<')
                                {
                                    d1.low[i] = ch;
                                    i++;
                                }
                                else
                                {
                                    goto Quantity;
                                }
                            }
                        }
                    }
                }
            Quantity:
                while (ch != EOF)
                {
                    ch = fgetc(fp);
                    if (ch == '>')
                    {
                        ch = fgetc(fp);
                        if (ch >= 48 && ch <= 57)
                        {
                            i = 0;
                            d1.quantity[i] = ch;
                            i++;
                            while (ch != EOF)
                            {
                                ch = fgetc(fp);
                                if (ch != '<')
                                {
                                    d1.quantity[i] = ch;
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
    goto here;

// Printing the informations
there:
{
    // Printing the data
    printf("Symbol: ");
    puts(d1.symbol);

    printf("LTP: %.2f\n", atof(d1.ltp));

    printf("Percentage Change: %.2f\n", atof(d1.percentage_change));

    printf("High: %.2f\n", atof(d1.high));
    printf("Low: %.2f\n", atof(d1.low));
    printf("Quantity: %.2f\n", atof(d1.quantity));
}

here:
{
    fclose(fp);
}
}