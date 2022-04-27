#include<stdio.h>

void sort(int a[], int size);

int main()
{
    int size, i;
    do{
    printf("Insert array size:\n");
    scanf("%d", &size);
    }
    while(size > 20);
    int a[size];
    printf("Insert %d elements:\n", size);
    for(i = 0; i < size; i++)
        scanf("%d", a+i);
    sort(a, size);
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);
}

void sort(int a[], int size)
{
    int flag = 0, i, j, temp;
    for(i = size - 1; i; i--)
    {
        flag = 0;
        for(j = 0; j < i; j++)
        {
            if(a[j] > a [j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}
