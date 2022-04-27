#include<stdio.h>

typedef struct LLNode{
    int data;
    struct LLNode *next;
} LLNode;

int checkEmpty(LLNode *head)
{
    return head->next == NULL? 1 : 0;
}

void push(LLNode *head, int data)
{
    LLNode *node;
    node = (LLNode *)malloc(sizeof(LLNode));
    node->data = data;
    node->next = head->next;
    head->next = node;
}

int pop(LLNode *head)
{
    LLNode *node;
    int data;
    node = head->next;
    data = node->data;
    head->next = node->next;
    free(node);
    return data;
}

void display(LLNode *head)
{
    LLNode *temp;
    temp = head;
    printf("Content in stack: ");
    while(temp->next != NULL)
    {
        printf("%d ", temp->next->data);
        temp = temp->next;
    }
    printf("\n");
}

void counting(LLNode *head)
{
    int total = 0;
    LLNode *temp;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
        total++;
    }
    printf("Number of item(s) in stack: %d\n", total);
}

int main()
{
    LLNode *head;
    head = (LLNode *)malloc(sizeof(LLNode));
    head->next = NULL;
    int option, data, exit = 1;

    while(exit)
    {
        printf("Enter choice: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("Enter data: ");
            scanf(" %d", &data);
            push(head, data);
            break;

        case 2:
            if(checkEmpty(head))
                printf("Stack empty, nothing can be popped\n");
            else
                printf("Value popped: %d\n", pop(head));
            break;

        case 3:
            if(checkEmpty(head))
                printf("Stack empty\n");
            else
                counting(head);
            break;

        case 4:
            exit = 0;
            break;
        }
        if(head->next == NULL)
            printf("Stack empty\n");
        else
            display(head);
        printf("\n");
    }
}
