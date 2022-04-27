#include<stdio.h>

typedef struct LLNode{
    char value;
    struct LLNode *right;
    struct LLNode *left;
}LLNode;

LLNode * createNode(char value)
{
    LLNode *node;
    node = (LLNode *)malloc(sizeof(LLNode));
    node->value = value;
    return node;
}

void insertLeft(LLNode *center, char value)
{
    LLNode *newNode, *edgeNode;
    edgeNode = center;
    while(edgeNode->left != NULL)
        edgeNode = edgeNode->left;
    newNode = createNode(value);
    newNode->left = edgeNode->left;
    newNode->right = edgeNode;
    edgeNode->left = newNode;
}

void insertRight(LLNode *center, char value)
{
    LLNode *newNode, *edgeNode;
    edgeNode = center;
    while(edgeNode->right != NULL)
        edgeNode = edgeNode->right;
    newNode = createNode(value);
    newNode->right = edgeNode->right;
    newNode->left = edgeNode;
    edgeNode->right = newNode;
}

void display(LLNode *center)
{
    LLNode *ptr;
    ptr = center;
    while(ptr->left != NULL)
        ptr = ptr->left;
    printf("\nNode's value from left to right is: ");
    while(ptr != NULL)
    {
        printf("%c ", ptr->value);
        ptr = ptr->right;
    }
}

int main()
{
    LLNode *center;
    char value;
    int option;
    center = (LLNode *)malloc(sizeof(LLNode));
    center->left = center->right = NULL;
    printf("Enter initial value: ");
    scanf("%c", &(center->value));
    while(1)
    {
        printf("Add node towards [1] Left; [2] Right: ");
        scanf("%d", &option);
        if(option == 1)
        {
            printf("Enter value towards the left: ");
            scanf(" %c", &value);
            insertLeft(center, value);
        }
        else if(option == 2)
        {
            printf("Enter value towards the right: ");
            scanf(" %c", &value);
            insertRight(center, value);
        }
        else
        {
            break;
        }
    }
    display(center);
}
