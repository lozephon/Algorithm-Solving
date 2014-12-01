#include<stdio.h>
#include<math.h>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<list>
using namespace std;

void temp() {
	list<char> ch;
	list<char>::iterator ichar, iend;
//`	iend = ichar.end();
}
#define E (double)1e-9

struct point {
	double x, y;
	point() {};
	point(double _x, double _y) {
		x = _x; y = _y;
	}
};

struct line {
    double a, b, c, len;
    point fr, to;
    
    line() {};
    line(double _a, double _b, double _c) {
        a = _a; b = _b; c = _c;
        len = -1;
    };
    line(point _fr, point _to) {
        fr = _fr; to = _to;
        a = to.y - fr.y;
        b = fr.x - to.x;
        c = -fr.x*to.y+fr.y*to.x;
    };
};

struct vect {
	point p;
	line l;
	int a, b, y, m, ySum;
	double db;

	vect(int _y, int _a, int _b) {	
		m = 1;
		ySum = _y;
		y = _y;
		a = _a;
		b = _b;
		p = point(0, y);
		db = (double)b/a;
		l = line(p, point(p.x+a, p.y+b));
	};

	const int operator <(const vect &b) const {
		const vect a = *this;
		if(a.y < b.y)
			return 1;
		return 0;
	}
};

point getCrossPoint(line a, line b, int &info) {//, double border) {
	point cp;
	if(fabs(a.b*b.a - a.a*b.b) < E) {
		info = 1;
		if(fabs(a.c/a.b - b.c/b.b) < E) 
			info = 2;
	}
	else {
//		if(fabs((a.c*b.b - b.c*a.b) - (a.b*b.a - a.a*b.b) * border) < E)
//			info = 3;
//		else 
			info = 0;

		cp.x = (a.c*b.b - b.c*a.b) / (a.b*b.a - a.a*b.b);
		cp.y = (a.a*b.c - a.c*b.a) / (a.b*b.a - a.a*b.b);
	}
	
	return cp;
}

void mergeV(vect &a, vect &b) {
	a.m++;
	a.ySum += b.y;
	a.p = point(0, (double)a.ySum/a.m);
	a.db += b.db;
	a.l = line(a.p, point(a.p.x+a.m, a.p.y+a.db));
}

int main() {
	freopen("input.in", "r", stdin);

	int t;
	scanf("%d", &t);

	while(t--) {
		int N;
		double W, H;
		
		printf("temp %d\n", 0x21345678);
		
		scanf("%d%lf%lf", &N, &W, &H);
		
		vector<vect> ps;
		for(int i = 0;i<N;i++) {
			int y, a, b;
			scanf("%d%d%d", &y, &a, &b);

			ps.push_back(vect(y, a, b));
		}
		
		sort(ps.begin(), ps.end());

		vector<double> ys;

		vect nowV = ps[0];
		for(int i = 1;i<N;i++) {
			int info;
			point cp = getCrossPoint(nowV.l, ps[i].l, info);
			if(info == 2 || (info == 0 && cp.x > -E && cp.x < W+E))
				mergeV(nowV, ps[i]);
			else {
				ys.push_back(-nowV.l.a/nowV.l.b*W - nowV.l.c/nowV.l.b);
				nowV = ps[i];
			}
		}
		ys.push_back(-nowV.l.a/nowV.l.b*W - nowV.l.c/nowV.l.b);

		sort(ys.begin(), ys.end());
		printf("%d\n", ys.size());
		for(int i = 0;i<ys.size();i++) 
			printf("%.4lf\n", ys[i]);
	}
}