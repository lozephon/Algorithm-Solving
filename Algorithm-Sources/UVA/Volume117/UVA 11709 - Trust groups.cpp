#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int p, t, n, nSCC, ttime;
map<string, int> stoi;
vector<vector<int> > e;
vector<int> vt, low, inS, nodes;

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
    
    if(low[now] == vt[now]) {
        for(int i = (int)nodes.size()-1;i>=0;i--) {
            inS[nodes[i]] = false;
            
            if(nodes[i] == now)
                i = -1;
            nodes.pop_back();
        }
        nSCC++;
    }

    return low[now];
}

int main() {
//    freopen("input.in", "r", stdin);
    
    while(scanf("%d%d", &p, &t) == 2) {
        if(p == 0 && t == 0)
            break;
        
        char line[3]; gets(line);
        
        stoi.clear();
        e.clear();
        e.resize(p);
        
        n = 0;
        for(int i = 0; i<p; i++) {
            string name;
            getline(cin, name);
            stoi[name] = n++;
        }
        
        for(int i = 0; i<t; i++) {
            string st, ed;
            getline(cin, st);
            getline(cin, ed);
            e[stoi[st]].push_back(stoi[ed]);
        }
        
        vt.clear(); vt.resize(n, 0);
        low.clear(); low.resize(n, 0);
        inS.clear(); inS.resize(n, 0);
        
        nodes.clear();
        ttime = 0;
        nSCC = 0;
        
        for(int i = 0;i<n;i++) {
            if(!vt[i])
                tarjan(i);
        }
        
        printf("%d\n", nSCC);
    }
}