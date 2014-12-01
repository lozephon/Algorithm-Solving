// 알고리즘 1 - Part6 MST
// Dijkstra using Priority Queue
// Accepted(1)

#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int n;
    
    while(scanf("%d", &n) == 1) {
        static bool first = false;
        if(first)
            printf("\n");
        first = true;
        
        int idx = 0;
        map<string, int> ctoi;
        map<int, string> itoc;
        int e[1000][1000], st, ed;
        
        memset(e, 0x77, sizeof(e));
        for(int i = 0;i<=n;i++) {
            string fr, to;
            cin >> fr >> to;
            if(ctoi.find(fr) == ctoi.end()) {
                ctoi[fr] = idx;
                itoc[idx] = fr;
                e[idx][idx] = 0;
                idx++;
            }
            if(ctoi.find(to) == ctoi.end()) {
                ctoi[to] = idx;
                itoc[idx] = to;
                e[idx][idx] = 0;
                idx++;
            }
            if(i < n)
                e[ctoi[fr]][ctoi[to]] = e[ctoi[to]][ctoi[fr]] = 1;
            else {
                st = ctoi[fr];
                ed = ctoi[to];
            }
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        int d[1000], p[1000];
        
        memset(d, 0x77, sizeof(d));
        for(int i = 0;i<idx;i++) {
            d[i] = e[st][i];
            p[i] = st;
            q.push(make_pair(d[i], i));
        }
        
        while(!q.empty()) {
            int u = q.top().first, v = q.top().second; q.pop();
            
            if(v == ed)
                break;
            
            for(int i = 0;i<idx;i++) {
                if(e[v][i] != 0x77777777 && d[i] > u+e[v][i]) {
                    d[i] = u+e[v][i];
                    p[i] = v;
                    q.push(make_pair(d[i], i));
                }
            }
        }
        
        if(d[ed] == 0x77777777) {
            printf("No route\n");
            continue;
        }
        
        vector<int> path;
        while(ed != p[ed]) {
            path.push_back(ed);
            ed = p[ed];
        }
        path.push_back(ed);
        for(int i = (int)path.size()-1;i>0;i--)
            cout << itoc[path[i]] << " " << itoc[path[i-1]] << endl;
    }
}
