#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
#include<sstream>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int n, k;
    while(scanf("%d%d", &n, &k) == 2) {
        int t[5];
        for(int i = 0;i<n;i++)
            scanf("%d", t+i);
        
        char line[3]; gets(line);
        
        vector<int> e[5];
        int elv[100][5] = {0, };
        for(int i = 0;i<n;i++) {
            char str[1000];
            gets(str);
            istringstream sin(str);
            
            int to;
            while(sin >> to) {
                e[i].push_back(to);
                elv[to][i] = 1;
            }
        }
        
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
        
        for(int i = 0;i<n;i++) {
            if(elv[0][i])
                q.push(make_pair(0, make_pair(0, i)));
        }
        
        int d[100];
        for(int i = 0;i<100;i++)
            d[i] = 99999;
        d[0] = 0;
        
        while(!q.empty()) {
            int u = q.top().first, v = q.top().second.first, r = q.top().second.second; q.pop();
            
            if(v == k)
                break;
            
            for(int i = 0;i<n;i++) {
                if(elv[v][i]) {
                    int add = i == r ? 0 : 60;
                    for(int j = 0; j<e[i].size();j++) {
                        int newD = u+abs(v-e[i][j])*t[i]+add;
                        if(d[e[i][j]] > newD) {
                            d[e[i][j]] = newD;
                            q.push(make_pair(newD, make_pair(e[i][j], i)));
                        }
                    }
                }
            }
        }
        
        if(d[k] == 99999)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", d[k]);
    }
}