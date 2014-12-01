#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int n;
    while(scanf("%d", &n) == 1 && n != 0) {
        vector<pair<int, int> > e[10];
        int p[10], d[10];
        
        for(int i = 0;i<n;i++) {
            p[i] = i;
            d[i] = 1000000000;
            
            int nE;
            scanf("%d", &nE);
            for(int j = 0;j<nE;j++) {
                int ed, delay;
                scanf("%d%d", &ed, &delay);
                e[i].push_back(make_pair(ed-1, delay));
            }
        }
        int st, ed;
        scanf("%d%d", &st, &ed); st--; ed--;
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        q.push(make_pair(0, st));
        
        while(!q.empty()) {
            int u = q.top().first, v = q.top().second; q.pop();
            d[v] = u;
            
            if(v == ed)
                break;
            
            for(int i = 0;i<e[v].size();i++) {
                if(d[e[v][i].first] > d[v]+e[v][i].second) {
                    d[e[v][i].first] = d[v]+e[v][i].second;
                    p[e[v][i].first] = v;
                    q.push(make_pair(d[e[v][i].first], e[v][i].first));
                }
            }
        }
        
        int now = ed;
        vector<int> path;
        while(p[now] != now) {
            path.push_back(now);
            now = p[now];
        }
        
        static int caseNum = 1;
        printf("Case %d: Path = %d", caseNum++, st+1);
        for(int i = (int)path.size()-1; i>=0; i--) 
            printf(" %d", path[i]+1);
        printf("; %d second delay\n", d[ed]);
    }
}