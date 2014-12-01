#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

char str[1001];

typedef struct Quadtree {
	char ch;
	struct Quadtree *child;
} Quadtree;

int makeTree(char *s, int idx, Quadtree &tree) {
	tree.ch = s[idx];
	idx++;
	if(s[idx-1] == 'x') {
		tree.child = (Quadtree *)malloc(sizeof(Quadtree) * 4);
		for(int i = 0;i<4;i++)
			idx = makeTree(s, idx, tree.child[i]);
	}
	return idx;
}

void printTree(Quadtree &tree) {
	printf("%c", tree.ch);
	if(tree.ch == 'x') {
		printTree(tree.child[2]);
		printTree(tree.child[3]);
		printTree(tree.child[0]);
		printTree(tree.child[1]);
	}
}

int main() {
//	freopen("input.in", "r", stdin);
	int c;
	scanf("%d", &c);
	
	while(c--) {
		scanf("%s", str);
		Quadtree tree;
		makeTree(str, 0, tree);
		printTree(tree);
		printf("\n");
	}
}