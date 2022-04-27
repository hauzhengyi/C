#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Exam{
    int credit;
    char grade;
    char code[25];
    struct Exam *next;
};

struct Exam * InsertNode(int credit, char grade, char code[])
{
    struct Exam *node;
    node = (struct Exam *)malloc(sizeof(struct Exam));
    node->credit = credit;
    node->grade = grade;
    strcpy(node->code, code);
    return node;
};

int main(void)
{
    struct Exam *head = NULL;
    struct Exam *curr = NULL;
    head = InsertNode(0, '\0', " ");
    curr = head;

    curr->next = InsertNode(3, 'A', "CST105");
    curr = curr->next;
    curr->next = InsertNode(2, 'B', "CST106");
    curr = curr->next;
    curr->next = InsertNode(4, 'A', "CST107");
    curr = curr->next;
    curr->next = NULL;

    curr = head;
    printf(" Code\tGrade\tCredit\n");
    while(curr->next != NULL)
    {
        printf("%s\t%3c\t%3d\n", curr->next->code, curr->next->grade, curr->next->credit);
        curr = curr->next;
    }
}
