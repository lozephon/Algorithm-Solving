#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<sstream>
using namespace std;

int map[100][100];
int c[100];
int n;

void floodfill(int x, int y, int gNum) {
    map[x][y] = -1;
    int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
    
    for(int i = 0;i<4;i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if(map[nx][ny] == gNum) 
            floodfill(nx, ny, gNum);
    }
}
int main() {
//    freopen("input.in", "r", stdin);
    
    while(scanf("%d", &n) == 1 && n != 0) {
        memset(map, 0, sizeof(map));
        memset(c, 0, sizeof(c));
        
        char buf[1000];
        gets(buf);

        bool isGood = true;
        
        int gNum = 1, nums[100] = {n*n, 0, };
        for(int i = 0;i<n-1;i++) {
            gets(buf);
            istringstream str(buf);
            
            int x, y;
            while(str >> x >> y) {
                if(x <= 0 || x > n || y <= 0 || y > n)
                    isGood = false;
                else {
                    nums[map[x-1][y-1]]--;
                    map[x-1][y-1] = gNum;
                    nums[map[x-1][y-1]]++;
                }
            }
            
            gNum++;
        }
        for(int i = 0;i<n;i++) {
            if(nums[i] != n)
                isGood = false;
        }
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(map[i][j] != -1) {
                    if(++c[map[i][j]] == 2) {
                        isGood = false;
                        break;
                    }
                    floodfill(i, j, map[i][j]);
                }
            }
            if(!isGood)
                break;
        }
        
        printf("%s\n", isGood ? "good" : "wrong");
    }
}