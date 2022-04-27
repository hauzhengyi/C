#include<stdio.h>
#include<math.h>

double distance(double x1, double x2, double y1, double y2)
{
    return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}

void main(void)
{
    double x1, x2, y1, y2;
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    printf("%.2lf", distance(x1, x2, y1, y2));
}
