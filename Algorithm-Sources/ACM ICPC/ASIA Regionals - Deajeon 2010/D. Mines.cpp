#include<stdio.h>
#include<vector>
using namespace std;

vector<int> e[2000];
vector<pair<int, pair<int, int> > > v;
vector<int> inEdge, visited;
int n, nVisited ;

void dfs(int now) {
	visited[now] = 1;
	nVisited++;

	for(int i = 0;i<e[now].size();i++) {
		if(!visited[e[now][i]]) {
			inEdge[e[now][i]]--;
			dfs(e[now][i]);
		}
	}
}

int main() {
	freopen("input.in", "r", stdin);

	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		inEdge.clear();
		inEdge.resize(n, 0);

		visited.clear();
		visited.resize(n, 0);

		for(int i = 0;i<n;i++) {
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			v.push_back(make_pair(d, make_pair(x, y)));
			e[i].clear();
		}
		
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++) {
				if(i == j)
					continue;
				int x2 = v[j].second.first, y2 = v[j].second.second;
				int x = v[i].second.first, y = v[i].second.second, d = v[i].first;

				if(x2 >= x-d/2 && x2 <= x+d/2 && y2 >= y-d/2 && y2 <= y+d/2) {
					e[i].push_back(j);
					inEdge[j]++;
				}
			}
		}

		nVisited = 0;

		int ans = 0;
		while(nVisited < n) {
			int i = 0;
			for(;i<n;i++) {
				if(!visited[i] && inEdge[i] == 0) {
					ans++;
					dfs(i);
					break;
				}
			}
			if(i == n) {
				for(;i<n;i++) {
					if(!visited[i] && inEdge[i] == 0) {
						ans++;
						dfs(i);
						break;
					}
				}	
			}
		}

		printf("%d\n", ans);
	}
}