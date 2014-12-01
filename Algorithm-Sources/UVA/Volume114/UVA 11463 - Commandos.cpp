#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;

int n, m, ans;
int d[100][100], p[100][100];

int path(int fr, int to) {
	int mid = p[fr][to];
//	p[fr][to] = -1;
//	
//	if(mid == -1)
//		return 0;
	
	if(fr == mid)
		return d[fr][to];
	
	return path(fr, mid) + path(mid, to);
}

int main() {
	freopen("input.in", "r", stdin);
	
	int t, caseNum = 1;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		
		memset(d, 0x33, sizeof(d));
		
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++)
				p[i][j] = i;
		}
		
		for(int i = 0;i<n;i++)
			d[i][i] = 0;
		
		for(int i = 0;i<m;i++) {
			int fr, to;
			scanf("%d%d", &fr, &to);
			d[fr][to] = d[to][fr] = 1;
		}
		
		for(int k = 0;k<n;k++) {
			for(int i = 0;i<n;i++) {
				for(int j = 0;j<n;j++) {
					if(d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
						p[i][j] = k;
					}
				}
			}
		}
		
		ans = 0;
		
		int st, ed;
		scanf("%d%d", &st, &ed);
		
		ans = path(st, 0) + path(0, ed);
		
		for(int i = 1;i<n;i++) {
		//	ans += path(st, i) + path(i, ed);
			ans = max(ans, path(st, i) + path(i, ed));
		}
		
		printf("Case %d: %d\n", caseNum++, ans);
	}
}
