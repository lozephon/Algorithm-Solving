#include<stdio.h>
#include<vector>
#include<string>
#include<memory.h>
#include<algorithm>
using namespace std;

int e[28][28];
bool isIn[28], visited[28];
vector<int> vStack;

void dfs(int now) {
    visited[now] = true;

    for(int i = 0;i<28;i++) {
        if(e[now][i] && !visited[i] && isIn[i])
            dfs(i);
    }
    
    vStack.push_back(now);    
}

void findSCC(int now, vector<int> &scc) {
    visited[now] = true;
    scc.push_back(now);
    
    for(int i = 0;i<28;i++) {
        if(e[i][now] && !visited[i] && isIn[i])
            findSCC(i, scc);
    }    
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int nQ;
    while(scanf("%d", &nQ) == 1 && nQ != 0) {
        memset(e, 0, sizeof(e));
        memset(isIn, 0, sizeof(isIn));
        memset(visited, 0, sizeof(isIn));
        
        vStack.clear();
        
        char line[5];
        gets(line);
        
        for(int i = 0;i<nQ;i++) {
            char c[6];
            scanf("%c %c %c %c %c %c", c, c+1, c+2, c+3, c+4, c+5);
            gets(line);
            for(int j = 0;j<5;j++) {
                e[c[5]-'A'][c[j]-'A'] = 1;
                isIn[c[j]-'A'] = true;
            }
            e[c[5]-'A'][c[5]-'A'] = 0;
        }
        
        for(int i = 0;i<28;i++) {
            if(!visited[i] && isIn[i])
                dfs(i);
        }
        
        memset(visited, 0, sizeof(visited));
        
        vector<string> g;
        
        for(int i = (int)vStack.size()-1; i>=0;i--) {
            if(!visited[vStack[i]]) {
                vector<int> scc;
                findSCC(vStack[i], scc);        
                sort(scc.begin(), scc.end());
                string sccStr = "";
                for(int j = 0;j<scc.size();j++)
                    sccStr += (char)(scc[j]+'A');
                g.push_back(sccStr);
            }
        }
        
        static bool firstline = false;
        if(firstline)
            printf("\n");
        firstline = true;
        
        sort(g.begin(), g.end());
        for(int i = 0;i<g.size();i++) {
            printf("%c", g[i][0]);
            for(int j = 1;j<g[i].length();j++)
                printf(" %c", g[i][j]);
            printf("\n");
        }
    }
}