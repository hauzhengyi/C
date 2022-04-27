#include<stdio.h>

int fact(int n)
{
    if(n == 0) return 1; //special case, zero factorial equals to one
    if(n == 1) return 1; //the terminating factor
    return n * fact(n-1);
}

int main()
{
    int n, i, fac = 1;
    printf("Insert an integer: "); //prompt input from the user
    scanf(" %d", &n); //store it in variable n

    for(i = 1; i <= n; i++)
        fac *= i;
    printf("Factorial of %d by iterative approach: %d\n", n, fac);
    printf("Factorial of %d by recursive approach: %d\n", n, fact(n));
}
