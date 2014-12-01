// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - AE(Tarjan)
// Difficulty - 3
// Etc - low[i] > st[now] 가 절선, >=가 절점

#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

int nV, nE, e[100][100];
int visited[100], st[100], low[100], tt;
int nAE;

int tarjan(int now) {
    st[now] = ++tt;
    low[now] = st[now];
    visited[now] = true;
    
    for(int i = 0;i<nV;i++) {
        if(e[now][i]) {
            e[now][i] = e[i][now] = 0;
            if(visited[i]) {
                low[now] = min(st[i], low[now]);
            }
            else {
                low[now] = min(low[now], tarjan(i));
            }
            
            if(low[i] > st[now]) {
                nAE++;
            }
        }
    }
    
    return low[now];
}

int main() {
//    freopen("input.in", "r", stdin);
    int t;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d%d", &nV, &nE);
        
        memset(e, 0, sizeof(e));
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0;i<nE;i++) {
            int fr, to;
            scanf("%d%d", &fr, &to);
            e[fr][to] = e[to][fr] = 1;
        }
        
        tt = 0;
        nAE = 0;
        
        for(int i = 0;i<nV;i++) {
            if(!visited[i])
                tarjan(i);
        }
        
        printf("%d\n", nAE);
    }
}