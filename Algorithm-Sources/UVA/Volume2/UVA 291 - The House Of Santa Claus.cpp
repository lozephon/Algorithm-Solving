// 알고리즘 1 - Part4 Euler Path
// Euler Circuit
// Accepted(0)

#include<stdio.h>

int edge[5][5] = {
    {0, 1, 1, 0, 1},  
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 1, 1, 0}
};

int path[8];
void dfs(int now, int level) {
    path[level] = now;

    if(level == 8) {
        for(int i = 0;i<=8;i++)
            printf("%d", path[i]+1);
        printf("\n");
        return;
    }

    for(int i = 0;i<5;i++) {
        if(edge[now][i]) {
            edge[now][i] = edge[i][now] = 0;
            dfs(i, level+1);
            edge[now][i] = edge[i][now] = 1;            
        }
    }
}

int main() {
    dfs(0, 0);
}