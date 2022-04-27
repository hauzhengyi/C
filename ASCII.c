#include<stdio.h>

int main()
{
    int i, bnr;

    printf("ASCII\n\n");
    for(i=0; i<256; i++)
    {
        bnr = 0;
        bnr += i%2;
        bnr += (i/2%2)*10;
        bnr += (i/2/2%2)*100;
        bnr += (i/2/2/2%2)*1000;
        bnr += (i/2/2/2/2%2)*10000;
        bnr += (i/2/2/2/2/2%2)*100000;
        bnr += (i/2/2/2/2/2/2%2)*1000000;
        bnr += (i/2/2/2/2/2/2/2%2)*10000000;
        printf("%d\t%c\t%d\n",i,i,bnr);
    }
    system("pause");
    return 0;
}
