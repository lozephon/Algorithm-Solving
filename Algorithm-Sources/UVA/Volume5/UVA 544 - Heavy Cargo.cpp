// 알고리즘 1 - Part7 Floyd
// Maximum Spanning Tree
// Accepted(2)

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    int caseNum = 1;
    int n, r;
    while(scanf("%d%d", &n, &r) == 2) {
        if(n == 0 && r == 0)
            break;
        
        map<string, int> street;
        int st, ed, cost, idx = 0;
        int e[200][200] = {0, };
        memset(e, 0xff, sizeof(e));
        string fr, to;
        for(int i = 0;i<=r;i++) {
            if(i < r)
                cin >> fr >> to >> cost;
            else
                cin >> fr >> to;
            
            if(street.find(fr) == street.end())
                street[fr] = idx++;
            if(street.find(to) == street.end())
                street[to] = idx++;
            if(i < r)
                e[street[fr]][street[to]] = e[street[to]][street[fr]] = cost;
            else {
                st = street[fr];
                ed = street[to];
            }
        }
        
        priority_queue<pair<int, int> > q;
        int d[200] = {0, };
        
        d[st] = 0x77777777;
        for(int i = 0;i<n;i++) {
            if(e[st][i] != -1) {
                q.push(make_pair(e[st][i], i));
                d[i] = e[st][i];
            }
        }

        while(!q.empty()) {
            int v = q.top().second; q.pop();
            
            if(v == ed)
                break;
            for(int i = 0;i<n;i++) {
                if(e[v][i] != -1 && min(d[v], e[v][i]) > d[i]) {
                    d[i] = min(d[v], e[v][i]);
                    q.push(make_pair(d[i], i));
                }
            }
        }
        printf("Scenario #%d\n", caseNum++);
        printf("%d tons\n\n", d[ed]);
    }
}