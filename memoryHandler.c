//
// Created by Anca on 12/22/2019.
//
#include "create.h"
#include "memoryHandler.h"
#include <stdlib.h>

void freeLine(char* line) {
    free(line);
}

void freeSorts(Sort *sorts){
    free(sorts->name);
}

void freeTypes(Type * types) {
    for(int i=0;i < sizeof(types);i++){
        for(int j=0; j<types[i].noOfSorts; j++){
            freeSorts(&(types[i].sorts[j]));
        }
        free(types[i].sorts);
        free(types[i].name);
    }
    free(types);
}

void freeDrinks(Drink* drinks) {
    for (int i = 0; i < sizeof(drinks); i++) {
        free(drinks[i].name);
    }
    free(drinks);
}
