#include <stdio.h>

void main (void)
{
    int i,j=0,b[9]={0};
    char a[9];
    printf("Insert a byte in binary.\n");
    scanf("%s",a);


    for(i=0;i<=7;i++)
    {
        b[i+1]=((a[i]-'0')==0)?1:0;
        printf("%d",b[i+1]);
    }
    printf("\n");


    b[8]+=1;
    for(i=8;i>=0;i--)
    {
        if((b[i]+j)>1) {b[i]=0;j=1;}
        else {b[i]+=j;j=0;}
    }
    printf("\n");


    for(i=0;i<=2;i++)
    {
        printf("%d",(b[i*3]*4)+(b[(i*3)+1]*2)+(b[(i*3)+2]));
    }
    return 0;
}
