// 20131004 Sorting 후 Greedy 하게 (원점까지 거리) 처리
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool mycompare(const pair<int, int> a, const pair<int, int> b) {
    return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

int main() {
//    freopen("input.in", "r", stdin);
    
    int n;
    int nOp = 0;
    vector<pair<int, int> > bombs;
    scanf("%d", &n);
    for(int i = 0;i<n;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(abs(x) > 0 && abs(y))
            nOp += 6;
        else
            nOp += 4;
        bombs.push_back(make_pair(x, y));
    }
    sort(bombs.begin(), bombs.end(), mycompare);
    printf("%d\n", nOp);
    for(int i = 0;i<n;i++) {
        int x = bombs[i].first, y = bombs[i].second;
        if(x > 0) printf("1 %d R\n", abs(x));
        if(x < 0) printf("1 %d L\n", abs(x));
        if(y > 0) printf("1 %d U\n", abs(y));
        if(y < 0) printf("1 %d D\n", abs(y));
        printf("2\n");
        if(x > 0) printf("1 %d L\n", abs(x));
        if(x < 0) printf("1 %d R\n", abs(x));
        if(y > 0) printf("1 %d D\n", abs(y));
        if(y < 0) printf("1 %d U\n", abs(y));
        printf("3\n");
    }
}
