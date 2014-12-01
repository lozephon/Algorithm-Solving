// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - DP(Coin Change)
// Difficulty - 2
// Etc - 동전 작은 순으로 0부터 m-C[i]까지 D[j]가 1 이상이면 D[j+C[i]] += D[j]

#include<stdio.h>

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n;
        int c[20], m;
        scanf("%d", &n);
        for(int i = 0;i<n;i++)
            scanf("%d", &c[i]);
        scanf("%d", &m);
        
        int d[10001] = {1, };
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<=m-c[i];j++) {
                if(d[j]) 
                    d[j+c[i]] += d[j];
            }
        }
        
        printf("%d\n", d[m]);
    }
}