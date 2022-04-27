#include <stdio.h>

typedef struct complex{
    float real;
    float imag;
} comp;

comp addComplex(comp a, comp b)
{
    comp c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

int main(void)
{
    comp a, b, c;
    scanf("%f %f", &a.real, &a.imag);
    scanf("%f %f", &b.real, &b.imag);
    c = addComplex(a, b);
    printf("%.1f + %.1fi", c.real, c.imag);
}
