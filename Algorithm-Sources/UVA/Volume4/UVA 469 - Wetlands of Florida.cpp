#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int n, m, map[100][100], gNum;
vector<int> areas;

#define WATER -1
#define LAND -2

int floodfill(int x, int y) {
    int rtn = 1;
    int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    
    map[x][y] = gNum;
    for(int i = 0;i<9;i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == WATER)
            rtn += floodfill(nx, ny);
    }
    
    return rtn;
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    char line[5];
    gets(line);
    gets(line);

    bool firstline = false;    
    while(t--) {
        if(firstline)
            printf("\n");
        firstline = true;
        
        char buf[105];
        gets(buf);
        m = (int)strlen(buf);
        n = 0;
        
        for(int i = 0;i<m;i++)
            map[n][i] = buf[i] == 'L' ? LAND : WATER;
        n++;
        
        while(gets(buf) && (buf[0] == 'L' || buf[0] == 'W')) {
            for(int i = 0;i<m;i++)
                map[n][i] = buf[i] == 'L' ? LAND : WATER;
            n++;
        }
        
        gNum = 0;
        areas.clear();
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(map[i][j] == WATER) {
                    areas.push_back(floodfill(i, j));
                    gNum++;
                }
            }
        }
        
        while(!feof(stdin) && strcmp(buf, "")) {
            int a, b;
            sscanf(buf, "%d%d", &a, &b);
            
            printf("%d\n", map[a-1][b-1] >= 0 ? areas[map[a-1][b-1]] : 0);
            gets(buf);
        }
    }
}