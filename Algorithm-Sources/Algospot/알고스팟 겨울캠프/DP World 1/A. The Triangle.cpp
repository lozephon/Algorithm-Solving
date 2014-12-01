#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int n;
    scanf("%d", &n);
    
    int ar[100][100], d[100][100] = {0, };
    scanf("%d", &ar[0][0]);
    d[0][0] = ar[0][0];
    
    for(int i = 1;i<n;i++) {
        scanf("%d", &ar[i][0]);
        d[i][0] = d[i-1][0] + ar[i][0];
        
        for(int j = 1;j<i;j++) {
            scanf("%d", &ar[i][j]);            
            d[i][j] = max(d[i-1][j], d[i-1][j-1]) + ar[i][j];
        }
        
        scanf("%d", &ar[i][i]);
        d[i][i] = d[i-1][i-1] + ar[i][i];
    }
    
    int ans = d[n-1][0];
    for(int i = 1;i<n;i++)
        ans = max(ans, d[n-1][i]);
    
    printf("%d\n", ans);
}