#include<stdio.h>
#include<queue>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int n, m;
    while(scanf("%d", &n) == 1 && n != 0) {
        scanf("%d", &m);
        int e[200][200] = {0, };
        
        for(int i = 0;i<m;i++) {
            int fr, to;
            scanf("%d%d", &fr, &to);
            e[fr][to] = e[to][fr] = 1;
        }
        
        queue<pair<int, int> > q;
        q.push(make_pair(1, 0));
        
        int visited[200] = {1, 0, };
        bool isBicolorable = true;
        
        while(!q.empty()) {
            int tt = q.front().first, now = q.front().second; q.pop();
            
            for(int i = 0;i<n;i++) {
                if(e[now][i]) {
                    if(!visited[i]) {
                        visited[i] = tt+1;
                        q.push(make_pair(tt+1, i));
                    }
                    else if(visited[i] && (visited[i] % 2 != (tt + 1) % 2))
                        isBicolorable = false;
                }
            }
        }
                        
        printf("%s\n", isBicolorable ? "BICOLORABLE." : "NOT BICOLORABLE.");
    }
}