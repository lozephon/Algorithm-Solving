#include<stdio.h>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

struct warm {
	int fr, to, t;
	warm(int _fr, int _to, int _t) {
		fr = _fr; to = _to; t = _t;
	}
};

vector<warm> e;
int d[1000];

int main() {
	freopen("input.in", "r", stdin);
	
	int c;
	scanf("%d", &c);
	
	while(c--) {
		int n, m;
		scanf("%d%d", &n, &m);
		
		e.clear();
		
		for(int i = 0;i<m;i++) {
			int fr, to, time;
			scanf("%d%d%d", &fr, &to, &time);
			e.push_back(warm(fr, to, time));
		}
		
		memset(d, 0x33, sizeof(d));
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<m;j++) {
				if(d[e[j].to] > d[e[j].fr] + e[j].t)
					d[e[j].to] = d[e[j].fr] + e[j].t;
			}
		}
		
		int j = 0;
		for(;j<m;j++) {
			if(d[e[j].to] > d[e[j].fr] + e[j].t)
				break;
		}
		if(j == m)
			printf("not possible\n");
		else
			printf("possible\n");
	}
}