#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<pair<int, int> > > e;

int main() {
//    freopen("input.in", "r", stdin);
    
    int n, m, k;
    while(scanf("%d", &n) == 1) {
        int oricost = 0;
        for(int i = 0;i<n-1;i++) {
            int fr, to, cost;
            scanf("%d%d%d", &fr, &to, &cost);
            oricost += cost;
        }
        
        e.clear(); e.resize(n);
        
        scanf("%d", &k);
        for(int i = 0;i<k;i++) {
            int fr, to, cost;
            scanf("%d%d%d", &fr, &to, &cost);
            fr--; to--;
            e[fr].push_back(make_pair(to, cost));
            e[to].push_back(make_pair(fr, cost));
        }
        
        scanf("%d", &m);
        for(int i = 0;i<m;i++) {
            int fr, to, cost;
            scanf("%d%d%d", &fr, &to, &cost);
            fr--; to--;
            e[fr].push_back(make_pair(to, cost));
            e[to].push_back(make_pair(fr, cost));
        }
        
        vector<int> visited(n, 0);
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        q.push(make_pair(0, 0));

        int nVisited = 0, newCost = 0;
        while(!q.empty() && nVisited < n) {
            int cost = q.top().first, now = q.top().second; q.pop();
            if(visited[now])
                continue;
            
            newCost += cost;
            visited[now] = 1;
            nVisited++;
            
            for(int i = 0;i<e[now].size();i++) {
                int u = e[now][i].first, v = e[now][i].second;
                if(!visited[u])
                    q.push(make_pair(v, u));
            }
        }
        
        static bool firstline = false;
        if(firstline)
            printf("\n");
        firstline = true;
        
        printf("%d\n%d\n", oricost, newCost);
    }
}