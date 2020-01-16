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
    int noOfCutlery=2, state = 0, orderConfirmed = 0, typeChoice, sortChoice, drinkChoice, cutleryChoice;
    char cutlery[][MAX_CUTLERY_NAME]={"Yes", "No,thanks!"}, addInfo[30];

    FILE * foodDataFile;
    foodDataFile = fopen("D:\\Facultate\\food-ordering\\data.txt", "r");
    if(foodDataFile == NULL){
        printf("%s\n", LOAD_DATA);
        foodDataFile=stdin;
    }

    Type* types = constructTypesFromFile(foodDataFile);

    Drink* drinks = constructDrinksFromFile(foodDataFile);

    Customer customer = createCustomer();

    printf("Welcome to Food Thingies!\n");
    while(!orderConfirmed) {
        switch (state) {
            case 0: {
                inputPersonalData(&customer);
                state++;
                break;
            }
            case 1: {
                displayTypeOptions(types);
                typeChoice = getChoiceIndex(sizeof(types), &state);
                break;
            }
            case 2: {
                displaySortsOptions(types[typeChoice]);
                sortChoice = getChoiceIndex(types[typeChoice].noOfSorts, &state);
                break;
            }
            case 3: {
                displayDrinksChoice(types[typeChoice].name, drinks);
                drinkChoice = getChoiceIndex(sizeof(drinks), &state);
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
                displayOrderInfo(&customer, &(types[typeChoice].sorts[sortChoice]), &drinks[drinkChoice], addInfo, cutleryChoice);
                confirmOrder(&orderConfirmed, &state);
                break;
            }
        }
    }

    //free memory
    fclose(foodDataFile);
    freeTypes(types);
    freeDrinks(drinks);

    return 0;
}







