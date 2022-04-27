#include<stdio.h>
#include<math.h>

float p(int n,int x);

void main(void)
{
    int x,n;
    printf("Enter n then x.\n");
    scanf("%d %d",&n,&x);
    printf("P%d(%d)=%f.\n",n,x,p(n,x));
}

float p(int n,int x)
{
    if(n==0){return 1;}
    if(n==1){return x;}
    if(n>=1){return (((2*n-1)*x)-p(n-1,x)-((n-1)*p(n-2,x)/n));}
}
