#include<stdio.h>
#define SIZE 50

typedef struct LLNode{
    char string[SIZE];
    struct LLNode *next;
} LLNode;

LLNode * createNode(char val[])
{
    LLNode *node;
    node = (LLNode *)malloc(sizeof(LLNode));
    strcpy(node->string, val);
    return node;
}

void enqueue(LLNode *head, char val[]) //inserts a new node at the rear of the linked list
{
    LLNode *node, *temp; //temp is a pointer used to traverse the linked list
    node = createNode(val);
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    node->next = temp->next;
    temp->next = node;
}

void search(LLNode *head, char val[])
{
    LLNode *ptr = head;
    int number = 1;
    while(ptr->next != NULL)
    {
        if(strcmp(ptr->next->string, val) == 0)
        {
            printf("\nThe string \"%s\" is found in node %d\n", val, number);
            break;
        }
        number++;
        ptr = ptr->next;
    }
    if(ptr->next == NULL)
        printf("\nWord not found\n");
}

void display(LLNode *head)
{
    LLNode *ptr = head;
    int number = 1;
    printf("\n");
    if(ptr->next == NULL)
    {
        printf("List empty\n");
        return;
    }
    while(ptr->next != NULL)
    {
        printf("%d %s\n", number++,ptr->next->string);
        ptr = ptr->next;
    }
}

int main()
{
    int option;
    char val[SIZE]; //val is the string to be inserted or searched
    LLNode *head, *ptr;
    head = (LLNode *)malloc(sizeof(LLNode));
    head->next = NULL;

    while(1) //the menu keeps looping until the selection of exit breaks the loop
    {
        printf("\nSelect an option:\n");
        printf("1. Create a new node\n");
        printf("2. Search a word\n");
        printf("3. Display the linked list\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        if(option == 1)
        {
            printf("\nEnter a string:\n");
            scanf("%50s", val);
            enqueue(head, val);
            continue;
        }

        if(option == 2)
        {
            printf("\nEnter a word to search:\n");
            scanf("%50s", val);
            search(head, val);
            continue;
        }

        if(option == 3)
        {
            display(head);
            continue;
        }

        if(option == 4)
        {
            break;
        }
    }
}
