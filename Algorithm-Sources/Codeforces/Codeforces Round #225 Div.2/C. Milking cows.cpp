#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int l[200000], r[200000], ar[200000];
int n;

typedef struct Node {
    int minFrom, minValue;
    struct Node *left, *right, *parent;
    int leaf;
    int type;
    int added;
    int state;
} Node;

#define HEAD 0
#define LEFT -1
#define RIGHT -2

Node head;

int make_tree(int fr, int to, Node &now) {
    if(to - fr == 1) { // leaf
        now.leaf = l[fr] + r[fr];
        return now.leaf;
    }
    
    now.left = (Node *)malloc(sizeof(Node));
    now.left->leaf = -1;
    now.left->type = LEFT;
    now.left->added = 0;
    now.left->parent = &now;
    
    now.right = (Node *)malloc(sizeof(Node));
    now.right->leaf = -1;
    now.right->type = RIGHT;
    now.right->added = 0;
    now.right->parent = &now;
    
    int leftMin = make_tree(fr, (fr+to)/2, *now.left);
    int rightMin = make_tree((fr+to)/2, to, *now.left);
    if(leftMin <= rightMin) {
        now.minFrom = LEFT;
        now.minValue = leftMin;
    }
    else {
        now.minFrom = RIGHT;
        now.minValue = rightMin;
    }
    return now.minValue;
}

int getMin(Node &now) {
    if(now.leaf != -1) {
        return now.leaf;
    }
    
    int rtn;
    if(now.minFrom == LEFT) {
        rtn = getMin(*now.left);
    }
    else {
        rtn = getMin(*now.right);
    }
    return rtn;
}

int main() {
    freopen("input.in", "r", stdin);
    
    head.type = HEAD;
    head.added = 0;
    
    scanf("%d", &n);
    for(int i = 0;i<n;i++)
        scanf("%d", ar+i);
    for(int i = 1;i<n;i++)
        l[i] = l[i-1]+(ar[i] == 1);
    for(int i = n-2;i>=0;i--)
        r[i] = r[i+1]+(ar[i] == 0);
    
    make_tree(0, n, head);
    int ans = 0;
    for(int i = 0;i<n;i++)
        ans += getMin(head);
    printf("%d\n", ans);
}