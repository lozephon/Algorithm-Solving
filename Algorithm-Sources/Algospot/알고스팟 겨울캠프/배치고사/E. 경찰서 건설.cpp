// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(4)
// Type - SCC(Kosaraju)
// Difficulty - 3
// Etc - 각 SCC의 노드들 중 최소값들의 합

#include<stdio.h>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> stck;
bool visited[50];
int n, e[50][50], cost[50];

void dfs(int now) {
    visited[now] = true;
    
    for(int i = 0;i<n;i++)
        if(e[now][i] && !visited[i]) 
            dfs(i);
    
    stck.push_back(now);
}

int scc(int now) {
    int minValue = cost[now];
    visited[now] = true;
    
    for(int i = 0;i<n;i++) 
        if(e[i][now] && !visited[i])
            minValue = min(scc(i), minValue);
    
    return minValue;
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d", &n);
        for(int i = 0;i<n;i++)
            scanf("%d", &cost[i]);
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                char ch;
                while(scanf("%c", &ch) == 1 && (ch != 'Y' && ch != 'N'));
                e[i][j] = ch == 'Y' ? 1 : 0;
            }
        }
        
        stck.clear();
        
        memset(visited, 0, sizeof(visited));
        for(int i = 0;i<n;i++) {
            if(!visited[i])
                dfs(i);
        }
        
        int ans = 0;
        memset(visited, 0, sizeof(visited));        
        for(int i = (int)stck.size()-1;i>=0;i--) {
            if(!visited[stck[i]]) 
                ans += scc(stck[i]);
        }
        
        printf("%d\n", ans);
    }
}
