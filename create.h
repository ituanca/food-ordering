//
// Created by Anca on 12/22/2019.
//

#ifndef FOOD_ORDERING_CREATE_H
#define FOOD_ORDERING_CREATE_H
#include <stdio.h>

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

typedef struct _customer{
    char *username;
    char *password;
} Customer;

Customer createCustomer();
Type createType(int noOfSorts);
Drink* createDrinks(int noOfDrinks);
Type* constructTypesFromFile(FILE * foodDataFile);
Drink* constructDrinksFromFile(FILE * foodDataFile);

#endif //FOOD_ORDERING_CREATE_H
