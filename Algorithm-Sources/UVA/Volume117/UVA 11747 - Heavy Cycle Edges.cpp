#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

vector<vector<pair<int,int> > > e;
vector<int> edges;

int main() {
//	freopen("input.in", "r", stdin);
	
	int n, m;
	while(scanf("%d%d", &n, &m) == 2) {
		if(n == 0 && m == 0)
			break;
		
		edges.clear();
		e.clear(); e.resize(n);
		for(int i = 0;i<m;i++) {
			int fr, to, cost;
			scanf("%d%d%d", &fr, &to, &cost);
			
			e[fr].push_back(make_pair(to, cost));
			e[to].push_back(make_pair(fr, cost));
		}
		
		vector<int> visited(n, 0);
		
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
		
		for(int i = 0;i<n;i++) {
			if(!visited[i]) {
				q.push(make_pair(0, i));
				
				while(!q.empty()) {
					int cost = q.top().first, now = q.top().second; q.pop();
					
					if(visited[now]) {
						edges.push_back(cost);
						continue;
					}
					visited[now] = 1;
					
					for(int j = 0;j<e[now].size();j++) {
						int u = e[now][j].first, v = e[now][j].second;
						
						if(!visited[u])
							q.push(make_pair(v, u));
					}
				}
			}
		}
		
		sort(edges.begin(), edges.end());
		if(edges.size() == 0)
			printf("forest\n");
		else {
			printf("%d", edges[0]);
			for(int i = 1;i<edges.size();i++)
				printf(" %d", edges[i]);
			printf("\n");
		}
	}
}