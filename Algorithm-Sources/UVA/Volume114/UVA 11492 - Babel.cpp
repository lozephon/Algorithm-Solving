#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<memory.h>
using namespace std;

map<string, int> stoi;
int n;

int mapNum(string &s) {
    if(stoi.find(s) == stoi.end())
        stoi[s] = n++;
    return stoi[s];
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int m;
    while(scanf("%d", &m) == 1 && m != 0) {
        stoi.clear();
        
        n = 0;
        char stbuf[100], edbuf[100], wordbuf[100];
        scanf("%s%s", stbuf, edbuf);
        string ststr = stbuf, edstr = edbuf;
        
        int st = mapNum(ststr), ed = mapNum(edstr);
        
        vector<pair<pair<int, int>, pair<int, int> > > edges;
        for(int i = 0;i<m;i++) {
            scanf("%s%s%s", stbuf, edbuf, wordbuf);
            string s;   
            edges.push_back(make_pair(make_pair(mapNum(s = string(stbuf)), mapNum(s = string(edbuf))),
                                      make_pair(wordbuf[0]-'a', strlen(wordbuf))));
        }
        
        vector<vector<pair<int, pair<int, int> > > > e;
        e.resize(n);
        
        for(int i = 0;i<m;i++) {
            int u = edges[i].first.first, v = edges[i].first.second, ic = edges[i].second.first, len = edges[i].second.second;
            
            e[u].push_back(make_pair(v, make_pair(ic, len)));
            e[v].push_back(make_pair(u, make_pair(ic, len)));
        }
        
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
        
        q.push(make_pair(0, make_pair(st, 26)));
        
        vector<vector<int> > d(n);
        for(int i = 0;i<n;i++) {
            d[i].resize(27);
            for(int j = 0;j<27;j++)
                d[i][j] = 99999;
        }
        d[st][26] = 0;
        
        while(!q.empty()) {
            int len = q.top().first, now = q.top().second.first, ic = q.top().second.second; q.pop();
            
            if(now == ed)
                break;
            
            for(int i = 0;i<e[now].size();i++) {
                if(e[now][i].second.first == ic)
                    continue;                
                
                int newD = len + e[now][i].second.second;
                if(d[e[now][i].first][e[now][i].second.first] > newD) {
                    d[e[now][i].first][e[now][i].second.first] = newD;
                    q.push(make_pair(newD, make_pair(e[now][i].first, e[now][i].second.first)));
                }
            }
        }
        
        int ans = 99999;
        for(int i = 0;i<27;i++)
            ans = min(ans, d[ed][i]);
        
        if(ans == 99999)
            printf("impossivel\n");
        else
            printf("%d\n", ans);
    }
}