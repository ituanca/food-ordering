//
// Created by Anca on 11/7/2019.
//

#ifndef FOOD_ORDERING_ORDERCONFIRMATION_H
#define FOOD_ORDERING_ORDERCONFIRMATION_H
#include "displayData.h"

void displayOrderInfo(Customer * c, Sort * sort, Drink * drink, char addInfo[], int cutleryChoice);
void confirmOrder(int *orderConfirmed, int *state);

#endif //FOOD_ORDERING_ORDERCONFIRMATION_H
