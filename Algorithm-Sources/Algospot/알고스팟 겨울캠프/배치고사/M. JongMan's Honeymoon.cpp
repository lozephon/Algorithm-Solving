// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - Dijkstra
// Difficulty - 3
// Etc - 앞뒤로 프라하를 경유하는 다익스트라를 두번 돌리면 됨

#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int e[100][100], n, m;
bool visited[100];

int dijkstra(int fr, int to) {
    int rtn = 0x33333333;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    
    q.push(make_pair(0, fr));
 
    int d[100], p[100];
    for(int i = 0;i<n;i++) {
        d[i] = -1;
        p[i] = fr;
    }

    while(!q.empty()) {
        int u = q.top().first, v = q.top().second; q.pop();

        d[v] = u;
        
        if(v == to)
            break;
        
        for(int i = 0;i<n;i++) {
            if(!visited[i] && e[v][i] != -1 && (d[i] == -1 || d[i] > d[v] + e[v][i])) {
                d[i] = d[v] + e[v][i];
                p[i] = v;
                q.push(make_pair(d[i], i));
            }
        }
    }
    
    if(d[to] != -1) {
        rtn = d[to];
        int now = to;
        while(now != p[now]) {
            visited[now] = true;
            now = p[now];
        };
        visited[now] = true;
    }
    
    return rtn;
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d%d", &n, &m);
        memset(e, 0xff, sizeof(e));
        
        for(int i = 0;i<m;i++) {
            int fr, to, cost;
            scanf("%d%d%d", &fr, &to, &cost);
            
            e[fr][to] = e[to][fr] = cost;
        }
        
        memset(visited, 0, sizeof(visited));
        int ans = dijkstra(0, 2) + dijkstra(2, 1);
        
        memset(visited, 0, sizeof(visited));
        ans = min(ans, dijkstra(1, 2) + dijkstra(2, 0));

        printf("%d\n", ans);
    }
}