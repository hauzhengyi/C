#include<stdio.h>

void add(double, double);
void subtract(double, double);
void multiply(double, double);
void divide(double, double);

int main()
{
    void (*func[4])(double, double) = {add, subtract, multiply, divide};
    int op;
    double float a, b;
    printf("Enter 0 to add, 1 to subtract, 2 to multiply, 3 to divide, 4 to end: ");
    scanf("%d", &op);
    if(op == 4) return 0;

    printf("Enter 2 numbers (separated by a space): ");
    scanf("%lf %lf", &a, &b);

    (*func[op])(a, b);
}

void add(double a, double b)
{
    printf("%lf + %lf is %lf", a, b, a + b);
}

void subtract(double a, double b)
{
    printf("%lf - %lf is %lf", a, b, a - b);
}

void multiply(double a, double b)
{
    printf("%lf * %lf is %lf", a, b, a * b);
}

void divide(double a, double b)
{
    if(!b) printf("error");
    else printf("%lf / %lf is %lf", a, b, a / b);
}
