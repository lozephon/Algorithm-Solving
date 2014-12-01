// Date - 2011/10/10
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - DP
// Difficulty - 2
// Etc - 증감, 감증 수열을 따로 처리

#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n;
        int ar[1005];
        scanf("%d", &n);
        
        for(int i = 0;i<n;i++)
            scanf("%d", &ar[i]);
        
        int d[1005][2], ans = 1;
        d[0][0] = d[0][1] = 1;
        for(int i = 0;i<n;i++) {
            d[i][0] = d[i][1] = 1;
            for(int j = 0;j<i;j++) {
                if(d[j][0] % 2 == 1 && ar[j] < ar[i] && d[j][0] + 1 > d[i][0])
                    d[i][0] = d[j][0] + 1;
                if(d[j][0] % 2 == 0 && ar[j] > ar[i] && d[j][0] + 1 > d[i][0])
                    d[i][0] = d[j][0] + 1;
                
                if(d[j][1] % 2 == 1 && ar[j] > ar[i] && d[j][1] + 1 > d[i][1])
                    d[i][1] = d[j][1] + 1;
                if(d[j][1] % 2 == 0 && ar[j] < ar[i] && d[j][1] + 1 > d[i][1])
                    d[i][1] = d[j][1] + 1;                
            }
            ans = max(ans, max(d[i][0], d[i][1]));
        }
        
        printf("%d\n", ans);
    }
}