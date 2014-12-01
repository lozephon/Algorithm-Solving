// 알고리즘 1 - Part6 MST
// Dijkstra using Priority Queue
// Accepted(0)

#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    char str[100];
    while(scanf("%s", str) == 1) {
        int e[30][30], v[30] = {0, }, sum = 0;
        memset(e, 0x77, sizeof(e));
        int len = (int)strlen(str);
        e[str[0]-'a'][str[len-1]-'a'] = e[str[len-1]-'a'][str[0]-'a'] = len;
        v[str[0]-'a']++;
        v[str[len-1]-'a']++;
        sum += len;
        
        while(scanf("%s", str) == 1 && strcmp(str, "deadend")) {
            len = (int)strlen(str);
            e[str[0]-'a'][str[len-1]-'a'] = e[str[len-1]-'a'][str[0]-'a'] = len;
            v[str[0]-'a']++;
            v[str[len-1]-'a']++;
            sum += len;
        }
        
        int st = -1, ed = -1;
        for(int i = 0;i<30;i++) {
            if(v[i] % 2) {
                if(st == -1)
                    st = i;
                else {
                    ed = i;
                    break;
                }
            }
        }
        if(st == -1) {
            printf("%d\n", sum);
            continue;
        }
        
        int d[30];

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        for(int i = 0;i<30;i++) {
            d[i] = e[st][i];
            q.push(make_pair(d[i], i));
        }

        while(!q.empty()) {
            int u = q.top().first, v = q.top().second; q.pop();
            
            if(v == ed)
                break;
            
            for(int i = 0;i<30;i++) {
                if(d[i] > u + e[v][i]) {
                    q.push(make_pair(u + e[v][i], i));
                    d[i] = u + e[v][i];
                }
            }
        }
        
        printf("%d\n", sum+d[ed]);
    }
}