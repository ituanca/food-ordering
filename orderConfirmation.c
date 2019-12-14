#include <stdio.h>
#include <string.h>

void displayOrderInfo(char username[], char *sorts, double prices, char *drink, double drinkPrices, char addInfo[], int cutleryChoice)
{
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s \n",username);

    printf("Food items: \n");
    printf("---%s (%.2f)\n", sorts, prices);
    if(drinkPrices != 0){
        printf("---%s (%.2f)\n", drink, drinkPrices);
    }
    else{
        printf("---no drink \n");
    }
    if(strcmp(addInfo,"")!=0)
        printf("Additional info: %s \n", addInfo);
    printf("Cutlery: ");
    if(cutleryChoice == 0)
        printf("yes \n");
    else
        printf("no \n");
    printf("Payment amount: %.2f\n", prices + drinkPrices);
}

void confirmOrder(int *orderConfirmed, int *state)
{
    char choice;
    printf("-------------- \n");
    printf("a) Confirm order\n");
    printf("b) Go back\n");
    choice = getchar();
    if(choice=='a') {
        *orderConfirmed = 1;
        printf("Your order is confirmed! \n");
    } else {
        (*state)-=2;
    }
    getchar();
}


//
// Created by Anca on 11/7/2019.
//

