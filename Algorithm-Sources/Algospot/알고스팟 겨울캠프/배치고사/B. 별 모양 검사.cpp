#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

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


int isOnTheLine(line &l, point &p) {
    if(fabs(l.a * p.x + l.b * p.y + l.c) <= 1e-9) {
        if(distP2P(p, l.fr) <= 1e-9 || distP2P(p, l.to) <= 1e-9)
            return 1;        
        if(distP2P(l.fr, p) < l.len + 1e-9 && distP2P(l.to, p) < l.len + 1e-9)
            return 2;        
    }
    return 0;
}

int getCP(line &p, line &q, point &cp) {
    if(p.a*q.b == p.b*q.a)
        return 1;
    
    cp.x = (p.c*q.b-p.b*q.c)/(p.b*q.a-p.a*q.b);
    cp.y = (p.a*q.c-p.c*q.a)/(p.b*q.a-p.a*q.b);
    
    return 0;
};

int ccw(point p1, point p2, point p3) {
    double v;
    v  = p1.x * p2.y - p2.x * p1.y;
    v += p2.x * p3.y - p3.x * p2.y;
    v += p3.x * p1.y - p1.x * p3.y;
    
    if(v > 1e-9) return 1; // 시계 방향
    if(v < -1e-9) return -1; // 반시계 방향
    return 0;
}

bool cross(line a, line b) {
    int ppt, ttp;
    ppt = ccw(a.fr, a.to, b.fr) * ccw(a.fr, a.to, b.to);
    ttp = ccw(b.fr, b.to, a.fr) * ccw(b.fr, b.to, a.to);
    return ppt < 0 && ttp < 0;
}

int main() {
//    freopen("input.in", "r", stdin);
    int n;
    while(scanf("%d", &n) == 1 && n != 0) {
        vector<line> l;
        point fr, to, first;
        scanf("%lf%lf", &first.x, &first.y);
        
        fr = first;
        for(int i = 1;i<n;i++) {
            scanf("%lf%lf", &to.x, &to.y);
            l.push_back(line(fr, to));
            fr = to;
        }
        l.push_back(line(fr, first));
        
        vector<point> cp;
        
        for(int i = 0;i<l.size();i++) {
            for(int j = i+1;j<l.size();j++) {
                point p;
                if(getCP(l[i], l[j], p) == 0)
                    cp.push_back(p);
            }
        }
        
        bool isPossible = false;
        for(int i = 0;i<cp.size();i++) {
            int j = 0;
            for(;j<l.size();j++) {
                if(ccw(cp[i], l[j].fr, l[j].to) == -1)
                    break;
            }
            if(j == l.size()) {
                isPossible = true;
                break;
            }
        }
        
        printf("%d\n", isPossible ? 1 : 0);
    }
}