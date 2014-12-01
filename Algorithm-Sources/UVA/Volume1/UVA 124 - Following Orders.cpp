#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
#include<memory.h>
using namespace std;

int ctoi[30];
vector<int> var;
vector<int> e[30];
int inE[30];
int visited[30];

void tpsort(int level, char *strs) {
    for(int i = 0;i<var.size();i++) {
        if(!visited[i] && inE[i] == 0) {
            visited[i] = 1;
            for(int j = 0; j<e[i].size();j++) 
                inE[e[i][j]]--;
            
            strs[level] = var[i]+'a';
            if(level < var.size())
                tpsort(level+1, strs);
            
            visited[i] = 0;
            for(int j = 0; j<e[i].size();j++) 
                inE[e[i][j]]++;                
        }
    }
    if(level == var.size())
        printf("%s\n", strs);    
}

int main() {
//    freopen("input.in", "r", stdin);
    
    string str;
    while(getline(cin, str)) {
//        cout << str << endl;
        
        istringstream sin(str);
        char v;
        var.clear();
        while(sin >> v) 
            var.push_back(v-'a');
        
        sort(var.begin(), var.end());
        for(int i = 0;i<var.size();i++) {
            ctoi[var[i]] = i;
            e[i].clear();
        }
        
        memset(inE, 0, sizeof(inE));
        memset(visited, 0, sizeof(visited));
        
        getline(cin, str);
        istringstream sin2(str);
        
        char st, ed;
        while(sin2 >> st >> ed) {
            e[ctoi[st-'a']].push_back(ctoi[ed-'a']);
            inE[ctoi[ed-'a']]++;
        }
        
        static bool firstline = false;
        if(firstline)
            printf("\n");
        firstline = true;
        
        for(int i = 0;i<var.size();i++) {
            if(inE[i] == 0) {
                visited[i] = 1;
                for(int j = 0; j<e[i].size();j++)
                    inE[e[i][j]]--;
                
                char strs[30] = {var[i]+'a', 0};
                tpsort(1, strs);
                
                visited[i] = 0;
                for(int j = 0; j<e[i].size();j++) 
                    inE[e[i][j]]++;                
            }
        }
    }
}