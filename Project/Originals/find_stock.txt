#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "to_upper_case.c"

void main()
{
    FILE *fp;
    // int fp_position=0;
    char ch;
    char stock_code[10];
    char n[100];
    char n2[100]="CompanyDetail.aspx?symbol=";
    int count = strlen(n2);
    int stock_code_len;

    printf("Enter the code of the stock you want to see: ");
    scanf("%s", stock_code);
    to_upper_case(stock_code);
    stock_code_len = strlen(stock_code);
    count+=stock_code_len;
    count++;
    printf("%s", stock_code);
    strcat(n2, stock_code);
    printf("\n%s\n", n2);

    fp = fopen("hello.txt", "r");

    while (ch!=EOF)
    {
        ch = fgetc(fp);
        if (ch == '/')
        {
            fgets(n, count, fp);
            if (strcmp(n,n2)==0)
            {
                printf("Found!");
                goto here;
            }
        }
    }
    printf("\nNot Found!");
    here:
    fclose(fp);
    getch();
}
