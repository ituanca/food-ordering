//
// Created by Anca on 11/7/2019.
//
#include "constants.h"

#ifndef FOOD_ORDERING_DISPLAYDATA_H
#define FOOD_ORDERING_DISPLAYDATA_H

typedef struct _sort{
    char *name;
    double price;
}Sort;

typedef struct _type{
    char *name;
    int noOfSorts;
    Sort * sorts;
}Type;

typedef struct _drink{
    char *name;
    double price;
}Drink;

Type createType(int noOfSorts);
Drink* createDrinks(int noOfDrinks);
void displayTypeOptions(int noOfTypes, Type* types);
void displaySortsOptions(Type type);
void displayDrinksChoice(int noOfDrinks, char* types, Drink* drinks);


#endif //FOOD_ORDERING_DISPLAYDATA_H
