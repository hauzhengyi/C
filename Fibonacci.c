#include<stdio.h>

int fib(int x);

int main()
{
    int x, i;
    for(i = 0; i <20; i++)
    printf("%d\n", fib(i));
}

int fib(int x)
{
    if(x == 1) return x;
    else if(x < 1) return 0;
    else return fib(x - 1) + fib(x - 2);
}
