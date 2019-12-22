//
// Created by Anca on 12/22/2019.
//
#include "stdlib.h"
#include "constants.h"
#include "create.h"

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


