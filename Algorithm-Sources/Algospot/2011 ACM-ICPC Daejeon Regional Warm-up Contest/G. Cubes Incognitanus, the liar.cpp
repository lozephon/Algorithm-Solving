#include<stdio.h>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;

vector<pair<int, int> > e[50000];
int inEdge[50000], d[50000], st[50000];
int g[50000], minG[50000];

int gNum(int now) {
	vector<int> stk;

	while(g[now] != g[g[now]]) {
		stk.push_back(now);
		now = g[now];
	}

	for(int i = 0;i<stk.size();i++)
		g[stk[i]] = g[now];

	return g[now];
}

bool dfs(int now, int root) {
	st[now] = root;

	for(int i = 0;i<e[now].size();i++) {
		int to = e[now][i].first, k = e[now][i].second;

		if(st[to] != 0 && st[to] < root)
			return true;

		if(d[to] > d[now] + k) {
			d[to] = d[now] + k;
			if(dfs(to, root+1))
				return true;
		}
	}

	return false;
}

int main() {
	freopen("input.in", "r", stdin);

	int t;
	scanf("%d", &t);

	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);

		memset(inEdge, 0, sizeof(inEdge));
		memset(d, 0xff, sizeof(d));
		memset(minG, 0, sizeof(minG));

		for(int i = 0;i<n;i++) {
			e[i].clear();
			g[i] = i;
		}

		for(int i = 0;i<m;i++) {
			int fr, to, k;
			scanf("%d%d%d", &fr, &to, &k);
			e[fr].push_back(make_pair(to, -k));
			inEdge[to]++;

			if(gNum(fr) != gNum(to)) {
				if(g[fr] < g[to]) 
					g[g[to]] = g[fr];
				else
					g[g[fr]] = g[to];
			}
		}

		bool isCycle = false;
		int nInEdge = 0;
		for(int i = 0;i<n;i++) {
			if(inEdge[i] == 0) {
				memset(st, 0, sizeof(int)*n);
				isCycle = dfs(i, 0);
				nInEdge++;
			}
		}

		if(isCycle || !nInEdge) {
			printf("-1\n");
			continue;
		}

		for(int i = 0;i<n;i++)
			minG[g[i]] = min(minG[g[i]], d[i]);

		for(int i = 0;i<n;i++)
			d[i] -= minG[g[i]];

		printf("%d", d[0]);
		for(int i = 1;i<n;i++)
			printf(" %d", d[i]);

		printf("\n");
	}
}