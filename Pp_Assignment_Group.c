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
    while(temp->next != NULL)
    {
        printf("%s\t\tRM %.2f\n", temp->next->name, temp->next->price);
        temp = temp->next;
    }
    printf("Inventory:\tRM %.2f\n", inventory);
    printf("Total sales:\tRM %.2f\n", sales);
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
    int option = 0, exit = 0;
    char name[NAMESIZE];
    float price, inventory = 0, sales = 0;
    head = createNode("", 0);
    head->next = NULL;

    printf("STOCK INVENTORY SYSTEM V1.0.0\n");
    printf("WELCOME TO PP HARDWARE STORE!\n");
    printf("1 - Enter new item and its price\n");
    printf("2 - Display total number of items\n");
    printf("3 - Enter a stock item to sell\n");
    printf("4 - Exit\n");

    while(exit != 1)
    {
        printf("\nEnter choice: ");
        scanf(" %d", &option);

        switch(option)
        {
            case 1: printf("Enter item name: ");
                    scanf(" %30s", name);
                    printf("Enter price: ");
                    scanf(" %f", &price);
                    insertItem(name, price);
                    inventory += price;
                    displayStock(inventory, sales);
                    break;

            case 2: if(checkEmpty())
                        printf("The list is empty.\n");
                    else
                        printf("The number of items in stock is %d.\n", countItems());
                    break;

            case 3: printf("Enter item name to sell: ");
                    scanf(" %30s", name);
                    if(sell(name, &inventory, &sales))
                    {
                        printf("Item sold.\n");
                        displayStock(inventory, sales);
                    }
                    else
                        printf("Item not found in inventory.\n");
                    break;

            case 4: exit = 1;
                    continue;

            default: printf("Invalid choice.\n");
        }
    }
}
