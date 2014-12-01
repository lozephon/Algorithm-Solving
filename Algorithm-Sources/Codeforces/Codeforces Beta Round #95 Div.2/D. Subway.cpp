#include<stdio.h>

int isRing[3001];
int n;
int visited[3001];
int e[3001][3001], distance[3001];
int root;

int dfs(int now) {
	visited[now] = 1;

	for(int i = 0;i<n;i++) {
		if(e[now][i]) {
			if(visited[i]) {
				root = i;
				isRing[now] = 1;
				return 1;
			}
			else {
				e[now][i] = e[i][now] = 0;
				int rtn = dfs(i);
				e[now][i] = e[i][now] = 1;
				if(rtn == 1) {
					isRing[now] = 1;
					if(now == root)
						return 2;
					else 
						return 1;
				}
				else if(rtn == 2)
					return 2;
			}
		}
	}
	return 0;
}

void dfs2(int now, int dist) {
	distance[now] = dist;

	for(int i = 0;i<n;i++) {
		if(e[now][i] && !isRing[i]) {
			e[now][i] = e[i][now] = 0;
			dfs2(i, dist+1);
		}
	}
}

int main() {	
//	freopen("input.in", "r", stdin);

	scanf("%d", &n);

	for(int i = 0;i<n;i++) {
		int fr, to;
		scanf("%d%d", &fr, &to);

		e[fr-1][to-1] = 1;
		e[to-1][fr-1] = 1;
	}

	dfs(0);

	for(int i = 0;i<n;i++) {
		if(isRing[i])
			dfs2(i, 0);
	}

	printf("%d", distance[0]);
	for(int i = 1;i<n;i++)
		printf(" %d", distance[i]);
	printf("\n");
}