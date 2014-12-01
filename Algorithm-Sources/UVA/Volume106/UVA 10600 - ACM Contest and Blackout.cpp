// 알고리즘 1 - Part6 MST
// Kruskal
// Accepted(4)

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge {
    int fr, to;
    int cost;
    int used;
    Edge() {used = 0;};
    Edge(int _fr, int _to, int _cost) {
        fr = _fr;
        to = _to;
        cost = _cost;
    };
    bool operator <(const Edge &e) const {
        return this->cost < e.cost;
    }
};

int g[101];
vector<Edge> e;

int gNum(int n) {
    vector<int> temp;
    while(n != g[n]) {
        temp.push_back(n);
        n = g[n];
    }
    for(int i = 0;i<temp.size();i++)
        g[temp[i]] = n;
    
    return n;
}

int gUnion(int n, int m) {
    if(gNum(n) < gNum(m))
        g[g[m]] = g[n];
    else
        g[g[n]] = g[m];
}

int temp;
int mst(int n) {
    for(int i = 1;i<=n;i++)
        g[i] = i;
    
    int found = 0, sum = 0;
    for(int i = 0;i<e.size() && found < n-1;i++) {
        if(e[i].used != 3) {
            if(gNum(e[i].fr) != gNum(e[i].to)) {
                gUnion(e[i].fr, e[i].to);
                found++;
                if(!e[i].used)
                    e[i].used = temp;
                sum += e[i].cost;
            }
        }
    }
    
    if(temp < 2)
        temp++;
    
    if(found < n-1)
        return 0x7fffffff;
    
    return sum;
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        
        e.clear();
        e.resize(m);

        for(int i = 0;i<m;i++)
            scanf("%d%d%d", &e[i].fr, &e[i].to, &e[i].cost);
        
        sort(e.begin(), e.end());
        
        temp = 1;
        int minOne = mst(n);
        int minTwo = 0x7fffffff;
        for(int i = 0;i<e.size();i++) {
            if(e[i].used == 1) {
                e[i].used = 3;
                minTwo = min(minTwo, mst(n));
                e[i].used = 2;
            }
        }
        
        printf("%d %d\n", minOne, minTwo);
    }
}