struct Point {
	double x, y;
	Point() {};
	Point(double _x, double _y) {
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
    line(point &_fr, point &_to) {
        fr = _fr; to = _to;
        a = to.y - fr.y;
        b = fr.x - to.x;
        c = -fr.x*to.y+fr.y*to.x;
        len = distP2P(fr, to);
    };
};

double getLen(Point a, Point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double getAngle(Point a, Point b) {
	return atan2(b.y-a.y, b.x-a.x);
}

int isCCW(Point a, Point b, Point c) {
	int temp;
	temp  = a.x*b.y - b.x*a.y;
	temp += b.x*c.y - c.x*b.y;
	temp += c.x*a.y - a.x*c.y;
	
	if(temp > 1e-9) return 1;
	else if(temp < -1e-9) return -1;
	return 0;
}

bool isOnTheSegment(Point st, Point ed, Point p) {
#define maxf(x, y) x > y-1e-9 ? x : y
#define minf(x, y) x < y+1e-9 ? x : y
	Point tSt(minf(st.x, ed.x), minf(st.y, ed.y)), tEd(maxf(st.x, ed.x), maxf(st.y, ed.y));
	if(p.x > tSt.x - 1e-9 && p.x < tEd.x + 1e-9 && p.y > tSt.y - 1e-9 && p.y < tEd.y + 1e-9) {
		if(fabs((ed.y-st.y)*(p.x-st.x) - (ed.x-st.x)*(p.y-st.y)) < 1e-9)
			return true;
	}
	return false;
}

bool isCross(Point p1, Point p2, Point t1, Point t2, bool checkOnTheSegment) {
	int ppt, ttp;
	ppt = isCCW(p1, p2, t1) * isCCW(p1, p2, t2);
	ttp = isCCW(t1, t2, p1) * isCCW(t1, t2, p2);
	
	if(ppt < 0 && ttp < 0)
		return true;
	else if(checkOnTheSegment)
		return isOnTheSegment(p1, p2, t1) || isOnTheSegment(p1, p2, t2) || isOnTheSegment(t1, t2, p1) || isOnTheSegment(t1, t2, p2);
	
	return false;
}

Point getCrossPoint(Line a, Line b, bool &is) {
	Point cp;
	if(fabs(a.b*b.a - a.a*b.b) < 1e-9)
		is = false;
	else {
		cp.x = (a.c*b.b - b.c*a.b) / (a.b*b.a - a.a*b.b);
		cp.y = (a.a*b.c - a.c*b.a) / (a.b*b.a - a.a*b.b);
		is = true;
	}
	
	return cp;
}
