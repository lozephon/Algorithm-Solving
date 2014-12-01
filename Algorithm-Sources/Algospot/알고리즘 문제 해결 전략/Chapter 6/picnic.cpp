#include<stdio.h>

int n, m;
int e[10][11] = {0, };

int search(int now, bool *used, int level) {
	int rtn = 0;
	
	used[now] = true;
	for(int j = 0;j<e[now][10];j++) {
		if(!used[e[now][j]]) {
			used[e[now][j]] = true;
			if(level == n/2-1) {
				rtn++;
//				printf("\n");
			}
//			printf("(%d, %d) ", now, e[now][j]);
			for(int k = now+1;k<n;k++)
				if(!used[k])
					rtn += search(k, used, level+1);
			used[e[now][j]] = false;
		}
	}
	used[now] = false;
	
	return rtn;
}

int main() {
	int c;
	
//	freopen("input.in", "r", stdin);
	
	scanf("%d", &c);
	
	while(c--) {
		for(int i = 0;i<10;i++)
			for(int j =0 ;j<11;j++)
				e[i][j] = 0;
		
		scanf("%d%d", &n, &m);
		
		for(int i = 0;i<m;i++) {
			int fr, to;
			scanf("%d%d", &fr, &to);
			if(fr > to) {
				int t = fr;
				fr = to;
				to = t;
			}
			e[fr][e[fr][10]++] = to;
//			e[to][e[to][10]++] = fr;
		}
		
		bool used[10] = {0, };
		printf("%d\n", search(0, used, 0));
	}
}