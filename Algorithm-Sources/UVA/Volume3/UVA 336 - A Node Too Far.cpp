#include<stdio.h>
#include<queue>
#include<algorithm>
#include<memory.h>
#include<map>
using namespace std;

map<int, int> stoi;

int main() {
//    freopen("input.in", "r", stdin);
    
    int m, caseNum = 1, n;
    int e[100][100];
    
    while(scanf("%d", &m) == 1 && m != 0) {
        n = 0;
        memset(e, 0, sizeof(e));
        stoi.clear();
        
        for(int i = 0;i<m;i++) {
            int st, ed;
            scanf("%d%d", &st, &ed);
            
            if(stoi.find(st) == stoi.end())
                stoi[st] = n++;
            if(stoi.find(ed) == stoi.end())
                stoi[ed] = n++;
            e[stoi[st]][stoi[ed]] = e[stoi[ed]][stoi[st]] = 1;
        }
        
        int st, ttl;
        while(scanf("%d%d", &st, &ttl) == 2) {
            if(st == 0 && ttl == 0)
                break;
            
            queue<pair<int, int> > q;
            bool visited[100] = {0, };
            int canGo = 1;
            
            q.push(make_pair(stoi[st], 0));
            visited[stoi[st]] = 1;

            while(!q.empty()) {
                int u = q.front().first, v = q.front().second; q.pop();
                
                if(v == ttl)
                    continue;
                
                for(int i = 0;i<n;i++) {
                    if(!visited[i] && e[u][i]) {
                        visited[i] = 1;
                        canGo++;
                        q.push(make_pair(i, v+1));
                    }
                }
            }
            
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caseNum++, n-canGo, st, ttl);
        }
    }
}