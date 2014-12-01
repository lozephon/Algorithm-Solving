#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;

int arr[1000][100];
int ans[10000][2];
int nAns = 0;

int main() {
//    freopen("input.in", "r", stdin);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++)
            scanf("%d", &arr[i][j]);
    }
    
    for(int i = 0;i<m-1;i++) {
        bool check = false;
        set<pair<int, int> > tempAns;
        for(int l = 0;l<n;l++) {
            int v = arr[l][i];
            int idx = i;
            for(int j = i+1;j<m;j++) {
                if(k == 0 && v > arr[l][j]) {
                    v = arr[l][j];
                    idx = j;
                }
                else if(k == 1 && v < arr[l][j]) {
                    v = arr[l][j];
                    idx = j;
                }
            }
            if(idx != i) {
                check = true;
                if(k == 0)
                    tempAns.insert(make_pair(i, idx));
                else
                    tempAns.insert(make_pair(idx, i));
            }
        }
        for(set<pair<int, int> >::iterator j = tempAns.begin();j != tempAns.end(); j++) {
            int a = j->first, b = j->second;
            ans[nAns][0] = a;
            ans[nAns][1] = b;
            nAns++;
            for(int l = 0;l<n;l++) {
                if(arr[l][a] > arr[l][b])
                    swap(arr[l][a], arr[l][b]);
            }
        }
    }
    
    printf("%d\n", nAns);
    for(int i = 0;i<nAns;i++)
        printf("%d %d\n", ans[i][0]+1, ans[i][1]+1);
}