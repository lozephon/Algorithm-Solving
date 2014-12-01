// 알고리즘 1 - Part6 MST
// Prim using Priority Queue
// Accepted(6)

#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int caseNum = 1, n;
    while(scanf("%d", &n) == 1 && n != 0) {
        int v[200][2];
        double l[200][200] = {0, };
        
        for(int i = 0;i<n;i++)
            scanf("%d%d", &v[i][0], &v[i][1]);
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++)
                l[i][j] = l[j][i] = sqrt((double)((v[i][0]-v[j][0])*(v[i][0]-v[j][0])+(v[i][1]-v[j][1])*(v[i][1]-v[j][1])));
        }
        
        int visit[200] = {0, };
        priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;
        for(int i = 1;i<n;i++)
            q.push(make_pair(l[0][i], i));
        visit[0] = 1;
        
        double dis = 0.0;
        while(1) {
            while(visit[q.top().second]) q.pop();
            
            int now = q.top().second;
            double len = q.top().first;
            q.pop();
            
            if(dis < len)
                dis = len;
            
            if(now == 1)
                break;

            visit[now] = 1;
            for(int i = 0;i<n;i++) {
                if(!visit[i])
                    q.push(make_pair(l[now][i], i));
            }
        }

        printf("Scenario #%d\n", caseNum++);
        printf("Frog Distance = %.3lf\n\n", dis);
    }
}