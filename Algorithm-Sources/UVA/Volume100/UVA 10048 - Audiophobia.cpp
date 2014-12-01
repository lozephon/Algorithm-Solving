#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;

int main() {
	freopen("input.in", "r", stdin);
	
	int c, s, q;
	while(scanf("%d%d%d", &c, &s, &q) == 3) {
		if(c == 0 && s == 0 && q == 0)
			break;
		
		int d[101][101];
		memset(d, -1, sizeof(d));
		
		for(int i = 0;i<s;i++) {
			int fr, to, decibel;
			scanf("%d%d%d", &fr, &to, &decibel);
			
			d[fr][to] = d[to][fr] = decibel;
		}
		
		for(int k = 1;k<=c;k++) {
			for(int i = 1;i<=c;i++) {
				for(int j = 1;j<=c;j++) {
					if(d[i][k] != -1 && d[k][j] != -1) {
						if(d[i][j] == -1 || d[i][j] > max(d[i][k], d[k][j]))
							d[i][j] = max(d[i][k], d[k][j]);
					}
				}
			}
		}
		
		static int caseNum = 1;
		static bool line = false;
		if(line)
			printf("\n");
		line = true;
		
		printf("Case #%d\n", caseNum++);
		for(int i = 0;i<q;i++) {
			int fr, to;
			scanf("%d%d", &fr, &to);
			
			if(d[fr][to] == -1)
				printf("no path\n");
			else
				printf("%d\n", d[fr][to]);
		}
	}
}