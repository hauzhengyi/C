#include<stdio.h>

void add(int, int);
void subtract(int, int);
void multiply(int, int);
void divide(int, int);

int main()
{
    int a, b, choice;

    void (*f[4])(int, int) = {add, subtract, multiply, divide};

    puts("Enter 0 to add, 1 to subtract, 2 to multiply, 3 to divide, 4 to end:");
    scanf("%d", &choice);
    puts("Enter 2 numbers:");
    scanf("%d %d", &a, &b);

    (f[choice])(a, b);
}

void add(int a, int b)
{
    printf("a + b is %d\n", a + b);
}

void subtract(int a, int b)
{
    printf(" a - b is %d\n", a - b);
}

void multiply(int a, int b)
{
    printf(" a * b is %d\n", a * b);
}

void divide(int a, int b)
{
    printf(" a / b is %d\n", a / b);
}
