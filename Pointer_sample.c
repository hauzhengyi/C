#include<stdio.h>

int main(void)
{
    int a,b=2,*p,*q;
    scanf("%d",&a);
    p=&a,q=&b;
    printf("a is %d, b is %d\n",a,b);
    printf("&a is %d, &b is %d\n",&a,&b);
    printf("p is %d, q is %d\n",p,q);
    printf("*p is %d, *q is %d",*p,*q);
}

/*The difference between pointers and variables:

    variables: b=1; a=b; b=2;
    output: a=1, b=2

    pointers: a=1; ipa=&a; a=2;
    output: *ipa=2, a=2
*/
