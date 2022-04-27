#include<stdio.h>
#include<string.h>
#define NAMESIZE 30

typedef struct LLNode{
    char name[NAMESIZE];
    float price;
    struct LLNode *next;
    struct LLNode *prev;
} LLNode;

LLNode *head;

LLNode * createNode(char name[], float price)
{
    LLNode *node;
    node = (LLNode *)malloc(sizeof(LLNode));
    strcpy(node->name, name);
    node->price = price;
    return node;
}

void insertItem(char name[], float price)
{
    LLNode *node, *temp;
    node = createNode(name, price);
    temp = head;
    while(temp->next != NULL && temp->next->price > price)
        temp = temp->next;
    node->next = temp->next;
    node->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = node;
    temp->next = node;
}

int checkEmpty()
{
    return head->next == NULL? 1 : 0;
}

void displayStock(float inventory, float sales)
{
    LLNode *temp;
    temp = head;
    printf("\tItem\t\tPrice\n");
    while(temp->next != NULL)
    {
        printf("\t%s\t\tRM %.2f\n", temp->next->name, temp->next->price);
        temp = temp->next;
    }
    printf("\n\tInventory:\tRM%.2f\n", inventory);
    printf("\tTotal sales:\tRM%.2f\n", sales);
}

int countItems()
{
    int total = 0;
    LLNode *temp;
    temp = head;
    while(temp->next != NULL)
    {
        total++;
        temp = temp->next;
    }
    return total;
}

void deleteNode(LLNode *node)
{
    float price;
    LLNode *temp;
    price = node->price;
    temp = node->prev;
    temp->next = node->next;
    if(node->next != NULL)
        node->next->prev = temp;
    free(node);
}

int sell(char name[], float *inventory, float *sales)
{
    LLNode *temp;
    temp = head;
    while(temp->next != NULL)
    {
        if(!strcmp(name, temp->next->name))
        {
            *inventory -= temp->next->price;
            *sales += temp->next->price;
            deleteNode(temp->next);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    system("color F0");
    int option = 0, exit = 0;
    char name[NAMESIZE];
    float price, inventory = 0, sales = 0;
    head = createNode("", 0);
    head->next = NULL;

    while(exit != 1)
    {
        system("cls");
        printf("********* STOCK INVENTORY SYSTEM V1.0.0 *********\n");
        printf("========= WELCOME TO PP HARDWARE STORE! =========\n\n");
        printf("      [ 1 - Enter new item and its price  ]\n");
        printf("      [ 2 - Display total number of items ]\n");
        printf("      [ 3 - Enter a stock item to sell    ]\n");
        printf("      [ 4 - Exit                          ]\n\n");
        printf("=================================================\n\n");
        displayStock(inventory, sales);
        printf("\n=================================================\n\n");

        switch(option)
        {
            case 0: break;

            case 1: printf("\tEnter item name: ");
                    scanf(" %30s", name);
                    printf("\tEnter price: ");
                    scanf(" %f", &price);
                    insertItem(name, price);
                    inventory += price;
                    option = 0;
                    continue;

            case 2: if(checkEmpty())
                        printf("\tThe list is empty.\n");
                    else
                        printf("\tThe number of items in stock is %d.\n", countItems());
                    break;

            case 3: printf("\tEnter item name to sell: ");
                    scanf(" %30s", name);
                    if(sell(name, &inventory, &sales))
                    {
                        option = 0;
                        continue;
                    }
                    else
                    {
                        printf("\n\tItem not found in inventory.\n");
                        break;
                    }

            case 4: printf("\tThank you, please rate 5 stars =)\n");
                    printf("\n\t\t    * * * * * \n");
                    printf("\n=================================================\n");
                    exit = 1;
                    continue;

            default: printf("\tInvalid choice.\n");
        }

        printf("\n=================================================\n");

        printf("\n\tEnter choice: ");
        scanf(" %d", &option);
        printf("\n");
    }
    system("pause");
}
