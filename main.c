#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to Food Thingies!\n");

    int noOfTypesOfFood=3;
    int noOfCutlery=2;
    char types[][10] = {"Pizza","Pasta","Salad"};
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
    int noDrink = 5;
    char drink[][20] = {"Coca-Cola","Fanta","Lipton","Water","No, thanks!"};
    double drinkPrices[] = {5,5,5,4,0};

    char username[30];
    char password[30];
    char addInfo[30];
    int choice, typeChoice, sortChoice, drinkChoice, cutleryChoice;

    char cutlery[][20]={"Yes", "No,thanks!"};

    int state = 0;
    int orderConfirmed = 0;

    while(!orderConfirmed){
        switch (state){
            case 0:{
                printf("Please sign in to continue! \n");
                printf("---Username:\n");
                gets(username);
                printf("---Password:\n");
                gets(password);
                state++;
                break;
            }
            case 1:{
                printf("Please choose the food you feel like eating today:\n");
                for(int i=0;i<noOfTypesOfFood;i++){
                    putchar('a'+i);
                    printf(") %s\n",types[i]);
                }
                printf("%c) Go back\n", 'a'+noOfTypesOfFood);
                choice = getchar();
                getchar();
                if(choice == 'a'+noOfTypesOfFood){
                    state--;
                    break;
                }
                typeChoice = choice - 'a';
                state++;
                break;
            }
            case 2: {
                printf("Please choose the type of %s \n", types[typeChoice]);
                for (int i = 0; i < noSorts[typeChoice]; i++) {
                    putchar('a' + i);
                    printf(") %s (%.2f)\n", sorts[typeChoice][i], prices[typeChoice][i]);
                }
                printf("%c) Go back\n", 'a' + noSorts[typeChoice]);
                choice = getchar();
                getchar();
                if (choice == 'a' + noSorts[typeChoice]) {
                    state--;
                    break;
                }
                sortChoice = choice - 'a';
                state++;
                break;
            }
            case 3: {
                printf("Please choose a drink to go with your Pizza:\n");
                for(int i=0;i<noDrink;i++){
                    putchar('a'+i);
                    printf(") %s (%.2f)\n", drink[i], drinkPrices[i]);
                }
                printf("%c) Go back\n", 'a' + noDrink);
                choice = getchar();
                if(choice == 'a'+noDrink){
                    state--;
                    getchar();
                    break;
                }
                drinkChoice = choice - 'a';
                state++;
                break;
            }
            case 4:{
                printf("Do you want cutlery? \n");
                for(int i=0;i<noOfCutlery;i++){
                    putchar('a'+i);
                    printf(") %s\n",cutlery[i]);
                }
                printf("%c) Go back\n", 'a'+noOfCutlery);
                choice = getchar();
                getchar();
                if(choice == 'a'+noOfCutlery){
                    state--;
                    break;
                }
                cutleryChoice = choice - 'a';
                state++;
                break;
            }
            case 5:{
                printf("Any additional info? \n");
                gets(addInfo);
                gets(addInfo);
                state++;
                break;
            }
            case 6:{
                printf("This is your order:\n");
                printf("-------------------\n");
                printf("Name: %s \n",username);
                printf("Food items: \n");
                printf("---%s (%.2f)\n", sorts[typeChoice][sortChoice], prices[typeChoice][sortChoice]);
                if(drinkChoice != 4){
                    printf("---%s (%.2f)\n", drink[drinkChoice], drinkPrices[drinkChoice]);
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

                printf("Payment amount: %.2f\n", prices[typeChoice][sortChoice] + drinkPrices[drinkChoice]);
                printf("-------------- \n");
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                choice = getchar();
                if(choice=='a') {
                    orderConfirmed = 1;
                    printf("Your order is confirmed! \n");
                } else {
                    state=state-2;
                }
                getchar();
                break;
            }
        }
    }
    return 0;
}