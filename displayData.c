//
// Created by Anca on 11/7/2019.
//
#include <stdio.h>
#define MAX_TYPE_NAME 20
#define MAX_SORT_NAME 17
#define MAX_DRINK_NAME 20

void displayTypeOptions(int noOfTypesOfFood, char types[][MAX_TYPE_NAME])
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfTypesOfFood;i++){
        putchar('a'+i);
        printf(") %s\n",types[i]);
    }
    printf("%c) Go back\n", 'a'+noOfTypesOfFood);
}

void displaySortsOptions(int noSorts, char types[], char sorts[][MAX_SORT_NAME], double prices[])
{
    printf("Please choose the type of %s \n", types);
    for (int i = 0; i < noSorts; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", sorts[i], prices[i]);
    }
    printf("%c) Go back\n", 'a' + noSorts);
}

void displayDrinksChoice(int noDrink, char drink[][MAX_DRINK_NAME], double drinkPrices[])
{
    printf("Please choose a drink to go with your Pizza:\n");
    for(int i=0;i<noDrink;i++){
        putchar('a'+i);
        printf(") %s (%.2f)\n", drink[i], drinkPrices[i]);
    }
    printf("%c) Go back\n", 'a' + noDrink);
}