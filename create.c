//
// Created by Anca on 12/22/2019.
//
#include "stdlib.h"
#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "create.h"
#include "memoryHandler.h"

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

Customer createCustomer(){
    Customer c;
    c.username =(char*)malloc(MAX_USERNAME* sizeof(char));
    c.password = (char*)malloc(MAX_PASSWORD* sizeof(char));
    return c;
}

Type* constructTypesFromFile(FILE * foodDataFile) {
    int noOfTypes, noOfSorts, isSort;
    char *ptr, **line, *tempSortName;
    char sep[] = "-(),";

    fscanf(foodDataFile, "%d:", &noOfTypes);
    fgetc(foodDataFile);

    line = (char **) malloc(noOfTypes * sizeof(char *));
    tempSortName = (char *) malloc(MAX_SORT_NAME * sizeof(char));
    Type* types = (Type*) malloc (noOfTypes * sizeof(Type));

    for (int i = 0; i < noOfTypes; i++) {
        line[i] = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
        fgets(line[i], MAX_LINE_LENGTH, foodDataFile);

        //read type name
        ptr = strtok(line[i], " ");
        strcpy(tempSortName, ptr);

        //read type sort numbers
        ptr = strtok(NULL, ":");
        noOfSorts = atoi(ptr);

        //create the actual type
        types[i] = createType(noOfSorts);
        strcpy(types[i].name, tempSortName);
        types[i].noOfSorts = noOfSorts;

        //create sorts based on prev computed number
        ptr = strtok(NULL,sep);
        isSort = 1;
        int j = 0;
        while (ptr != NULL && j < types[i].noOfSorts)
        {
            if(strcmp(ptr," ") == 0)
            {
                ptr=strtok(NULL, sep);
            }
            if(isSort == 1){
                strcpy(types[i].sorts[j].name, ptr);
                isSort=0;
            }
            else{
                types[i].sorts[j].price = atof(ptr + 1);
                isSort=1;
                j++;
            }
            ptr = strtok(NULL, sep);
        }
    }
    freeLine(line);
    return types;
}

Drink* constructDrinksFromFile(FILE * foodDataFile) {
    char *ptr, *lineDrinks;
    char sep[] = "-(),";
    int isDrink=1, noOfDrinks;

    fscanf(foodDataFile, "%d: ", &noOfDrinks);
    fgetc(foodDataFile);

    lineDrinks = (char *) malloc(MAX_LINE_DRINKS * sizeof(char));
    Drink* drinks =  createDrinks(noOfDrinks);
    fgets(lineDrinks, MAX_LINE_DRINKS, foodDataFile);
    int i = 0;

    ptr = strtok(lineDrinks, sep);
    while (ptr != NULL && i < noOfDrinks) {
        if(strcmp(ptr, " ")==0){
            ptr = strtok(NULL,sep);
        }
        if (isDrink == 1) {
            strcpy(drinks[i].name, ptr);
            isDrink = 0;
        } else {
            drinks[i].price = atoi(ptr+1);
            isDrink = 1;
            i++;
        }
        ptr = strtok(NULL, sep);
    }
    freeLine(lineDrinks);
    return drinks;
}


