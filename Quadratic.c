#include<stdio.h>
#include<math.h>

void positive(float a,float b,float c);
void zero(float a,float b,float c);
void negative(float a,float b,float c);

void main(void)
{
    float a,b,c,q;
    printf("ax^2+bx+c.\na=?");
    scanf("%f",&a);
    printf("b=?");
    scanf("%f",&b);
    printf("c=?");
    scanf("%f",&c);

    q=((b*b)-(4*a*c));

    if(q>0)
    {
        positive(a,b,c);
    }
    if(q==0)
    {
        zero(a,b,c);
    }
    if(q<0)
    {
        negative(a,b,c);
    }
}

void positive(float a,float b,float c)
{
    printf("The answer is %f and %f.\n",(-b+sqrt((b*b)-(4*a*c)))/(2*a),(-b-sqrt((b*b)-(4*a*c)))/(2*a));
}

void zero(float a,float b,float c)
{
    printf("The answer is %f.\n",(-b)/(2*a));
}

void negative(float a,float b,float c)
{
    printf("The answer is %f+%fi and %f-%fi.\n",(-b)/(2*a),sqrt((4*a*c)-(b*b))/(2*a),(-b)/(2*a),sqrt((4*a*c)-(b*b))/(2*a));
}
