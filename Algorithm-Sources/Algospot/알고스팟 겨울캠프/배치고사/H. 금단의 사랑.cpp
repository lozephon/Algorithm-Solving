// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - Simple Geometry
// Difficulty - 1
// Etc - 원끼리 떨어져 있는 상태, 겹쳐있는 상태, 한 원이 다른 원 안에 들어간 상태로 나누어 본다.

#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
        double a, b, c, p, q, r;
        scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &p, &q, &r);
        
        double dist = sqrt((a-p)*(a-p)+(b-q)*(b-q));
        if(dist >= (c+r) - 1e-9) 
            printf("%.4lf\n", dist-c-r);
        else if(dist < (c+r) && dist > fabs(c-r))
            printf("%.4lf\n", 0.0);
        else
            printf("%.4lf\n", max(c, r) - dist - min(c, r));
    }
}