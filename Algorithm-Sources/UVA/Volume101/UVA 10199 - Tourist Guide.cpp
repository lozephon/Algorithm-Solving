#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;

map<string, int> stoi;
map<int, string> itos;
vector<string> cams;
int n, vt[101], low[101], ttime;
int e[101][101], nE;
bool isAP[101];

int tarjan(int now, bool isRoot) {
    vt[now] = low[now] = ++ttime;
    
    int nChild = 0;
    for(int i = 0; i<n;i++) {
        if(e[now][i]) {
            e[now][i] = e[i][now] = 0;
            
            if(vt[i])
                low[now] = min(low[now], vt[i]);
            else {
                nChild++;
                low[now] = min(low[now], tarjan(i, false));
            }
            
            if(vt[now] <= low[i])
                isAP[now] = true;
        }
    }
    
    if(isRoot) {
        if(nChild >= 2)
            isAP[now] = true;
        else
            isAP[now] = false;
    }
    
    return low[now];
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int caseNum = 1;
    
    while(scanf("%d", &n) == 1 && n != 0) {
        stoi.clear();
        itos.clear();
        cams.clear();
        
        ttime = 0;
        
        for(int i = 0;i<n;i++) {
            string s;
            cin >> s;
            stoi[s] = i;
            itos[i] = s;
        }
        
        memset(e, 0, sizeof(e));
        memset(isAP, 0, sizeof(isAP));
        memset(vt, 0, sizeof(vt));
        memset(low, 0, sizeof(low));
        
        scanf("%d", &nE);
        
        for(int i = 0;i<nE;i++) {
            string st, ed;
            cin >> st >> ed;
            e[stoi[st]][stoi[ed]] = e[stoi[ed]][stoi[st]] = 1;
        }
        
        for(int i = 0;i<n;i++) {
            if(vt[i] == 0)
                tarjan(i, true);
        }
        
        for(int i = 0;i<n;i++) 
            if(isAP[i])
                cams.push_back(itos[i]);
        
        sort(cams.begin(), cams.end());
        
        if(caseNum != 1)
            printf("\n");
        
        printf("City map #%d: %d camera(s) found\n", caseNum++, (int)cams.size());
        for(int i = 0;i<cams.size();i++)
            cout << cams[i] << endl;
    }
}