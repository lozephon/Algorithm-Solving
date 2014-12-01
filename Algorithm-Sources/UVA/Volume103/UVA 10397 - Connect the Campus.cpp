#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int g[750];

int gNum(int now) {
	vector<int> stk;
	while(g[g[now]] != g[now]) {
		stk.push_back(now);
		now = g[now];
	}
	
	for(int i = 0;i<stk.size();i++)
		g[stk[i]] = g[now];
	
	return g[now];
}

int main() {
	freopen("input.in", "r", stdin);
	
	int n;
	while(scanf("%d", &n) == 1) {
		int m;
		pair<int, int> v[750];

		vector<pair<double, pair<int, int> > > edges;
		
		for(int i = 0;i<n;i++) {
			g[i] = i;
			scanf("%d%d", &v[i].first, &v[i].second);
		}
		
		for(int i = 0;i<n;i++) {
			for(int j = i+1;j<n;j++) {
				double dist = sqrt((double)(v[i].first-v[j].first)*(v[i].first-v[j].first)+
								   (v[i].second-v[j].second)*(v[i].second-v[j].second));
				edges.push_back(make_pair(dist, make_pair(i, j)));
			}
		}
		
		sort(edges.begin(), edges.end());
		
		int nG = n;
		scanf("%d", &m);
		for(int i = 0;i<m;i++) {
			int fr, to;
			scanf("%d%d", &fr, &to);
			fr--; to--;
			if(gNum(fr) != gNum(to)) {
				if(g[fr] < g[to])
					g[g[to]] = g[fr];
				else
					g[g[fr]] = g[to];
				nG--;
			}
		}
		
		double ans = 0.0;
		int idx = 0;
		while(nG > 1) {
			double cost = edges[idx].first;
			int fr = edges[idx].second.first, to = edges[idx].second.second;
			
			if(gNum(fr) != gNum(to)) {
				if(g[fr] < g[to])
					g[g[to]] = g[fr];
				else
					g[g[fr]] = g[to];
				nG--;
				ans += cost;
			}
			idx++;
		}
		
		printf("%.2lf\n", ans);
	}
}