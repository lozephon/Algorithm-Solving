// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - Simple Geometry
// Difficulty - 2
// Etc - 점과 직선 사이의 거리, r은 음수도 가능

#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    int t;
    scanf("%d", &t);
    
    while(t--) {
        double a, b, c, p, q, r;
        
        scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &p, &q, &r);
        double d = fabs(a*p+b*q+c)/sqrt(a*a+b*b);
        r = fabs(r);
        printf("%.4lf\n", d > r ? d-r : 0);
    }
}