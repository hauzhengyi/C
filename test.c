#include <stdio.h>
#define n 9

int main() {    int numbers[n]  = {12,  3,  5,   6, 2, 7, 81, 23, -1};  int *ptr,  i,  j, temp;  ptr = numbers;

 for (i = 0;  i<n; i++)  {   for  (j = 0; j<n; j++)   {    if  (*(ptr+i)  > *(ptr+j))    {    temp = *(ptr+i);    *(ptr+i)  = *(ptr+j);    *(ptr+j)  = temp;    }   }  }  for (i = 0;  i<6; i++)   printf("%d %d ",   *(ptr+i),  *(ptr+i)  -n * 10);  return 0; }
