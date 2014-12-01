#include<stdio.h>
#include<queue>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int r, c;
    while(scanf("%d%d", &r, &c) == 2) {
        if(r == 0 && c == 0)
            break;
        
        int map[1000][1000] = {0, };
        
        int rows;
        scanf("%d", &rows);
        for(int i = 0;i<rows;i++) {
            int st, cols;
            scanf("%d%d", &st, &cols);
            for(int j = 0;j<cols;j++) {
                int ed;
                scanf("%d", &ed);
                map[st][ed] = 1;
            }
        }
        
        int stx, sty, edx, edy;
        scanf("%d%d%d%d", &stx, &sty, &edx, &edy);
        
        queue<pair<int, pair<int, int> > > q;
        q.push(make_pair(0, make_pair(stx, sty)));
        int visited[1000][1000] = {0, };
        visited[stx][sty] = 1;
        
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, ans = 0;
        while(!q.empty()) {
            int tt = q.front().first, nx = q.front().second.first, ny = q.front().second.second; q.pop();
            
            if(nx == edx && ny == edy) {
                ans = tt;
                break;
            }
            
            for(int i = 0;i<4;i++) {
                int nnx = nx+dx[i], nny = ny+dy[i];
                if(nnx < 0 || nnx >= r || nny < 0 || nny >= c)
                    continue;
                if(!visited[nnx][nny] && !map[nnx][nny]) {
                    visited[nnx][nny] = 1;
                    q.push(make_pair(tt+1, make_pair(nnx, nny)));
                }
            }
        }
        
        printf("%d\n", ans);
    }
}