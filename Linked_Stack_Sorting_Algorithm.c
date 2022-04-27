#include<stdio.h>

typedef struct stackNode{
    int data;
    struct stackNode *next;
} stackNode;

void push(stackNode *head, int n) //takes in a head node and a number, pushes the number onto the top of the stack
{
    stackNode *p;
    p = (stackNode *)malloc(sizeof(stackNode));
    p->data = n;
    p->next = head->next;
    head->next = p;
    return;
}

int pop(stackNode *head, int *n) //takes in a head node and a variable address, pops the top element and stores in the variable, then returns 1. If the stack is empty, returns 0
{
    stackNode *p;
    p = head->next;
    if(p == NULL) return 0;
    *n = p->data;
    head->next = p->next;
    free(p);
    return 1;
}

int main()
{
    stackNode *head, *thead, *p; //head is the first stack, thead is the secondary stack, p is a node pointer
    head = (stackNode *)malloc(sizeof(stackNode)); //initializing head
    head->next = NULL;
    thead = (stackNode *)malloc(sizeof(stackNode)); //initializing thead
    thead->next = NULL;

    int size, i, tmp, tmp2; // prompting input from user
    printf("Please enter the stack size: ");
    scanf("%d", &size);
    printf("Please insert %d integers: ", size);
    for(i = 0; i < size; i++) //pushing data into the stack
    {
        scanf("%d", &tmp);
        push(head, tmp);
    }

    while(pop(head, &tmp)) //pops the top element from head and stores in tmp, until no elements are left in head
    {
        while(thead->next != NULL && thead->next->data > tmp) //if the top element in thead is larger than tmp, pop it and push it into head
        {
            pop(thead, &tmp2);
            push(head, tmp2);
        }
        push(thead, tmp); //if the top element in thead is not larger than tmp or thead is empty, push tmp into thead
    }

    p = thead;
    while(p->next != NULL) //printing the secondary stack from top to bottom, which is now sorted in descending order
    {
        printf("%d ", p->next->data);
        p = p->next;
    }
}
