#include<stdio.h>

void main (void)
{
    char a[500],b[500],c[1000];
    int i,j;
    printf("Insert first string.\n");
    gets(a);
    printf("Insert second string.\n");
    gets(b);
    for(i=0;a[i]!='\0';i++)
    {
        c[i]=a[i];
    }
    for(j=0;b[j]!='\0';j++)
    {
        c[i++]=b[j];
    }
    c[i]='\0';
    puts(c);
}
