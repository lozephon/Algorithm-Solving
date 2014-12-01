// 알고리즘 1 - Part3 BFS
// BFS
// Accepted(12) - 경계선은 벽이요.

#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

struct point {
    int x, y, d;
    
    point() {};
    point(int _x, int _y, int _d) {
        x = _x;
        y = _y;
        d = _d;
    }
};

int main() {
//    freopen("input.in", "r", stdin);
    
    int m, n;
    while(scanf("%d%d", &m, &n) == 2) {
        if(m == 0 && n == 0)
            break;
        
        int map[51][51] = {0, };
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                int ob; 
                scanf("%d", &ob);
                
                if(ob)
                    map[i][j] = map[i][j+1] = map[i+1][j] = map[i+1][j+1] = 1;
            }
        }
        
        int visit[51][51][4];
        memset(visit, 0x77, sizeof(visit));
        
        point st, ed;
        char str[10];
        scanf("%d%d%d%d %s", &st.x, &st.y, &ed.x, &ed.y, str);

        if(!strcmp(str, "west"))
            st.d = 0;
        else if(!strcmp(str, "north"))
            st.d = 1;
        else if(!strcmp(str, "east"))
            st.d = 2;
        else if(!strcmp(str, "south"))
            st.d = 3;
        
        queue<point> q;
        q.push(st);
        
        int ans = 0x77777777;
        visit[st.x][st.y][st.d] = 0;
        while(!q.empty()) {
            point p = q.front(); q.pop();
            int len = visit[p.x][p.y][p.d] + 1;
            
            if(p.x == ed.x && p.y == ed.y) {
                if(ans > len - 1)
                    ans = len - 1;
                continue;
            }
            
            if(visit[p.x][p.y][(p.d + 3) % 4] > len) {
                q.push(point(p.x, p.y, (p.d + 3) % 4));
                visit[p.x][p.y][(p.d + 3) % 4] = len;
            }
            if(visit[p.x][p.y][(p.d + 1) % 4] > len) {
                q.push(point(p.x, p.y, (p.d + 1) % 4));
                visit[p.x][p.y][(p.d + 1) % 4] = len;
            }
            
            int dy[4][3] = { {-1, -2, -3}, {0, 0, 0}, {1, 2, 3}, {0, 0, 0} };
            int dx[4][3] = { {0, 0, 0}, {-1, -2, -3}, {0, 0, 0}, {1, 2, 3} };
            
            for(int i = 0;i<3;i++) {
                int x = p.x + dx[p.d][i], y = p.y + dy[p.d][i];
                if(x > 0 && x < m && y > 0 && y < n && visit[x][y][p.d] > len) {
                    if(!map[x][y]) {
                        q.push(point(x, y, p.d));
                        visit[x][y][p.d] = len;
                    }
                    else break;
                }
            }
        }
        
        printf("%d\n", ans == 0x77777777 ? -1 : ans);
    }
}