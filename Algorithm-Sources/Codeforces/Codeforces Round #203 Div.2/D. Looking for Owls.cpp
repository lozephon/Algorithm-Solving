#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

struct Segment {
    int x1, y1;
    int x2, y2;
    double slope;
    double length;
    long long iSlope;
};

struct Circle {
    int x, y, r;
};

struct Center {
    long long nSame;
    double slope;
    double x, y;
    //vector<pair<double, double> > *ps;
};

inline double getDist(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
const long long vSlope = 9999900000000000L;

#define ENABLE_LOG 0

#if ENABLE_LOG
    #define log printf
#else
    #define log(...)
    #define freopen(...)
#endif

int main() {
    freopen("input.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);

    vector<Segment> lines;
    for(int i = 0;i<n;i++) {
        Segment s;
        scanf("%d%d%d%d", &s.x1, &s.y1, &s.x2, &s.y2);
        if(s.x2 == s.x1)
            s.slope = 99999;
        else
            s.slope = ((double)s.y2-s.y1)/(s.x2-s.x1);
        s.length = sqrt((s.x1 - s.x2)*(s.x1 - s.x2) + (s.y1 - s.y2)*(s.y1 - s.y2));
        s.iSlope = s.slope * 100000000000L;
        log("%lld %.10lf\n", s.iSlope, s.slope);
        lines.push_back(s);
    }

    vector<Circle> circles;
    //vector<Center> cs;
    map<long long, vector<Center>* > cs;
    for(int i = 0;i<m;i++) {
        Circle c;
        scanf("%d%d%d", &c.x, &c.y, &c.r);
        circles.push_back(c);
    }
    
    for(int i = 0;i<m;i++) {
        for(int j = i+1;j<m;j++) {
            if(circles[i].r == circles[j].r) {
                double dist = sqrt((circles[i].x - circles[j].x)*(circles[i].x - circles[j].x) + (circles[i].y - circles[j].y)*(circles[i].y - circles[j].y));
                if(dist - circles[i].r * 2.0 <= 1e-6) {

                }
                else {
                    Center c;
                    if(circles[j].x - circles[i].x == 0)
                        c.slope = 99999;
                    else
                        c.slope = ((double)circles[j].y - circles[i].y) / (circles[j].x - circles[i].x);
                    
                    long long iSlope = c.slope * 100000000000L;
                    //log("%lld, %.10lf\n", iSlope, c.slope);
                    c.x = (circles[j].x + circles[i].x)/2.0;
                    c.y = (circles[j].y + circles[i].y)/2.0;
                    c.nSame = 1;
                    if(cs.find(iSlope) == cs.end())
                        cs[iSlope] = new vector<Center>();
                    bool isSameCenter = false;
                    for(int k = 0;k<cs[iSlope]->size();k++) {
                        Center &c2 = (*cs[iSlope])[k];
                        if(fabs(c.x - c2.x) < 1e-7 && fabs(c.y - c2.y) < 1e-7) {
                            isSameCenter = true;
                            c2.nSame++;
                            break;
                        }
                    }
                    if(!isSameCenter)
                        cs[iSlope]->push_back(c);
                }
            }
        }
    }
    
    for(map<long long, vector<Center>* >::iterator i = cs.begin();i != cs.end();i++) {
        for(int j = 0;j<(*i).second->size();j++) {
            Center &c = (*((*i).second))[j];
            log("%lld %.14lf %lf %lf\n", (*i).first, c.slope, c.x, c.y);
        }
    }
    
    long long ans = 0;
    for(int i = 0;i<n;i++) {
        Segment &s = lines[i];
        
        long long crossSlope;
        if(s.iSlope == 0)
            crossSlope = vSlope;
        else if(s.iSlope == vSlope)
            crossSlope = 0;
        else {
            crossSlope = (-1.0 / s.slope) * 100000000000L;
        }
        log("%lld\n", crossSlope);
        
        if(cs.find(crossSlope) == cs.end()) continue;
        
        for(int j = 0;j<cs[crossSlope]->size();j++) {
            Center &c = (*cs[crossSlope])[j];
            log("%lf %lf\n", c.x, c.y);
            double d1 = getDist(c.x, c.y, s.x1, s.y1);
            double d2 = getDist(c.x, c.y, s.x2, s.y2);
            double isSeg = s.x2*c.y - s.x1*c.y - s.x2*s.y1 + s.x1*s.y1 - s.y2*c.x + s.y1*c.x + s.y2*s.x1 - s.y1 * s.x1;
            log("%lf %lf %lf %lf\n", d1, d2, s.length, isSeg);
            if(s.length - d1 > -1e-7 && s.length - d2 > -1e-7 && fabs(isSeg) < 1e-7)
                ans += c.nSame;
        }
        
    }
    
    cout << ans << endl;
}