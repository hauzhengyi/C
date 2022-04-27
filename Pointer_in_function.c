#include<stdio.h>

swap(int *p1,int *p2)
{
    int p;
    p=*p1;
    *p1=*p2;
    *p2=p;
}

main()
{
    int a,b;
    int *ip1,*ip2;
    scanf("%d %d",&a,&b);
    ip1=&a; ip2=&b;
    if(a<b)swap(ip1,ip2);
    printf("\n%d,%d\n",a,b);
}
