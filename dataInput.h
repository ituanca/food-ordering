//
// Created by Anca on 11/6/2019.
//

#ifndef FOOD_ORDERING_DATAINPUT_H
#define FOOD_ORDERING_DATAINPUT_H

typedef struct _customer{
    char *username;
    char *password;
} Customer;

Customer createCustomer();
void inputPersonalData(Customer *c);
int getChoiceIndex(int noOfChoices, int *state);

#endif //FOOD_ORDERING_DATAINPUT_H
