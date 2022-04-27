#include<stdio.h>

void specialSort(int array[], int *length);

int main()
{
    int l1, l2, i;
    scanf("%d %d", &l1, &l2);
    int a[l1], b[l2];

    for(i = 0; i < l1; i++)
        scanf("%d", a+i);
    for(i = 0; i < l2; i++)
        scanf("%d", b+i);

    specialSort(a, &l1);
    specialSort(b, &l2);

    int *p = a, *q = b, *r = &a[l1 - 1], *s = &b[l2 - 1], c[l1 + l2];

    for(i = 0; i < l1 + l2; i++)
    {
        if(*p > *q && q <= s || p > r)
        {
            c[i] = *q;
            q++;
        }
        else
        {
            c[i] = *p;
            p++;
        }
        printf("%d ", c[i]);
    }
}

specialSort(int array[], int *length)
{
    int i, j;
    for(i = 0; i < *length; i++)
    {
        for(j = 1; j + i < *length; j++)
        {
            if(array[i] == array[i + j])
            {

            }
        }
    }
}
