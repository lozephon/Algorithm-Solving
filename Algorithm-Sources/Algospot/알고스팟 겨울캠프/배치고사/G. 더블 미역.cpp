// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - Implementation
// Difficulty - 2
// Etc - x, y별로 위치관계에 따라 겹치는 부분 길이를 구한 후 곱하면 된다.

#include<stdio.h>
#include<algorithm>
using namespace std;

struct point {
    int x, y;
    point() {};
    point(int _x, int _y) {
        x = _x;
        y = _y;
    };
};

struct rect {
    point ul, ur, dl, dr;
    rect() {};
    rect(point &p, point &q) { // 대각선을 이루는 두 점
        int minX = min(p.x, q.x), maxX = max(p.x, q.x), minY = min(p.y, q.y), maxY = max(p.y, q.y);
        ul = point(minX, minY);
        ur = point(maxX, minY);
        dl = point(minX, maxY);
        dr = point(maxX, maxY);
    };
};

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        point p[4];
        for(int i = 0;i<4;i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        
        rect r1(p[0], p[1]), r2(p[2], p[3]);
        
        int width = 0, height = 0;
        
        if(r1.dr.y > r2.dr.y)
            swap(r1, r2);
        if(r1.dr.y < r2.ur.y)
            height = 0;
        else if(r1.ur.y > r2.ur.y)
            height = r1.dr.y - r1.ur.y;
        else
            height = r1.dr.y - r2.ur.y;
    
        if(r1.dr.x > r2.dr.x)
            swap(r1, r2);
        if(r2.dl.x > r1.dr.x)
            width = 0;
        else if(r2.dl.x < r1.dl.x)
            width = r1.dr.x - r1.dl.x;
        else
            width = r1.dr.x - r2.dl.x;
        
        printf("%d\n", width*height);
    }
}