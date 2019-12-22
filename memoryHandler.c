//
// Created by Anca on 12/22/2019.
//
#include "create.h"
#include "memoryHandler.h"
#include <stdlib.h>

void freeSort(Sort *sorts){
    free(sorts->name);
}

void freeTypes(char *line, Type * types, int noOfTypes){
    for(int i=0;i<noOfTypes;i++){
        for(int j=0; j<types[i].noOfSorts; j++){
            freeSort(&(types[i].sorts[j]));
        }
        free(line[i]);
        free(types[i].sorts);
        free(types[i].name);
    }
    free(line);
    free(types);
}

void freeData(char line, char lineDrinks, Type * types, int noOfTypes, Drink* drinks, int noOfDrinks){
    freeTypes(line, types, noOfTypes);
    for (int i = 0; i < noOfDrinks; i++) {
        free(drinks[i].name);
    }
    free(lineDrinks);
    free(drinks);
}
