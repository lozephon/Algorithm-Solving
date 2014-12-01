// 알고리즘 1 - Part2 DFS
// DFS + Pruning
// Accepted(0)

#include<stdio.h>

int c, s, t;
int train[8];
int tickets[8][23][2];
int maxCost;

void dfs(int now, int idx, int cost, int exp) {
    if(cost + exp < maxCost)
        return;
    
    if(now > s) {
        if(maxCost < cost)
            maxCost = cost;
        return;
    }
    
    if(tickets[now][22][0] == 0) {
        dfs(now+1, 0, cost, exp);
        return;
    }
    
    int i;
    int ticketCost = tickets[now][idx][1]*(now - tickets[now][idx][0]);
    
    for(i = tickets[now][idx][0]; i<now; i++) {
        if(train[i] + tickets[now][idx][1] > c)
            break;
    }
    
    if(i == now) {
        for(i = tickets[now][idx][0]; i<now; i++)
            train[i] += tickets[now][idx][1];
        
        if(idx+1 >= tickets[now][22][0])
            dfs(now+1, 0, cost+ticketCost, exp-ticketCost);
        else
            dfs(now, idx+1, cost+ticketCost, exp-ticketCost);
        
        for(i = tickets[now][idx][0]; i<now; i++)
            train[i] -= tickets[now][idx][1];
    }
    
    if(idx+1 >= tickets[now][22][0])
        dfs(now+1, 0, cost, exp-ticketCost);
    else
        dfs(now, idx+1, cost, exp-ticketCost);
}

int main() {
//    freopen("input.in", "r", stdin);
    
    while(scanf("%d%d%d", &c, &s, &t) == 3) {
        if(c == 0 && s == 0 && t == 0)
            break;
        
        maxCost = 0;
        for(int i = 0;i<=s;i++) {
            train[i] = 0;
            tickets[i][22][0] = 0;
        }
        
        int maxExp = 0;
        
        for(int i = 0;i<t;i++) {
            int fr, to, n;
            scanf("%d%d%d", &fr, &to, &n);
            tickets[to][tickets[to][22][0]][0] = fr;
            tickets[to][tickets[to][22][0]++][1] = n;
            maxExp += (to-fr)*n;
        }
        
        dfs(0, 0, 0, maxExp);
        
        printf("%d\n", maxCost);
    }
}