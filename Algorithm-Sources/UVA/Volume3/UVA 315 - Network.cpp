#include<stdio.h>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int n, e[100][100], st[100], low[100], t;
bool isAP[100];

int tarjan(int now, bool isRoot) {
    low[now] = st[now] = ++t;
    
    int nRoute = 0;
    for(int i = 0;i<n;i++) {
        if(e[now][i]) {
            e[now][i] = e[i][now] = 0;
            
            if(st[i])
                low[now] = min(low[now], st[i]);
            else {
                low[now] = min(low[now], tarjan(i, false));
                nRoute++;
            }
            
            if(st[now] <= low[i])
                isAP[now] = true;
        }
    }
    
    if(isRoot) {
        if(nRoute > 1)
            isAP[now] = true;
        else
            isAP[now] = false;
    }
    
    return low[now];
}

int main() {
//    freopen("input.in", "r", stdin);
    
    while(scanf("%d", &n) == 1 && n != 0) {
        memset(e, 0, sizeof(e));
        memset(st, 0, sizeof(st));
        memset(low, 0, sizeof(low));
        memset(isAP, 0, sizeof(isAP));
        t = 0;
        
        char buf[1000];
        gets(buf);
        int fr, to;
        while(gets(buf) && buf[0] != '0') {
            istringstream str(buf);
            str >> fr;
            while(str >> to) 
                e[fr-1][to-1] = e[to-1][fr-1] = 1;
        }
        
        for(int i = 0;i<n;i++) {
            if(!st[i])
                tarjan(i, true);
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++)
            if(isAP[i])
                ans++;
        
        printf("%d\n", ans);
    }
}