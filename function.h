#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void createCandidate(){
  printf("\n Creat candidates);
         
         
         
         
         
         
         
         
int authenticateCandidate(){
    char username[15], password[6];
    
    printf("\nEnter username: ");
    scanf("%s",username);
    if((strcmp(username,"Admin"))!=0)
        return 0;
    else
    {
        printf("Enter Password: ");
        int i=0;
        for(i=0;i<5;i++)
        {
            password[i]=getch();
            printf("%c",'*');
        }
        password[i]='\0';
        if((strcmp(password,"admiN"))!=0)
            return 0;
    }
    return 1;
}
         
