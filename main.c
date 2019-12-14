#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataInput.h"
#include "displayData.h"
#include "extra.h"
#include "orderConfirmation.h"
#include "constants.h"
#define LOAD_DATA "Please load the data"
#define MAX_LINE 50
#define MAX_LINE_DRINKS 50

int main() {

    printf("Welcome to Food Thingies!\n");
    FILE * foodDataFile;
    foodDataFile = fopen("D:\\Facultate\\food-ordering\\data.txt", "r");
    if(foodDataFile == NULL){
        printf("%s\n", LOAD_DATA);
        foodDataFile=stdin;
    }
    int noOfCutlery=2;
    int  state = 0, orderConfirmed = 0, typeChoice, sortChoice, drinkChoice, cutleryChoice;
    char cutlery[][MAX_CUTLERY_NAME]={"Yes", "No,thanks!"};
    char username[30], password[30], addInfo[30];
    int noOfTypes;
    int noOfDrinks;
    char *ptr;
    char **line;
    char **types;
    int *noOfSorts;
    char ***sorts;
    double **prices;
    char *lineDrinks;
    char **drinks;
    double *drinkPrice;

    char sep[] = "-()";
    int isSort=1;
    int isDrink=1;

    fscanf(foodDataFile, "%d:", &noOfTypes);
    fgetc(foodDataFile);

    //food
    line = (char **) malloc(noOfTypes * sizeof(char *));
    types = (char **) malloc(noOfTypes * sizeof(char *));
    noOfSorts = (int *) malloc(noOfTypes * sizeof(int));
    sorts = (char ***) malloc(noOfTypes * sizeof(char **));
    prices = (double **) malloc(noOfTypes * sizeof(double *));

    for (int i = 0; i < noOfTypes; i++) {
        line[i] = (char *) malloc(MAX_LINE * sizeof(char));
        fgets(line[i],MAX_LINE,foodDataFile);
        types[i] = (char *) malloc(MAX_TYPE_NAME * sizeof(char));
        sorts[i] = (char**)malloc(noOfSorts[i]* sizeof(char*));
        prices[i] = (double*)malloc(noOfSorts[i]* sizeof(double));

        ptr = strtok(line[i], " ");
        strcpy(types[i], ptr);
        ptr = strtok(NULL, ":");
        noOfSorts[i] = atof(ptr);
        int j = 0;

        ptr = strtok(NULL,sep);
        while(ptr!=NULL){
            sorts[i][j] = (char*)malloc(MAX_SORT_NAME* sizeof(char));
            if(strcmp(ptr," ")==0){
                ptr=strtok(NULL,sep);
            }
            if(isSort==1){
                strcpy(sorts[i][j],ptr);
                isSort=0;
            }
            else{
                prices[i][j] = atof(ptr+1);
                j++;
                isSort=1;
            }
            ptr = strtok(NULL, sep);
        }
    }
    for(int i=0;i<noOfTypes;i++){
        printf("%s\n",types[i]);
        for(int j=0;j<noOfSorts[i];j++){
            printf("%s\n",sorts[i][j]);
            printf("%.2lf\n",prices[i][j]);
        }
    }

    //drinks
    fscanf(foodDataFile, "%d: ", &noOfDrinks);
    fgetc(foodDataFile);
    lineDrinks = (char *) malloc(MAX_LINE_DRINKS * sizeof(char));
    drinks = (char **) malloc(noOfDrinks * sizeof(char *));
    drinkPrice = (double *) malloc(noOfDrinks * sizeof(double));
    fgets(lineDrinks,MAX_LINE_DRINKS,foodDataFile);
    int i = 0;

    ptr = strtok(lineDrinks, sep);
    while (ptr != NULL) {
        drinks[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        if(strcmp(ptr," ")==0){
            ptr=strtok(NULL,sep);
        }
        if (isDrink == 1) {
            strcpy(drinks[i], ptr);
            isDrink = 0;
            printf("%s\n", drinks[i]);
        } else {
            drinkPrice[i] = atof(ptr+1);
            isDrink = 1;
            printf("%.2lf\n", drinkPrice[i]);
            i++;
        }
        ptr = strtok(NULL, sep);
    }

    while(!orderConfirmed) {
        switch (state) {
            case 0: {
                inputPersonalData(username, password);
                state++;
                break;
            }
            case 1: {
                displayTypeOptions(noOfTypes, types);
                typeChoice = getChoiceIndex(noOfTypes, &state);
                break;
            }
            case 2: {
                displaySortsOptions(noOfSorts[typeChoice], types[typeChoice], sorts[typeChoice], prices[typeChoice]);
                sortChoice = getChoiceIndex(noOfSorts[typeChoice], &state);
                break;
            }
            case 3: {
                displayDrinksChoice(noOfDrinks, types, drinks, drinkPrice);
                drinkChoice = getChoiceIndex(noOfDrinks, &state);
                break;
            }
            case 4: {
                displayCutleryChoice(noOfCutlery, cutlery);
                cutleryChoice = getChoiceIndex(noOfCutlery, &state);
                break;
            }
            case 5: {
                additionalInfo(addInfo);
                state++;
                break;
            }
            case 6: {
                displayOrderInfo(username, sorts[typeChoice][sortChoice], prices[typeChoice][sortChoice],
                                 drinks[drinkChoice], drinkPrice[drinkChoice], addInfo, cutleryChoice);
                confirmOrder(&orderConfirmed, &state);
                break;
            }
        }
}
    //free memory
    for(int i=0;i<noOfTypes;i++){
        for(int j=0;j<noOfSorts[i]-1;j++){
            free(sorts[i][j]);
        }
        free(line[i]);
        free(types[i]);
        free(drinks[i]);
        free(prices[i]);
    }
    free(types);
    free(sorts);
    free(line);
    free(drinks);
    free(prices);
    free(noOfSorts);
    free(lineDrinks);
    free(drinkPrice);
    fclose(foodDataFile);
    return 0;
}






