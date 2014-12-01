#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
//    freopen("input.in", "r", stdin);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    
    int ar[50];
    for(int i =0;i<n;i++)
        scanf("%d", ar+i);
    sort(ar, ar+n);
    int cnt = k;
    int i;
    for(i = n-1;i>=0 && cnt < m;i--)
        cnt += ar[i] - 1;
    
    printf("%d\n", cnt < m ? -1 : n-i-1);
}