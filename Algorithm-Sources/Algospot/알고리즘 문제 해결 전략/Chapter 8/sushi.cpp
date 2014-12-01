#include<stdio.h>
#include<map>
#include<queue>
#include<iostream>
using namespace std;

priority_queue<pair<int, int> > q;
//queue<pair<int, int> > q;
map<long long, int> d;
int nV;

int main() {
    freopen("input.in", "r", stdin);
    
    int c;
    scanf("%d", &c);
    
    while(c--) {
        int n;
        long long m;
        int ans = 0;
        
        scanf("%d %lld", &n, &m);
        
        d.clear();
        
        pair<int, int> ar[20];
        for(int i = 0;i<n;i++)
            scanf("%d%d", &ar[i].first, &ar[i].second);
        
        sort(ar, ar+n);
        
        for(int i = 0;i<n;i++) {
            q.push(ar[i]);
            d[ar[i].first] = ar[i].second;
            ans = max(ans, d[ar[i].first]);
        }
        
        while(!q.empty()) {
            long long now = q.top().first;
            int value = q.top().second;
            q.pop();
            
            if(d[now] != value)
                continue;
            
            for(int i = 0;i<n;i++) {
                long long newNow = now + ar[i].first;
                if(newNow > m) continue;
                int newValue = value + ar[i].second;
                if(d.find(newNow) == d.end() || d[newNow] < newValue) {
                    d[newNow] = newValue;
                    q.push(make_pair(newNow, newValue));
                }
                
                ans = max(ans, newValue);
            }
        }
        
        printf("%d\n", ans);
    }
}