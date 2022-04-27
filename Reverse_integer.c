#include<stdio.h>

int main()
{
    int x, res=0;
    scanf("%d", &x);
    while(x>0)
    {
        res *= 10;
        res += x%10;
        x /= 10;
    }
    printf("%d", res);
}
