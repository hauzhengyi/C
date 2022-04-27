#include<stdio.h>
#include<math.h>
#include<time.h>

int primeTime1(int n)
{
    int i;
    for(i = 2; i < n; i++)
        if(!(n % i)) return 0;
    return 1;
}

int primeTime2(int n)
{
    int i;
    for(i = 2; i <= sqrt(n); i++)
        if(!(n % i)) return 0;
    return 1;
}

int main(void)
{
    int n, i, total;
    scanf("%d", &n);

    clock_t t;
    total = 0;
    t = clock();
    for(i = 2; i < n; i++)
        if(primeTime1(i)) total++;
    t = clock() - t;
    printf("time: %.3fs\n", ((float)t)/CLOCKS_PER_SEC);

    total = 0;
    t = clock();
    for(i = 2; i < n; i++)
        if(primeTime2(i)) total++;
    t = clock() - t;
    printf("time: %.3fs", ((float)t)/CLOCKS_PER_SEC);
}
