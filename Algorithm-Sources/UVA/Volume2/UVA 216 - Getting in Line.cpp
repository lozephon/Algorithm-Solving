// 알고리즘 1 - Part5 Hamilton Circuit
// Hamilton Circuit(DFS)
// Accepted(0)

#include<stdio.h>
#include<math.h>

int n;
double len[10][10];
int x[10], y[10];
double minLen, nowLen;
int visit[10], path[10], minPath[10];

void dfs(int now, int level) {
    path[level] = now;
    
    if(level == n-1) {
        minLen = nowLen;
        for(int i = 0;i<n;i++)
            minPath[i] = path[i];
        return;
    }
    
    for(int i = 0;i<n;i++) {
        if(!visit[i]) {
            if(nowLen + len[now][i] < minLen) {
                visit[i] = 1;
                nowLen += len[now][i];
                dfs(i, level+1);
                visit[i] = 0;
                nowLen -= len[now][i];                
            }
        }
    }
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int caseNum = 1;
    
    while(scanf("%d", &n) == 1 && n != 0) {
        for(int i = 0;i<n;i++) {
            scanf("%d%d", &x[i], &y[i]);
            visit[i] = 0;
        }
        
        for(int i = 0;i<n;i++)
            for(int j = i+1;j<n;j++)
                len[i][j] = len[j][i] = sqrt((double)((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])));
        
        minLen = 99999999.0;
        nowLen = 0;
        
        for(int i = 0;i<n;i++) {
            visit[i] = 1;
            dfs(i, 0);
            visit[i] = 0;
        }
        
        double sum = 0.0;
        
        printf("**********************************************************\n");
        printf("Network #%d\n", caseNum++);
        for(int i = 0;i<n-1;i++) {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x[minPath[i]], y[minPath[i]], x[minPath[i+1]], y[minPath[i+1]], len[minPath[i]][minPath[i+1]]+16.0);
            sum += len[minPath[i]][minPath[i+1]] + 16.0;
        }
        printf("Number of feet of cable required is %.2lf.\n", sum);
    }
}