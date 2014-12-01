// Date - 2011/10/11
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - DP
// Difficulty - 2
// Etc - D[i][j] = i번째에서 j로 끝날 때의 가짓수, j로 올 수 있는 수 k의 D[i-1][k]들의 합

#include<stdio.h>

int main() {
//    freopen("input.in", "r", stdin);
    
    long long d[101][10];
    for(int i = 0;i<10;i++)
        d[1][i] = 1;
    
    for(int i = 2;i<=100;i++) {
        for(int j = 0;j<10;j++) {
            switch (j) {
                case 0:
                    d[i][j] = d[i-1][8];
                    break;
                case 1:
                    d[i][j] = d[i-1][2] + d[i-1][4];
                    break;
                case 2:
                    d[i][j] = d[i-1][1] + d[i-1][3] + d[i-1][5];
                    break;
                case 3:
                    d[i][j] = d[i-1][2] + d[i-1][6];
                    break;
                case 4:
                    d[i][j] = d[i-1][1] + d[i-1][5] + d[i-1][7];
                    break;
                case 5:
                    d[i][j] = d[i-1][2] + d[i-1][4] + d[i-1][6] + d[i-1][8];
                    break;
                case 6:
                    d[i][j] = d[i-1][3] + d[i-1][5] + d[i-1][9];
                    break;
                case 7:
                    d[i][j] = d[i-1][4] + d[i-1][8];
                    break;
                case 8:
                    d[i][j] = d[i-1][0] + d[i-1][5] + d[i-1][7] + d[i-1][9];
                    break;
                case 9:
                    d[i][j] = d[i-1][6] + d[i-1][8];
                    break;
            }
            d[i][j] %= 1000000009;
        }
    }
    
    int n;
    while(scanf("%d", &n) == 1 && n != -1) {
        long long ans = 0;
        for(int i = 0;i<10;i++)
            ans = (ans + d[n][i]) % 1000000009;
        printf("%lld\n", ans);
    }
}
