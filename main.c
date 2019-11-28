#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataInput.h"
#include "displayData.h"
#include "extra.h"
#include "orderConfirmation.h"
#define MAX_TYPE_NAME 50
#define MAX_SORT_NAME 50
#define MAX_DRINK_NAME 20
#define MAX_CUTLERY_NAME 20
#define LOAD_DATA "Please load the data"

int main() {
    printf("Welcome to Food Thingies!\n");
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

    char sep[] = "- ():";
    int isType;
    int isSort=1;
    int isDrink=1;

    while(!orderConfirmed){
        switch (state){
            case 0:{
                printf("%s \n", LOAD_DATA);
                scanf("%d ", &noOfTypes);

                line = (char**)malloc(noOfTypes* sizeof(char*));

                types = (char**)malloc(noOfTypes* sizeof(char*));

                noOfSorts = (int*)malloc(noOfTypes*sizeof(int));

                sorts = (char***)malloc(noOfTypes* sizeof(char**));

                prices = (double**)malloc(noOfTypes* sizeof(double*));

                for(int i=0;i<noOfTypes;i++){
                    line[i] = (char*)malloc(MAX_TYPE_NAME* sizeof(char));
                    gets(line[i]);
                    types[i] = (char*)malloc(MAX_TYPE_NAME* sizeof(char));
                    isType=0;
                    int j=0;
                    sorts[i] = (char**)malloc(noOfSorts[i]* sizeof(char*));

                    ptr = strtok(line[i],sep);
                    while(ptr!=NULL){
                        if(isType==0){
                            strcpy(types[i],ptr);
                            printf("%s \n", types[i]);
                            isType=1;
                        }
                        else{
                            if(isSort==1){
                                sorts[i][j] = (char*)malloc(MAX_SORT_NAME* sizeof(char));
                                strcpy(sorts[i][j],ptr);
                                isSort=0;
                                printf("%s \n", sorts[i][j]);
                                j++;
                            }
                            else{
                                prices[i] = (double*)malloc((noOfTypes)* sizeof(double));
                                prices[i][j] = atof(ptr);
                                printf("%.2lf \n", prices[i][j]);
                                isSort=1;
                            }
                        }
                        ptr = strtok(NULL, sep);
                    }
                    noOfSorts[i]=j;
                    printf("%d \n", noOfSorts[i]);
                }

                scanf("%d ", &noOfDrinks);
                getchar();
                lineDrinks = (char*)malloc(MAX_DRINK_NAME* sizeof(char));
                drinks = (char**)malloc(noOfDrinks* sizeof(char*));
                drinkPrice = (double*)malloc(noOfDrinks * sizeof(double));
                gets(lineDrinks);
                int i=0;
                for(int i=0;i<noOfDrinks;i++){

                }
                ptr = strtok(lineDrinks,sep);
                while(ptr!=NULL){
                    if(isDrink==1){
                        strcpy(drinks[i],ptr);
                        isDrink=0;
                        printf("%s \n", drinks[i]);
                    }
                    else{
                        drinkPrice[i]=atof(ptr);
                        isDrink=1;
                        printf("%.2lf \n",drinkPrice[i]);
                    }
                    i++;
                    ptr = strtok(NULL,sep);
                }

                inputPersonalData(username, password);
                state++;
                break;
            }
            case 1:{
                displayTypeOptions(noOfTypes, types);
                typeChoice = getChoiceIndex(noOfTypes, &state);
                break;
            }
            case 2: {
                displaySortsOptions(noOfSorts, types, sorts, prices[typeChoice]);
                sortChoice = getChoiceIndex(noOfSorts, &state);
                break;
            }
            case 3: {
                displayDrinksChoice(noOfDrinks, drinks, drinkPrice);
                drinkChoice = getChoiceIndex(noOfDrinks, &state);
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
                displayOrderInfo(username, sorts[typeChoice], prices[typeChoice][sortChoice], drinks[drinkChoice], drinkPrice[drinkChoice], addInfo, cutleryChoice);
                confirmOrder(&orderConfirmed, &state);
                break;
            }
        }
    }
    return 0;
}






