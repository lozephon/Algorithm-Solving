#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int main() {
//	freopen("input.in", "r", stdin);
	
	int caseNum;
	scanf("%d", &caseNum);
	
	while(caseNum--) {
		int d[1001][100];
		int p[1001][100];
		memset(d, -1, sizeof(d));
		memset(p, -1, sizeof(p));
		
		int n, w;
		scanf("%d%d", &n, &w);
		
		char names[100][30];
		int weight[100], urgency[100];
		for(int i = 0;i<n;i++)
			scanf("%s%d%d", names[i], weight+i, urgency+i);
		
		d[0][0] = 0;
		p[0][0] = 0;
		d[weight[0]][0] = urgency[0];
		p[weight[0]][0] = 0;
		
		int ans = 0, ansPos = 0;
		for(int i = 1;i<n;i++) {
			for(int j = 0;j<=w;j++) {
				d[j][i] = d[j][i-1];
				p[j][i] = j;
				if(j-weight[i] >= 0 && d[j-weight[i]][i-1] != 1) {
					if(d[j-weight[i]][i-1] + urgency[i] > d[j][i]) {
						d[j][i] = d[j-weight[i]][i-1] + urgency[i];
						p[j][i] = j-weight[i];
					}
				}
				if(ans < d[j][i]) {
					ansPos = j;
					ans = d[j][i];
				}
			}
		}
		
		vector<int> ansSet;
		int nX = ansPos;
		for(int nY = n-1;nY>=0;nY--) {
			//printf("%d, %d ,%d\n", nX, nY, p[nX][nY]);
			if(p[nX][nY] != nX)
				ansSet.push_back(nY);
			nX = p[nX][nY];
		}
		
		printf("%d %d\n", ans, (int)ansSet.size());
		for(int i = 0;i<ansSet.size();i++)
			printf("%s\n", names[ansSet[i]]);
	}
}
