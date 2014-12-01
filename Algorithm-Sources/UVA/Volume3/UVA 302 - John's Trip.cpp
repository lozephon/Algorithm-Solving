// 알고리즘 1 - Part4 Euler Path
// Euler Circuit
// Accepted(0)

#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int> > street[50];
int st;
vector<int> a, b;
bool used[2000];

void dfs(int now) {
    for(int i = 0;i<street[now].size();i++) {
        if(!used[street[now][i].first]) {
            a.push_back(street[now][i].first);
            used[street[now][i].first] = true;
            dfs(street[now][i].second);
        }
    }
    b.push_back(a.back()); a.pop_back();
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int x, y, z;
    while(1) {
        scanf("%d%d", &x, &y);
        if(x == 0 && y == 0)
            break;
        scanf("%d", &z);
        
        for(int i = 0;i<50;i++)
            street[i].clear();
        
        int v[50] = {0, };
        st = min(x, y);
        street[x].push_back(make_pair(z, y));
        street[y].push_back(make_pair(z, x));
        v[x]++;
        v[y]++;
        
        while(scanf("%d%d", &x, &y) == 2 && (x != 0 || y != 0)) {
            scanf("%d", &z);
            
            street[x].push_back(make_pair(z, y));
            street[y].push_back(make_pair(z, x));
            v[x]++;
            v[y]++;
        }
        
        bool canGo = true;
        fill(used, used+2000, 0);
        for(int i = 0;i<50;i++) {
            if(v[i] % 2)
                canGo = false;
            sort(street[i].begin(), street[i].end());
        }
        
        a.clear();
        b.clear();
        
        if(!canGo) {
            printf("Round trip does not exist.\n\n");
            continue;
        }
        
        dfs(st);
        
        printf("%d", b[b.size()-2]);
        for(int i = (int)b.size()-3;i>=0;i--)
            printf(" %d", b[i]);
        
        printf("\n\n");
    }
}