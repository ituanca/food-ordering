//
// Created by Anca on 11/7/2019.
//

#define MAX_TYPE_NAME 20
#define MAX_SORT_NAME 17
#define MAX_DRINK_NAME 20

#ifndef FOOD_ORDERING_DISPLAYDATA_H
#define FOOD_ORDERING_DISPLAYDATA_H

void displayTypeOptions(int noOfTypes, char **types);
void displaySortsOptions(int *noOfSorts, char **types, char ***sorts, double prices[]);
void displayDrinksChoice(int noOfDrinks, char **drinks, double *drinkPrice);


#endif //FOOD_ORDERING_DISPLAYDATA_H
