#include<stdio.h>
#include<string.h>
#include<memory.h>

int w, h, map[51][51], dice[7];

#define NONE 0
#define DICE 1
#define DOT 2
#define END 3

void findDot(int x, int y) {
    int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
    
    map[x][y] = END;
    
    for(int i = 0;i<4;i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if(map[nx][ny] == DOT)
                findDot(nx, ny);
        }
    }
}

int floodfill(int x, int y) {
    int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
    
    map[x][y] = END;
    
    int rtn = 0;
    
    for(int i = 0;i<4;i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if(map[nx][ny] == DICE)
                rtn += floodfill(nx, ny);
            else if(map[nx][ny] == DOT) {
                findDot(nx, ny);
                rtn += floodfill(nx, ny);
                rtn++;
            }
        }
    }
    
    return rtn;
}
int main() {
//    freopen("input.in", "r", stdin);
    
    int caseNum = 1;
    while(scanf("%d%d", &w, &h) == 2 && (w != 0 || h != 0)) {
        char buf[100];
        gets(buf);
        
        memset(map, 0, sizeof(map));
        memset(dice, 0, sizeof(dice));
        
        for(int i = 0;i<h;i++) {
            gets(buf);
            for(int j = 0;j<w;j++)
                map[i][j] = buf[j] == '*' ? DICE : (buf[j] == 'X' ? DOT : NONE);
        }
        
        for(int i = 0;i<h;i++) {
            for(int j = 0;j<w;j++) {
                if(map[i][j] == DICE)
                    dice[floodfill(i, j)]++;
            }
        }
        
//        for(int i = 0;i<h;i++) {
//            for(int j = 0;j<w;j++) {
//                if(map[i][j] == DOT) {
//                    findDot(i, j);
//                    dice[1]++;
//                }
//            }
//        }
        
        printf("Throw %d\n", caseNum++);
        bool firstSp = false;
        for(int i = 1;i<7;) {
            if(dice[i]--) {
                if(firstSp)
                    printf(" ");
                firstSp = true;
                printf("%d", i);
            }
            else
                i++;
        }
        printf("\n\n");
    }
}