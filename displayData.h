//
// Created by Anca on 11/7/2019.
//

#define MAX_TYPE_NAME 20
#define MAX_SORT_NAME 17
#define MAX_DRINK_NAME 20

#ifndef FOOD_ORDERING_DISPLAYDATA_H
#define FOOD_ORDERING_DISPLAYDATA_H

void displayTypeOptions(int noOfTypesOfFood, char types[][MAX_TYPE_NAME]);
void displaySortsOptions(int noSorts, char types[], char sorts[][MAX_SORT_NAME], double prices[]);
void displayDrinksChoice(int noDrink, char drink[][MAX_DRINK_NAME], double drinkPrices[]);


#endif //FOOD_ORDERING_DISPLAYDATA_H
