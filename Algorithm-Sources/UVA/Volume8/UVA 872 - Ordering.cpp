#include<stdio.h>
#include<sstream>
#include<vector>
#include<memory.h>
#include<string.h>
using namespace std;

int ctoi[30];
int var[30], n, inE[30];
vector<int> e[30];
char strs[30];
bool visited[30], isAns;

void tpsort(int now, int level) {
    for(int i = 0;i<e[now].size();i++)
        inE[e[now][i]]--;
    visited[now] = true;
    
    strs[level] = var[now]+'A';
    
    for(int i = 0;i<n;i++) {
        if(!inE[i] && !visited[i])
            tpsort(i, level+1);
    }
    
    for(int i = 0;i<e[now].size();i++)
        inE[e[now][i]]++;
    visited[now] = false;
    
    if(level == n-1) {
        printf("%c", strs[0]);
        for(int i = 1;i<n;i++)
            printf(" %c", strs[i]);
        printf("\n");
        isAns = true;
    }
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int caseNum;
    scanf("%d", &caseNum);
    char line[3];
    gets(line);
    gets(line);    
    
    while(caseNum--) {        
        n = 0;
        memset(var, 0, sizeof(var));
        memset(inE, 0, sizeof(inE));
        memset(ctoi, 0, sizeof(ctoi));
        
        char str[1000];
        gets(str);
        istringstream sin(str);
        char v;
        while(sin >> v) {
            ctoi[v-'A'] = n;
            var[n++] = v-'A';
        }
        
        for(int i = 0;i<n;i++)
            e[i].clear();
        
        while(gets(str) && strcmp(str, "")) {
            char st, ed, sp;
            istringstream sin2(str);
            while(sin2 >> st >> sp >> ed) {
                e[ctoi[st-'A']].push_back(ctoi[ed-'A']);
                inE[ctoi[ed-'A']]++;
            }
        }
        
        memset(visited, 0, sizeof(visited));
        
        isAns = false;
        
        for(int i = 0;i<n;i++) {
            if(!inE[i])
                tpsort(i, 0);
        }
        
        if(!isAns)
            printf("NO\n");
        
        if(caseNum)
            printf("\n");
    }
}