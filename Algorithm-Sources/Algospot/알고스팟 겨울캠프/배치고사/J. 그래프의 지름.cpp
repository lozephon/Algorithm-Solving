// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(3)
// Type - Floyd
// Difficulty - 3
// Etc - 간선 값이 10^9 이하이기 때문에 최단 거리가 int의 범위를 벗어날 수 있다.

#include<stdio.h>
#include<algorithm>
using namespace std;

#define LLMAX 0x7fffffffffffffffLL

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n;
        scanf("%d", &n);
        
        long long e[100][100];
        long long d[100][100];
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                scanf("%lld", &e[i][j]);
                d[i][j] = e[i][j] == -1 ? LLMAX : e[i][j];
            }
            d[i][i] = 0;
        }
        
        for(int k = 0;k<n;k++) {
            for(int i = 0;i<n;i++) {
                for(int j = 0;j<n;j++) {
                    if(d[i][k] != LLMAX && d[k][j] != LLMAX) {
                        if(d[i][j] > d[i][k] + d[k][j])
                            d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
        
        long long maxV = 0;
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                if(d[i][j] != LLMAX) {
                    if(maxV < d[i][j])
                        maxV = d[i][j];
                }
            }
        }
        
        printf("%lld\n", maxV);
    }
}