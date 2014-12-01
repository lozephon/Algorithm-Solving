// 알고리즘 1 - Part5 Hamilton Circuit
// Hamilton Circuit(DFS)
// Accepted(0)

#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int caseNum; scanf("%d", &caseNum);
    while(caseNum--) {
        int st, ed, n;
        int x[10], y[10], p[10];
        scanf("%d%d", &st, &ed);
        
        scanf("%d%d%d", &st, &ed, &n);
        for(int i = 0;i<n;i++) {
            p[i] = i;
            scanf("%d%d", &x[i], &y[i]);
        }
        
        int minValue = 9999999;
        do {
            int sum = abs(st-x[p[0]]) + abs(ed-y[p[0]]) + abs(st-x[p[n-1]]) + abs(ed-y[p[n-1]]);
            int i = 0;
            for(;i<n-1 && sum < minValue;i++)
                sum += abs(x[p[i]]-x[p[i+1]]) + abs(y[p[i]]-y[p[i+1]]);
            if(i == n-1 && sum < minValue)
                minValue = sum;
        } while(next_permutation(p, p+n));
        
        printf("The shortest path has length %d\n", minValue);
    }
}