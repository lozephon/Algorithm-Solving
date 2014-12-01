#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<pair<int, int> > > e;
int main() {
	freopen("input.in", "r", stdin);
	
	int n, m;
	while(scanf("%d%d", &n, &m) == 2) {
		if(n == 0 && m == 0)
			break;
		
		e.clear(); e.resize(n);
		int allCost = 0;
		for(int i = 0;i<m;i++) {
			int fr, to, cost;
			scanf("%d%d%d", &fr, &to, &cost);
			allCost += cost;
			e[fr].push_back(make_pair(to, cost));
			e[to].push_back(make_pair(fr, cost));			
		}
		
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
		q.push(make_pair(0, 0));
		vector<int> visited(n, 0);
		int nVisited = 0, ans = 0;
		
		while(!q.empty() && nVisited < n) {
			int cost = q.top().first, now = q.top().second; q.pop();
			if(visited[now])
				continue;
			
			visited[now] = 1;
			nVisited++;
			ans += cost;
			
			for(int i = 0;i<e[now].size();i++) {
				int u = e[now][i].first, v = e[now][i].second;
				if(!visited[u]) 
					q.push(make_pair(v, u));
			}
		}
		
		printf("%d\n", allCost-ans);
	}
}