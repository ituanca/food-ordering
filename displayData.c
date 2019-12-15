//
// Created by Anca on 11/7/2019.
//
#include <stdio.h>
#define MAX_TYPE_NAME 20
#define MAX_SORT_NAME 17
#define MAX_DRINK_NAME 20

void displayTypeOptions(int noOfTypes, char **types)
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfTypes;i++){
        putchar('a'+i);
        printf(") %s\n",types[i]);
    }
    printf("%c) Go back\n", 'a'+noOfTypes);
}

void displaySortsOptions(int noOfSorts, char *types, char **sorts, double *prices)
{
    printf("Please choose the sort of %s \n", types);
    for (int i = 0; i < noOfSorts; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", sorts[i], prices[i]);
    }
    printf("%c) Go back\n", 'a' + noOfSorts);
}

void displayDrinksChoice(int noOfDrinks, char **types, char **drinks, double *drinkPrice)
{
    printf("Please choose a drink to go with your %s:\n", types);
    for(int i=0;i<noOfDrinks;i++){
        putchar('a'+i);
        printf(") %s (%.2f)\n", drinks[i], drinkPrice[i]);
    }
    printf("%c) Go back\n", 'a' + noOfDrinks);
}