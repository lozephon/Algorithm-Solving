#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;

int p, q;
int ps[102], d[102][102];

int solve(int fr, int to) {
	if(fr == to)
		return d[fr][to] = ps[to+1]-ps[fr-1] - 2;
	
	d[fr][to] = ps[to+1]-ps[fr-1] - 2 + min(d[fr+1][to] == -1 ? solve(fr+1, to) : d[fr+1][to], 
											d[fr][to-1] == -1 ? solve(fr, to-1) : d[fr][to-1]);
	
	for(int i = fr+1;i<=to-1;i++) {
		d[fr][to] = min(d[fr][to], ps[to+1]-ps[fr-1] - 2 + 
						(d[fr][i-1] == -1 ? solve(fr, i-1) : d[fr][i-1]) +
						(d[i+1][to] == -1 ? solve(i+1, to) : d[i+1][to]));
	}
	
	return d[fr][to];
}

int main() {
	freopen("input.in", "r", stdin);
	
	int n, caseNum = 1;
	scanf("%d", &n);
	
	while(n--) {
		scanf("%d%d", &p, &q);
		for(int i = 1;i<=q;i++)
			scanf("%d", ps+i);
		
		ps[0] = 0;
		ps[q+1] = p+1;
		
		memset(d, 0xff, sizeof(d));
		printf("Case #%d: %d\n", caseNum++, solve(1, q));
	}
}
