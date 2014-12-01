#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;

int main() {
	freopen("input.in", "r", stdin);
	
	int fr, to, caseNum = 1;
	while(scanf("%d%d", &fr, &to) == 2) {
		if(fr == 0 && to == 0)
			break;
		
		int stoi[101], n = 0, e[100][100], d[100][100];
		memset(stoi, 0xff, sizeof(stoi));
		memset(e, 0, sizeof(e));
		memset(d, 0x07, sizeof(d));
		
		if(stoi[fr] == -1)
			stoi[fr] = n++;
		if(stoi[to] == -1)
			stoi[to] = n++;
		d[stoi[fr]][stoi[to]] = e[stoi[fr]][stoi[to]] = 1;
		
		while(scanf("%d%d", &fr, &to) == 2) {
			if(fr == 0 && to == 0)
				break;
			if(stoi[fr] == -1)
				stoi[fr] = n++;
			if(stoi[to] == -1)
				stoi[to] = n++;
			d[stoi[fr]][stoi[to]] = e[stoi[fr]][stoi[to]] = 1;	
		}
		
		for(int i = 0;i<n;i++)
			d[i][i] = 0;
		
		for(int k = 0;k<n;k++) {
			for(int i = 0;i<n;i++) {
				for(int j = 0;j<n;j++) {
					if(d[i][j] > d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
		
		int sum = 0;
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++)
				sum += d[i][j];
		}
		
		printf("Case %d: average length between pages = %.3lf clicks\n", caseNum++, (double)sum/(n*(n-1)));
	}
}