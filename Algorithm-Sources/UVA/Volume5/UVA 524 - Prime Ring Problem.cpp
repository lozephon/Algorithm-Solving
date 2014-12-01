// 알고리즘 1 - Part2 DFS
// DFS
// Accepted(8)

#include<stdio.h>

bool isPrime[52] = {0, 
    1, 1, 1, 0, 1, 
    0, 1, 0, 0, 0, 
    1, 0, 1, 0, 0, 
    0, 1, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 1, 0,
    1, 0, 0, 0, 0,
    0, 1, 0, 0, 0,
    1, 0, 1, 0, 0,
    0, 1, 0, 0, 0
};

int n;
int ar[16] = {1, };
bool used[17] = {1, 1, }; 

void dfs(int now) {
    if(now == n) { 
        if(isPrime[ar[0] + ar[n-1]]) {
            printf("1");
            for(int i = 1;i<n;i++)
                printf(" %d", ar[i]);
            printf("\n");
        }
        return;
    }
    
    for(int i = 2;i<=n;i++) {
        if(!used[i] && isPrime[ar[now-1]+i]) {
            used[i] = true;
            ar[now] = i;
            
            dfs(now+1);
            used[i] = false;
        }
    }
}

int main() {
//    freopen("input.in", "r", stdin);
        
    int caseNum = 1;
    while(scanf("%d", &n) == 1) {
        if(caseNum != 1)
            printf("\n");

        printf("Case %d:\n", caseNum++);
        dfs(1);
    }
}