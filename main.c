#include <stdio.h>
#include "dataInput.h"
#include "displayData.h"
#include "extra.h"
#include "orderConfirmation.h"
#define MAX_TYPE_NAME 20
#define MAX_SORT_NAME 17
#define MAX_DRINK_NAME 20
#define MAX_CUTLERY_NAME 20

int main() {
    printf("Welcome to Food Thingies!\n");
    int noOfTypesOfFood=3;
    int noOfCutlery=2;
    char types[][MAX_TYPE_NAME] = {"Pizza","Pasta","Salad"};
    int noSorts[] = {3,2,4};
    char sorts[3][4][17] = {
            {"Pizza Carbonara","Pizza Diavola","Pizza Margherita"},
            {"Chicken Alfredo","Mac&cheese"},
            {"Tuna Salad","Chicken Salad","Greek Salad","Cobb"}
    };
    double prices[3][4] = {
            {21,23,19},
            {23,21},
            {23,22,19,21}
    };
    int noDrink = 5, state = 0, orderConfirmed = 0, typeChoice, sortChoice, drinkChoice, cutleryChoice;
    char drink[][MAX_DRINK_NAME] = {"Coca-Cola","Fanta","Lipton","Water","No, thanks!"}, cutlery[][MAX_CUTLERY_NAME]={"Yes", "No,thanks!"};
    double drinkPrices[] = {5,5,5,4,0};
    char username[30], password[30], addInfo[30];
    while(!orderConfirmed){
        switch (state){
            case 0:{
                inputPersonalData(username, password);
                state++;
                break;
            }
            case 1:{
                displayTypeOptions(noOfTypesOfFood, types);
                typeChoice = getChoiceIndex(noOfTypesOfFood, &state);
                break;
            }
            case 2: {
                displaySortsOptions(noSorts[typeChoice], types[typeChoice], sorts[typeChoice], prices[typeChoice]);
                sortChoice = getChoiceIndex(noSorts[typeChoice], &state);
                break;
            }
            case 3: {
                displayDrinksChoice(noDrink, drink, drinkPrices);
                drinkChoice = getChoiceIndex(noDrink, &state);
                break;
            }
            case 4:{
                displayCutleryChoice(noOfCutlery, cutlery);
                cutleryChoice = getChoiceIndex(noOfCutlery, &state);
                break;
            }
            case 5:{
                additionalInfo(addInfo);
                state++;
                break;
            }
            case 6:{
                displayOrderInfo(username, sorts[typeChoice][sortChoice], prices[typeChoice][sortChoice], drink[drinkChoice], drinkPrices[drinkChoice], addInfo, cutleryChoice);
                confirmOrder(&orderConfirmed, &state);
                break;
            }
        }
    }
    return 0;
}






