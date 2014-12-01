#include<stdio.h>
#include<algorithm>
#include<memory.h>
#include<stdlib.h>
using namespace std;

int n, m;
long long a[105], b[105];
int d[200][200];

int solve(long long now, int pa, int pb) {
	if(d[pa][pb] != -1)
		return d[pa][pb];
	
	int &rtn = d[pa][pb];
	for(int i = pa;a[i] != -1;i++)
		if(a[i] > now)
			rtn = max(rtn, 1+solve(a[i], i+1, pb));
	for(int i = pb;b[i] != -1;i++)
		if(b[i] > now)
			rtn = max(rtn, 1+solve(b[i], pa, i+1));
	
	return rtn = max(rtn, 0);
}

int main() {
//	freopen("input.in", "r", stdin);
	int c;
	scanf("%d", &c);
	
//	const long long NEGINF = numeric_limits<long long>::min();
	while(c--) {
		scanf("%d%d", &n, &m);
		for(int i = 0;i<n;i++)
			scanf("%lld", a+i);
		a[n] = -1;
		for(int i = 0;i<m;i++)
			scanf("%lld", b+i);
		b[m] = -1;
		memset(d, -1, sizeof(d));
		
		printf("%d\n", solve(numeric_limits<long long>::min(), 0, 0));
	}
}