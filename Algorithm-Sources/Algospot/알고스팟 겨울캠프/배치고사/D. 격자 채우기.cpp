// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - Simple DP
// Difficulty - 1
// Etc - D[i] = D[i-1] + 2*D[i-2]

#include<stdio.h>

int main() {
    long long ar[101] = {0, 1, 3, };
    for(int i = 3;i<101;i++)
        ar[i] = (ar[i-1] + 2*ar[i-2]) % 1000000009;
        
    int d;
    while(scanf("%d", &d) == 1 && d != -1) {
        printf("%lld\n", ar[d]);
    }
}