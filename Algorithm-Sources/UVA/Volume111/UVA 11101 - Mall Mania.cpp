#include<stdio.h>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>
using namespace std;

char map[2001][2001];
int d[2001][2001];

int main() {
//    freopen("input.in", "r", stdin);
    
    int n, m, rMin, rMax, cMin, cMax;
    while(scanf("%d", &n) == 1 && n) {
        rMin = cMin = 0x7fffffff;
        rMax = cMax = 0;
        
        memset(map, 0, sizeof(map));
        memset(d, 0xff, sizeof(d));
        
        queue<pair<int, pair<int, int> > > q;
        
        for(int i = 0;i<n;i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            map[x][y] = 1;
            d[x][y] = 0;
            q.push(make_pair(0, make_pair(x, y)));
            rMin = min(rMin, x);
            rMax = max(rMax, x);
            cMin = min(cMin, y);
            cMax = max(cMax, y);
        }
        
        scanf("%d", &m);
        
        for(int i = 0;i<m;i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            map[x][y] = 2;
            rMin = min(rMin, x);
            rMax = max(rMax, x);
            cMin = min(cMin, y);
            cMax = max(cMax, y);            
        }
        
        rMax++; cMax++;
        rMin = cMin = 0;
        rMax = cMax = 2001;
        
        int ans = 0x7fffffff, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        while(!q.empty()) {
            int tt = q.front().first, nx = q.front().second.first, ny = q.front().second.second; q.pop();
            
            for(int i = 0;i<4;i++) {
                int nnx = nx+dx[i], nny = ny+dy[i];
                if(nnx < rMin || nnx >= rMax || nny < cMin || nny >= cMax) 
                    continue;

                if(map[nnx][nny] == 0 && (d[nnx][nny] == -1 || d[nnx][nny] > tt+1)) {
                    d[nnx][nny] = tt+1;
                    q.push(make_pair(tt+1, make_pair(nnx, nny)));
                }
                else if(map[nnx][nny] == 2)
                    ans = min(ans, tt+1);
            }
        }
        
        printf("%d\n", ans);
    }
}