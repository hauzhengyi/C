#include<stdio.h>
#include<windows.h>

int main()
{
    int i, j, k = 1, l = 1;
    char *p, *a= "Ian sucks...";

    for(p = a; *p != '\0'; p++)
        {
            printf("%c", *p);
            Sleep(30);
        }
    printf("\n");

    for(i = 1; i<100; i++)
    {
        if(!(i%10)) l = -l;
        for(j = 0; j < k; j++) printf("\t");
        k += l;

        for(p = a; *p != '\0'; p++)
        {
            printf("%c", *p);
            Sleep(30);
        }
        printf("\n");

    }

    return 0;
}
