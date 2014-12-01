#include<stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		
		int inout[101] = {0, }, nOdds = 0;
		for(int i = 0;i<m;i++) {
			int fr, to;
			scanf("%d%d", &fr, &to);
			inout[fr]++;
			inout[to]++;
		}
		for(int i = 1;i<=n;i++)
			nOdds += inout[i] % 2;
		
		printf("%d\n", nOdds/2);
	}
}