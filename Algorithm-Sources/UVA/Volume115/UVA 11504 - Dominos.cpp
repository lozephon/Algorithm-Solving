#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, ttime;
vector<int> vt, low;
vector<vector<int> > e;
vector<int> nodes, g, inS;
int nSCC;

vector<vector<int> > edge;
vector<bool> visited;
vector<int> inE;
int nVisited = 0, ans = 0;

int tarjan(int now) {
    vt[now] = low[now] = ++ttime;
    nodes.push_back(now);
    inS[now] = true;
    
    for(int i = 0;i<e[now].size();i++) {
        int v = e[now][i];
        if(!vt[v])
            low[now] = min(low[now], tarjan(v));
        else if(inS[v])
            low[now] = min(low[now], vt[v]);
    }
    
    if(vt[now] == low[now]) {
        for(int i = (int)nodes.size()-1;i>=0;i--) {
            g[nodes[i]] = nSCC;
            inS[nodes[i]] = false;
            
            if(nodes[i] == now)
                i = -1;
            nodes.pop_back();
        }
        nSCC++;
    }
    
    return low[now];
}

void dfs(int now) {
    visited[now] = true;
    nVisited++;
    
    for(int i = (int)edge[now].size()-1;i>=0;i--) {
        int v = edge[now][i];
        edge[now].pop_back();
        inE[v]--;
        if(!visited[v])
            dfs(v);
    }
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int caseNum;
    scanf("%d", &caseNum);
    
    while(caseNum--) {
        scanf("%d%d", &n, &m);
        
        vt.clear(); vt.resize(n, 0);
        low.clear(); low.resize(n, 0);
        ttime = 0;
        nSCC = 0;
        nodes.clear();
        g.clear(); g.resize(n, 0);
        inS.clear(); inS.resize(n, 0);
        
        for(int i = 0;i<e.size();i++)
            e[i].clear();
        e.clear(); e.resize(n);
        for(int i = 0;i<n;i++)
            e[i].clear();
        
        for(int i = 0;i<m;i++) {
            int st, ed;
            scanf("%d%d", &st, &ed);
            st--; ed--;
            e[st].push_back(ed);
        }
        
        for(int i = 0;i<n;i++) {
            if(vt[i] == 0)
                tarjan(i);
        }
        
        for(int i = 0;i<edge.size();i++)
            edge[i].clear();
        edge.clear(); edge.resize(nSCC);
        for(int i = 0;i<edge.size();i++)
            edge[i].clear();
        
        inE.clear(); inE.resize(nSCC, 0);
        visited.clear(); visited.resize(nSCC, 0);
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<e[i].size();j++) {
                if(g[i] != g[e[i][j]]) {
                    edge[g[i]].push_back(g[e[i][j]]);
                    inE[g[e[i][j]]]++;
                }
            }
        }
        
        nVisited = 0, ans = 0;
        while(nVisited < nSCC) {
            for(int i = 0;i<nSCC;i++) {
                if(!visited[i] && inE[i] == 0) {
                    dfs(i);
                    ans++;
                    nVisited++;
                }
            }
        }
        
        printf("%d\n", ans);
    }
}