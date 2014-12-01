#include<stdio.h>
#include<math.h>

double getLength(int x, int y, int x2, int y2)
{
    return sqrt((double)(x - x2) * (x - x2) + (double)(y - y2) * (y - y2));
}
double getAngle(int x, int y, int x2, int y2)
{
    double a = getLength(x, y, x2, y2);
    double b = getLength(0, 0, x, y);
    double c = getLength(0, 0, x2, y2);
    
    return acos((b*b + c*c - a*a) / (2 * b * c));
}

int main()
{
    int n;
    scanf("%d", &n);
    
    double angle = 0.0;
    int lx, ly, rx, ry;
    scanf("%d%d", &lx, &ly);
    rx = lx; ry = ly;
    
    for(int i = 1;i<n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        
        double angleLeft = getAngle(x, y, lx, ly);
        
        
        double angleRight = getAngle(x, y, rx, ry);
    }
    
    printf("%lf\n", angle);
}