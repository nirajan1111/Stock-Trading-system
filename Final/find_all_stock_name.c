#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void find_all_stock_name()
{
    // Declarations
    FILE *fp;
    char ch;
    char n[100];
    char n2[100] = "CompanyDetail.aspx?symbol=";
    int count = strlen(n2);
    int i = 0, j = 0;
    int a = 0;
    int b = 1;
    char arr[500][500];

    fp = fopen("hello.txt", "r");

    count++;

// Searching and Storing names
First:
    j = 0;
    while (ch != EOF)
    {
        ch = fgetc(fp);
        if (ch == '/')
        {
            fgets(n, count, fp);
            if (strcmp(n, n2) == 0)
            {
                while (ch != EOF)
                {
                    ch = fgetc(fp);
                    if (ch == '>')
                    {
                        while (ch != EOF)
                        {
                            ch = fgetc(fp);
                            if (ch != '<')
                            {
                                arr[i][j] = ch;
                                j++;
                            }
                            else
                            {
                                i++;
                                goto First;
                            }
                        }
                    }
                }
            }
        }
    }

    // Printing the names
    printf("Stocks: \n");
    while (a <= i)
    {
        printf("%s", arr[a]);
        if (b < 5)
        {
            printf("\t\t");
            b++;
        }
        else
        {
            b = 1;
            printf("\n");
        }
        a++;
    }
}