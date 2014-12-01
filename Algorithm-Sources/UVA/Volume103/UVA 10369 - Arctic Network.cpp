#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<pair<int, int> > v;
vector<pair<double, pair<int, int> > > edges;
vector<int> g;

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
	
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int s, p;
		scanf("%d%d", &s, &p);
		
		g.clear(); g.resize(p);
		v.clear(); v.resize(p);
		
		for(int i = 0;i<p;i++) {
			scanf("%d%d", &v[i].first, &v[i].second);
			g[i] = i;
		}
		
		edges.clear();
		for(int i = 0;i<p;i++) {
			for(int j = i+1;j<p;j++) {
				double dist = sqrt((double)(v[i].first-v[j].first)*(v[i].first-v[j].first)+
								   (v[i].second-v[j].second)*(v[i].second-v[j].second));
				edges.push_back(make_pair(dist, make_pair(i, j)));
			}
		}
		
		sort(edges.begin(), edges.end());
		
		if(s == 0)
			s = 1;
		
		int nG = p, idx = 0;
		while(nG > s) {
			int fr = edges[idx].second.first, to = edges[idx].second.second;
			
			if(gNum(fr) != gNum(to)) {
				if(g[fr] < g[to])
					g[g[to]] = g[fr];
				else
					g[g[fr]] = g[to];
				nG--;
			}
			idx++;
		}
		
		printf("%.2lf\n", edges[idx-1].first);
	}
}