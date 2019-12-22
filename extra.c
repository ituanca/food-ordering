#include <stdio.h>
#define MAX_CUTLERY_NAME 20

void displayCutleryChoice(int noOfCutlery, char cutlery[][MAX_CUTLERY_NAME])
{
    printf("Do you want cutlery? \n");
    for(int i=0;i<noOfCutlery;i++){
        putchar('a'+i);
        printf(") %s\n",cutlery[i]);
    }
    printf("%c) Go back\n", 'a'+noOfCutlery);
}

void additionalInfo(char addInfo[])
{
    printf("Any additional info? \n");
    gets(addInfo);
}

//
// Created by Anca on 11/7/2019.
//

