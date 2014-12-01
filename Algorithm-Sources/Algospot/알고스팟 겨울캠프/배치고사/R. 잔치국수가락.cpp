// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - Simple Geometry
// Difficulty - 2
// Etc - 선분 위에 점이 있는가.

#include<stdio.h>
#include<math.h>

struct point {
    double x, y;
};

double distP2P(point &p, point &q) {
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}

struct line {
    double a, b, c, len;
    point fr, to;
    
    line() {};
    line(double _a, double _b, double _c) {
        a = _a; b = _b; c = _c;
        len = -1;
    };
    line(point &_fr, point &_to) {
        fr = _fr; to = _to;
        a = to.y - fr.y;
        b = fr.x - to.x;
        c = -fr.x*to.y+fr.y*to.x;
        len = distP2P(fr, to);
    };
};


bool isOnTheLine(line &l, point &p) {
    if(fabs(l.a * p.x + l.b * p.y + l.c) <= 1e-9) {
        if(distP2P(l.fr, p) <= l.len + 1e-9 && distP2P(l.to, p) <= l.len + 1e-9)
            return true;
    }
    return false;
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        point p[3];
        for(int i = 0;i<3;i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        
        line l(p[0], p[1]);
        
        printf("%s\n", isOnTheLine(l, p[2]) ? "YES" : "NO");
    }
}
