#include <stdio.h>
#include "create.h"
#include "displayData.h"
#include "extra.h"
#include "orderConfirmation.h"

void inputPersonalData(Customer *c) {
    printf("Please sign in to continue! \n");
    printf("---Username:\n");
    gets(c->username);
    printf("---Password:\n");
    gets(c->password);
}

int getChoiceIndex(int noOfChoices, int *state) {
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

