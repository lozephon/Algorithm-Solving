#include<stdio.h>
#include<vector>
using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int n, m;
    while(scanf("%d%d", &n, &m) == 2) {
        if(n == 0 && m == 0)
            break;
        
        int inE[100] = {0, };
        vector<int> e[100];
        
        for(int i = 0;i<m;i++) {
            int st, ed;
            scanf("%d%d", &st, &ed);
            st--; ed--;
            e[st].push_back(ed);
            inE[ed]++;
        }
        
        int nVisited = 0;
        while(nVisited < n) {
            for(int i = 0;i<n;i++) {
                if(!inE[i]) {
                    inE[i] = -1;
                    nVisited++;
                    
                    static bool firstsp = false;
                    if(firstsp)
                        printf(" ");
                    firstsp = true;
                    
                    printf("%d", i+1);
                    for(int j = 0;j<e[i].size();j++)
                        inE[e[i][j]]--;
                }
            }
        }
        printf("\n");
    }
}