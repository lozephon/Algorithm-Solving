#include<stdio.h>
#include<memory.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int c, n, cost[50], d[1 << 15];
vector<int> ar;

void printState(int state) {
    for(int i = n-1;i>=0;i--) 
        printf("%d", state & (1 << i) ? 1 : 0);
    printf(" - %d", state);
}

int solve(int state) {
//    printState(state);
//    printf("\n");
    
    d[state] = 0;
//    int s = mask - 1;
    int s = (state - 1) & state;
    while(s > 0) {
        int stateA = 0, stateB = 0;
        stateA = s;
        stateB = (state-s);
//        for(int i = 0;i<ones.size();i++) 
//            if(s & (1 << i))
//                stateA |= (1 << ones[i]);
//        for(int i = 0;i<ones.size();i++) 
//            if((mask-s) & (1 << i))
//                stateB |= (1 << ones[i]);
//        printf("from "); printState(state);
//        printf(" { ");
//        printState(stateA);
//        printf(", ");
//        printState(stateB);
//        printf(" }\n");
        d[state] = max(d[state], (d[stateA] == -1 ? solve(stateA) : d[stateA]) + (d[stateB] == -1 ? solve(stateB) : d[stateB]));
//        s--;
        s = (s-1) & state;
    }
    
    int sum = 0, nBottle = 0;
    for(int i = 0;i<n;i++) {
        if(state & (1 << i)) {
            sum += ar[i];
            nBottle++;
        }
    }
    
    int nFull = sum / c, nResi = sum % c, nZero = nBottle - nFull - 1;
    d[state] = max(d[state], nFull*cost[c] + cost[nResi] + nZero*cost[0]);
    
//    printf("d["); printState(state);
//    printf("] = %d\n", d[state]);
    return d[state];
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d%d", &c, &n);

        ar.clear();
        for(int i = 0;i<n;i++) {
            int num;
            scanf("%d", &num);
            ar.push_back(num);
        }
        
        for(int i = 0;i<=c;i++)
            scanf("%d", &cost[i]);
        
        memset(d, -1, sizeof(d));
        
        printf("%d\n", solve((1 << n) - 1));
    }
}