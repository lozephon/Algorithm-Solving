// 알고리즘 1 - Part3 BFS
// BFS
// Accepted(2)

#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

int main() {
//    freopen("input.in", "r", stdin);
    
    int caseNum;
    bool first = false;
    
    scanf("%d", &caseNum);
    while(caseNum--) {
        if(first)
            printf("\n");
        first = true;
        
        int n, cat, mouse;
        scanf("%d%d%d", &n, &cat, &mouse);
        
        int catE[101][101], mouseE[101][101], catV[101], mouseV[101];
        int st, ed;
        
        memset(catE, 0, sizeof(catE));
        memset(mouseE, 0, sizeof(mouseE));
        memset(catV, 0, sizeof(catV));
        memset(mouseV, 0, sizeof(mouseV));
        
        while(scanf("%d%d", &st, &ed) == 2 && st != -1)
            catE[st][ed] = 1;
        
        char line[20];
        
        gets(line);
        while(gets(line) && strcmp(line, "") != 0) {
            sscanf(line, "%d%d", &st, &ed);
            mouseE[st][ed] = 1;
        }
        
        queue<int> q; q.push(cat);
        catV[cat] = 1;
        while(!q.empty()) {
            int top = q.front(); q.pop();
            for(int i = 1;i<=n;i++) {
                if(catE[top][i] && !catV[i]) {
                    catV[i] = 1;
                    q.push(i);
                }
            }
        }
        
        bool ans1 = cat != mouse, ans2 = false;
        q.push(mouse);
        while(!q.empty()) {
            int top = q.front(); q.pop();
            for(int i = 1;i<=n;i++) {
                if(mouseE[top][i] && !mouseV[i]) {
                    if(catV[i])
                        ans1 = false;
                    else {
                        mouseV[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
        
        if(mouseV[mouse])
            ans2 = true;
        
        printf("%s ", ans1 ? "N" : "Y");
        printf("%s\n", ans2 ? "Y" : "N");
    }
}