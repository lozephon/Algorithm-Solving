// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(1)
// Type - Simple Geometry
// Difficulty - 2
// Etc - 두 직선의 교점, 세 점을 알 때 삼각형의 넓이(헤론의 공식)

#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

struct line {
    double a, b, c;
    line() {};
    line(double _a, double _b, double _c) {
        a = _a; b = _b; c = _c;
    };
};

struct point {
    double x, y;
};

int getCP(line &p, line &q, point &cp) {
    if(p.a*q.b == p.b*q.a)
        return 1;
    
    cp.x = (p.c*q.b-p.b*q.c)/(p.b*q.a-p.a*q.b);
    cp.y = (p.a*q.c-p.c*q.a)/(p.b*q.a-p.a*q.b);

    return 0;
};

double getTriangle(point p1, point p2, point p3) {
    return 0.5 * fabs(p1.x*p2.y-p2.x*p1.y+p2.x*p3.y-p3.x*p2.y+p3.x*p1.y-p1.x*p3.y);
};

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        line l[3];        
        for(int i = 0;i<3;i++) {
            double a, b, c;
            scanf("%lf%lf%lf", &a, &b, &c);
            l[i] = line(a, b, c);
        }
        
        point p[3];
        if(getCP(l[0], l[1], p[0]) || getCP(l[2], l[1], p[1]) || getCP(l[0], l[2], p[2]))
            printf("0.0000\n");
        else 
            printf("%.4lf\n", getTriangle(p[0], p[1], p[2]));
    }
}