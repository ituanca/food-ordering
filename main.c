#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataInput.h"
#include "displayData.h"
#include "extra.h"
#include "orderConfirmation.h"
#include "constants.h"
#include "create.h"
#include "memoryHandler.h"

int main() {
    printf("Welcome to Food Thingies!\n");
    FILE * foodDataFile;
    foodDataFile = fopen("D:\\Facultate\\food-ordering\\data.txt", "r");
    if(foodDataFile == NULL){
        printf("%s\n", LOAD_DATA);
        foodDataFile=stdin;
    }
    int noOfCutlery=2, state = 0, orderConfirmed = 0, typeChoice, sortChoice, drinkChoice, cutleryChoice;
    char cutlery[][MAX_CUTLERY_NAME]={"Yes", "No,thanks!"}, addInfo[30];
    Customer c = createCustomer();
    int noOfTypes, noOfDrinks, noOfSorts;
    char *ptr, **line, *lineDrinks, *tempSortName;
    char sep[] = "-(),";
    int isSort, isDrink=1;

    fscanf(foodDataFile, "%d:", &noOfTypes);
    fgetc(foodDataFile);

    //food
    line = (char **) malloc(noOfTypes * sizeof(char *));
    tempSortName = (char *) malloc(MAX_SORT_NAME * sizeof(char));

    Type* types = (Type*) malloc (noOfTypes * sizeof(Type));

    for (int i = 0; i < noOfTypes; i++) {
        line[i] = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
        fgets(line[i],MAX_LINE_LENGTH,foodDataFile);

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
        //for(int j = 0; j < types[i].noOfSorts; j++){
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
        //}
    }

    //drinks
    fscanf(foodDataFile, "%d: ", &noOfDrinks);
    fgetc(foodDataFile);
    lineDrinks = (char *) malloc(MAX_LINE_DRINKS * sizeof(char));
    Drink* drinks =  createDrinks(noOfDrinks);
    fgets(lineDrinks,MAX_LINE_DRINKS,foodDataFile);
    int i = 0;

    ptr = strtok(lineDrinks, sep);
    while (ptr != NULL && i < noOfDrinks) {
        if(strcmp(ptr," ")==0){
            ptr=strtok(NULL,sep);
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

    while(!orderConfirmed) {
        switch (state) {
            case 0: {
                inputPersonalData(&c);
                state++;
                break;
            }
            case 1: {
                displayTypeOptions(noOfTypes, types);
                typeChoice = getChoiceIndex(noOfTypes, &state);
                break;
            }
            case 2: {
                displaySortsOptions(types[typeChoice]);
                sortChoice = getChoiceIndex(types[typeChoice].noOfSorts, &state);
                break;
            }
            case 3: {
                displayDrinksChoice(noOfDrinks, types[typeChoice].name, drinks);
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
                displayOrderInfo(&c, &(types[typeChoice].sorts[sortChoice]), &drinks[drinkChoice], addInfo, cutleryChoice);
                confirmOrder(&orderConfirmed, &state);
                break;
            }
        }
    }
    //free memory
    freeData(line, lineDrinks, types, noOfTypes, drinks, noOfDrinks);
    fclose(foodDataFile);
    return 0;
}







