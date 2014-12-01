// Date - 2011/10/6
// Source - 알고스팟 겨울캠프 배치고사
// Result - Accepted(0)
// Type - Simple Graph Theory
// Difficulty - 1
// Etc - 오일러 회로, 경로(한붓그리기)는 홀수점이 두 개 이하여야한다. (홀수점 개수는 항상 짝수)

#include<stdio.h>

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int v, e;
        scanf("%d%d", &v, &e);
        
        int nV[100] = {0, };
        for(int i = 0;i<e;i++) {
            int st, ed;
            scanf("%d%d", &st, &ed);
            nV[st]++;
            nV[ed]++;
        }
        int nOdd = 0;
        for(int i = 0;i<v;i++)
            nOdd += nV[i] % 2;
        
        if(nOdd == 0)
            printf("0\n");
        else
            printf("%d\n", (nOdd-2)/2);
    }
}