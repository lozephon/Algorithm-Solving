// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted()
// Type - DP
// Difficulty - 2
// Etc - 차례대로 돌면서 경우의 수 더해감. CC류?

#include<stdio.h>

int main() {
//    freopen("input.in", "r", stdin);
    
    int n;
    while(scanf("%d", &n) == 1 && n != -1) {
        long long d[50][50] = {0, };
        int ar[50][50];
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                char ch;
                while(scanf("%c", &ch) == 1 && (ch < '0' || ch > '9'));
                ar[i][j] = ch-'0';
            }
        }
        
        d[0][0] = 1;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(i == n-1 && j == n-1)
                    continue;
                
                if(d[i][j]) {
                    if(i+ar[i][j] < n)
                        d[i+ar[i][j]][j] += d[i][j];
                    if(j+ar[i][j] < n)
                        d[i][j+ar[i][j]] += d[i][j];
                }
            }
        }
        
        printf("%lld\n", d[n-1][n-1]);
    }
}