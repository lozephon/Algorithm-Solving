#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	freopen("input.in", "r", stdin);
	char s1[100], s2[100];
	int len1, len2;
	bool isFirst = false;
	while(gets(s1)) {
		gets(s2);
		if(isFirst)
			printf("\n");
		isFirst = true;
		
		//printf("%s\n%s\n", s1, s2);
		int d[100][100] = {0, };
		int p[100][100] = {0, };
		len1 = (int)strlen(s1);
		len2 = (int)strlen(s2);
		for(int i = 0;i<=len1;i++) {
			d[i][0] = i;
			p[i][0] = 2;
		}
		for(int j = 0;j<=len2;j++) {
			d[0][j] = j;
			p[0][j] = 3;
		}
		d[0][0] = 0;
		p[0][0] = 0;
		/*
		for(int i = 0;i<=len1;i++) {
			for(int j =0;j<=len2;j++)
				printf("%d ", d[i][j]);
			printf("\n");
		}
		*/
		
		for(int i = 1;i<=len1;i++) {
			for(int j = 1;j<=len2;j++) {
				int a = d[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1);
				int b = d[i-1][j] + 1, c = d[i][j-1] + 1;
				if(a < b) {
					if(a < c) {
						d[i][j] = a;
						p[i][j] = s1[i-1] == s2[j-1] ? 4 : 1;
					}
					else {
						d[i][j] = c;
						p[i][j] = 3;
					}
				}
				else {
					if(b < c) {
						d[i][j] = b;
						p[i][j] = 2;
					}
					else {
						d[i][j] = c;
						p[i][j] = 3;
					}
				}
			}
		}
		/*
		for(int i = 0;i<=len1;i++) {
			for(int j =0;j<=len2;j++)
				printf("%d ", d[i][j]);
			printf("\n");
		}*/
		int x = len1, y = len2;
		vector<pair<int, int> > path;
		while(p[x][y] != 0 && x >= 0 && y >= 0) {
			//printf("(%d %d, %d, %c)", x, y, p[x][y], pch[x][y]);
			if(p[x][y] == 1 || p[x][y] == 4) {
				x--;
				y--;
				if(p[x+1][y+1] != 4)
					path.push_back(make_pair(p[x+1][y+1], y+1));
			}
			else if(p[x][y] == 2) {
				x--;
				path.push_back(make_pair(p[x+1][y], y+1));
			}
			else if(p[x][y] == 3) {
				y--;
				path.push_back(make_pair(p[x][y+1], y+1));
			}
		}
		//printf("(%d %d, %d, %c)", x, y, p[x][y], pch[x][y]);
		
		//printf("\n");
		printf("%d\n", d[len1][len2]);
		for(int i = (int)path.size()-1; i>=0;i--) {
			printf("%d ", (int)path.size()-i);
			if(path[i].first == 1 || path[i].first == 4)
				printf("Replace %d,%c", path[i].second, s2[path[i].second-1]);
			else if(path[i].first == 2)
				printf("Delete %d", path[i].second);
			else if(path[i].first == 3)
				printf("Insert %d,%c", path[i].second, s2[path[i].second-1]);
			printf("\n");
		}
	}
}