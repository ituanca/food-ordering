//
// Created by Anca on 11/7/2019.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_TYPE_NAME 20
#define MAX_SORT_NAME 17
#define MAX_DRINK_NAME 20
#include "displayData.h"

Sort createSort() {
    Sort mySort;
    mySort.name = (char *) malloc (MAX_SORT_NAME * sizeof(char));
    return mySort;
}

Sort* createSorts(int n) {
    Sort * mySorts = (Sort *) malloc (n * sizeof(Sort));
    for (int i = 0; i < n; i++) {
        mySorts[i] = createSort();
    }
    return mySorts;
}

Type createType(int noOfSorts){
    Type myType;
    myType.name = (char *) malloc (MAX_TYPE_NAME * sizeof(char));
    myType.noOfSorts = noOfSorts;
    myType.sorts = createSorts(myType.noOfSorts);
    return myType;
}

Drink createDrink() {
    Drink myDrink;
    myDrink.name = (char *) malloc (MAX_DRINK_NAME * sizeof(char));
    return myDrink;
}

Drink* createDrinks(int noOfDrinks) {
    Drink * myDrinks = (Drink *) malloc (noOfDrinks * sizeof(Drink));
    for (int i = 0; i < noOfDrinks; i++) {
        myDrinks[i] = createDrink();
    }
    return myDrinks;
}

void displayTypeOptions(int noOfTypes, Type * types)
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfTypes;i++){
        putchar('a'+i);
        printf(") %s\n",types[i].name);
    }
    printf("%c) Go back\n", 'a'+noOfTypes);
}

void displaySortsOptions(Type type)
{
    printf("Please choose the sort of %s \n", type.name);
    for (int i = 0; i < type.noOfSorts; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", type.sorts[i].name, type.sorts[i].price);
    }
    printf("%c) Go back\n", 'a' + type.noOfSorts);
}

void displayDrinksChoice(int noOfDrinks, char* type, Drink* drinks)
{
    printf("Please choose a drink to go with your %s:\n", type);
    for(int i=0;i<noOfDrinks;i++){
        putchar('a'+i);
        printf(") %s (%.2f)\n", drinks[i].name, drinks[i].price);
    }
    printf("%c) Go back\n", 'a' + noOfDrinks);
}