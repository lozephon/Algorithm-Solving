#include<stdio.h>
#include<queue>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int l, r, c;
    
    while(scanf("%d%d%d", &l, &r, &c) == 3) {
        if(l == 0 && r == 0 && c == 0)
            break;
        char line[50];
        gets(line);
        
        int map[30][30][30] = {0, }, stx, sty, stl, edx, edy, edl;
        for(int i = 0;i<l;i++) {
            for(int j = 0;j<r;j++) {
                gets(line);
                for(int k = 0;k<c;k++) {
                    if(line[k] == 'S') {
                        stx = j;
                        sty = k;
                        stl = i;
                    }
                    else if(line[k] == '.')
                        map[i][j][k] = 1;
                    else if(line[k] == 'E') {
                        edl = i;
                        edx = j;
                        edy = k;
                        map[i][j][k] = 1;
                    }
                }
            }
            gets(line);
        }
        
        queue<pair<pair<int, int>, pair<int, int> > > q;
        q.push(make_pair(make_pair(0, stl), make_pair(stx, sty)));
        
        int visited[30][30][30] = {0, };
        visited[stl][stx][sty] = 1;
        
        int dl[6] = {0, 0, 0, 0, -1, 1}, dx[] = {-1, 1, 0, 0, 0, 0}, dy[] = {0, 0, -1, 1, 0, 0}, ans = -1;
        while(!q.empty()) {
            int tt = q.front().first.first, nl = q.front().first.second, nx = q.front().second.first, ny = q.front().second.second; q.pop();
            
            if(nl == edl && nx == edx && ny == edy) {
                ans = tt;
                break;
            }
            
            for(int i = 0;i<6;i++) {
                int nnl = nl+dl[i], nnx = nx+dx[i], nny = ny+dy[i];
                if(nnl < 0 || nnl >= l || nnx < 0 || nnx >= r || nny < 0 || nny >= c)
                    continue;
                if(!visited[nnl][nnx][nny] && map[nnl][nnx][nny]) {
                    visited[nnl][nnx][nny] = 1;
                    q.push(make_pair(make_pair(tt+1, nnl), make_pair(nnx, nny)));
                }
            }
        }
        
        if(visited[edl][edx][edy])
            printf("Escaped in %d minute(s).\n", ans);
        else
            printf("Trapped!\n");
    }
}