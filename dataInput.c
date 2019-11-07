#include <stdio.h>

void inputPersonalData(char username[], char password[])
{
    printf("Please sign in to continue! \n");
    printf("---Username:\n");
    gets(username);
    printf("---Password:\n");
    gets(password);
}

int getChoiceIndex(int noOfChoices, int *state)
{
    int choiceIndex;
    char choice = getchar();
    getchar();
    if(choice == 'a'+noOfChoices){
        (*state)--;
    }
    else
    {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}

//
// Created by Anca on 11/6/2019.
//

