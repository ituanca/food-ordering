#include <stdio.h>
#include <string.h>
#include "dataInput.h"
#include "displayData.h"

void displayOrderInfo(Customer * customer, Sort * sort, Drink * drink, char addInfo[], int cutleryChoice)
{
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s \n", customer -> username);

    printf("Food items: \n");
    printf("---%s (%.2f)\n", sort -> name, sort -> price);
    if(drink -> price != 0){
        printf("---%s (%.2f)\n", drink -> name, drink -> price);
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
    printf("Payment amount: %.2f\n", sort -> price + drink -> price);
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

