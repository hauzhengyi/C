#include<stdio.h>

void func(char **p)
{
    printf("%s", *p);
}

int main()
{
    char *p = "Hello World!";
    func(&p);
}
