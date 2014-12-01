#include<stdio.h>

int main() {
//	freopen("input.in", "r", stdin);
	
	int n, m;
	scanf("%d%d", &n, &m);
	
	int e[101][101] = {0, }, nE[101] = {0, };
	
	for(int i = 0; i<m;i++) {
		int fr, to;
		scanf("%d%d", &fr, &to);
		if(e[fr][to] == 0) {
			e[fr][to] = e[to][fr] = 1;
			nE[fr]++;
			nE[to]++;
		}
	}
	
	for(int i = 1;i<=n;i++) {
		if(nE[i] == 1) {
			int now = i;
			do {
				for(int j = 1;j<=n;j++) {
					if(e[now][j]) {
						e[now][j] = e[j][now] = 0;
						nE[now]--;
						nE[j]--;
						now = j;
						break;
					}
				}
			} while(nE[now] != 0);
		}
	}
	
	int nCycle = 0;
	for(int i = 1;i<=n;i++) {
		if(nE[i] == 2) {
			int st = i;
			int now = i;
			int size = 0;
			do {
				for(int j = 1;j<=n;j++) {
					if(e[now][j]) {
						e[now][j] = e[j][now] = 0;
						nE[now]--;
						nE[j]--;
						now = j;
						break;
					}
				}
				size++;
			} while(st != now);
			nCycle+=size%2;
		}
	}

	printf("%d\n", nCycle + (n - nCycle) % 2);
}