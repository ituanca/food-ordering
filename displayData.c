//
// Created by Anca on 11/7/2019.
//
#include <stdio.h>
#include "displayData.h"

void displayTypeOptions(Type * types)
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i = 0;i < sizeof(types) - 1; i++) { //-1 to account for the null byte as per https://stackoverflow.com/questions/11919369/why-sizeofa-pointer-returns-incorrect-value
        putchar('a'+i);
        printf(") %s\n", types[i].name);
    }
    printf("%c) Go back\n", 'a' + sizeof(types));
}

void displaySortsOptions(Type type)
{
    printf("Please choose the sort of %s \n", type.name);
    for (int i = 0; i < type.noOfSorts; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", type.sorts[i].name, type.sorts[i].price);
    }
    printf("%c) Go back\n", 'a' + type.noOfSorts);
}

void displayDrinksChoice(char* type, Drink* drinks)
{
    printf("Please choose a drink to go with your %s:\n", type);
    for(int i = 0;i < sizeof(drinks); i++){
        putchar('a' + i);
        printf(") %s (%.2f)\n", drinks[i].name, drinks[i].price);
    }
    printf("%c) Go back\n", 'a' + sizeof(drinks));
}