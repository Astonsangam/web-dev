#include <stdio.h>

enum State
{
    IDLE,
    MONEY_INSERTED,
    ITEM_SELECTED,
    DISPENSE,
    CHANGE
};

// Global Variables
enum State currentState = IDLE;
int insertedMoney = 0;

// Items and Prices
struct Item
{
    char name[20];
    int price;
};

struct Item items[] = {
    {"Soda", 100},
    {"Chips", 150},
    {"Candy", 75}};

int itemCount = 3;
int selectedItemIndex = -1;

void displayItems()
{
    printf("Available Items:\n");
    for (int i = 0; i < itemCount; i++)
    {
        printf("%d. %s - %d cents\n", i + 1, items[i].name, items[i].price);
    }
}

void vendingMachineFSM()
{
    switch (currentState)
    {
    case IDLE:
        printf("Vending Machine is ready. Insert money:\n");
        scanf("%d", &insertedMoney);
        currentState = MONEY_INSERTED;
        break;

    case MONEY_INSERTED:
        printf("You inserted %d cents.\n", insertedMoney);
        displayItems();
        printf("Select an item (Enter 1-%d):\n", itemCount);
        scanf("%d", &selectedItemIndex);
        selectedItemIndex--; // Adjust to 0-based index

        if (selectedItemIndex >= 0 && selectedItemIndex < itemCount)
        {
            currentState = ITEM_SELECTED;
        }
        else
        {
            printf("Invalid selection. Try again.\n");
            currentState = MONEY_INSERTED;
        }
        break;

    case ITEM_SELECTED:
        if (insertedMoney >= items[selectedItemIndex].price)
        {
            currentState = DISPENSE;
        }
        else
        {
            printf("Insufficient funds. Please insert more money:\n");
            int extraMoney;
            scanf("%d", &extraMoney);
            insertedMoney += extraMoney;
        }
        break;

    case DISPENSE:
        printf("Dispensing %s...\n", items[selectedItemIndex].name);
        insertedMoney -= items[selectedItemIndex].price;

        if (insertedMoney > 0)
        {
            currentState = CHANGE;
        }
        else
        {
            currentState = IDLE;
        }
        break;

    case CHANGE:
        printf("Returning change: %d cents\n", insertedMoney);
        printf("\n****************\n");
        printf("Thank you so much for shopping with us!\n");
        printf("Please visit again. Have a great day! 😊\n");
        printf("**************\n\n");
        insertedMoney = 0; // Reset money for the next customer
        currentState = IDLE;
        break;
    }
}

int main()
{
    while (1)
    {
        vendingMachineFSM();
    }
    return 0;
}