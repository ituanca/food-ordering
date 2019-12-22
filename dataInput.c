#include <stdio.h>
#include <stdlib.h>
#include "dataInput.h"
#include "constants.h"

Customer createCustomer(){
    Customer c;
    c.username =(char*)malloc(MAX_USERNAME* sizeof(char));
    c.password = (char*)malloc(MAX_PASSWORD* sizeof(char));
    return c;
}

void inputPersonalData(Customer *c)
{
    printf("Please sign in to continue! \n");
    printf("---Username:\n");
    gets(c->username);
    printf("---Password:\n");
    gets(c->password);
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

