// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(4)
// Type - BFS
// Difficulty - 2
// Etc - 목표 지점에 도달한 순간 부터 같은 거리이며 목표지점에 도달하는 점들의 개수를 세면 됨

#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

vector<int> e[10000];
bool visited[10000];

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n, m, st, ed;
        scanf("%d%d%d%d", &n, &m, &st, &ed);
        
        for(int i = 0;i<n;i++) {
            e[i].clear();
            visited[i] = false;
        }
        
        for(int i = 0;i<m;i++) {
            int fr, to;
            scanf("%d%d", &fr, &to);
            e[fr].push_back(to);
            e[to].push_back(fr);
        }
        
        bool find = false;
        int minDist;
        long long ansNum = 0;
        
        queue<pair<int, int> > q;
        q.push(make_pair(st, 0));
        
        visited[st] = true;
        while(!q.empty()) {
            int u = q.front().first, v = q.front().second; q.pop();
            visited[u] = true;
            
            if(!find && u == ed) {
                find = true;
                minDist = v;
                ansNum = 1;
                continue;
            }
            if(find) {
                if(u == ed && v == minDist)
                    ansNum = (ansNum + 1) % 1000000003LL;
                else
                    break;
            }
            else {
                for(int i = 0;i<e[u].size();i++) {
                    if(!visited[e[u][i]])
                        q.push(make_pair(e[u][i], v+1));
                }
            }
        }
        
        printf("%lld\n", ansNum);
    }
}