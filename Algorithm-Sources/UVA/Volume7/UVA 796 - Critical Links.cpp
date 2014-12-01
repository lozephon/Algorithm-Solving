#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, vtime;
vector<int> vt, low;
vector<pair<int, int> > edges;

vector<vector<int> > e;

int tarjan(int now) {
    vt[now] = low[now] = ++vtime;
    
    for(int i = 0;i<n;i++) {
        if(e[now][i]) {
            e[now][i] = e[i][now] = 0;
            
            if(vt[i])
                low[now] = min(low[now], vt[i]);
            else 
                low[now] = min(low[now], tarjan(i));
            
            if(vt[now] < low[i]) 
                edges.push_back(make_pair(min(now, i), max(now, i)));
        }
    }
                                
    return low[now];
}

int main() {
//    freopen("input.in", "r", stdin);
    
    while(scanf("%d", &n) == 1) {
        vt.clear();
        low.clear();
        edges.clear();
        for(int i = 0;i<e.size();i++)
            e[i].clear();
        e.clear();
        
        vtime = 0;
        vt.resize(n, 0);
        low.resize(n, 0);
        e.resize(n);
        for(int i = 0;i<e.size();i++) {
            e[i].clear();
            e[i].resize(n, 0);
        }
        
        for(int i = 0;i<n;i++) {
            int st, ed, nE;
            scanf("%d (%d)", &st, &nE);
            
            for(int j = 0;j<nE;j++) {
                scanf("%d", &ed);
                e[st][ed] = e[ed][st] = 1;
            }
        }
        
        for(int i = 0;i<n;i++) {
            if(vt[i] == 0)
                tarjan(i);
        }
        
        sort(edges.begin(), edges.end());
        
        printf("%d critical links\n", (int)edges.size());
        for(int i = 0;i<edges.size();i++)
            printf("%d - %d\n", edges[i].first, edges[i].second);
        printf("\n");
    }
}