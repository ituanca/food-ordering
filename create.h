//
// Created by Anca on 12/22/2019.
//

#ifndef FOOD_ORDERING_CREATE_H
#define FOOD_ORDERING_CREATE_H

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

#endif //FOOD_ORDERING_CREATE_H
