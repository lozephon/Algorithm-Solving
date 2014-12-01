#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	freopen("input.in", "r", stdin);
	
	int n, m;
	while(scanf("%d%d", &n, &m) == 2) {
		int ar[301], sum[301]; sum[0] = 0;
		for(int i = 1;i<=n;i++) {
			scanf("%d", ar+i);
			sum[i] = sum[i-1] + ar[i];
		}
		
		int d[301][301];
		d[1][1] = ar[1];
		
		for(int i = 2;i<=n;i++) {
			d[i][1] = d[i-1][1]+ar[i];
			for(int j = 2;j<=i && j<=m;j++) {
				d[i][j] = 0x7fffffff;
				for(int k = j-1;k<i;k++) {
					int maxV = max(d[k][j-1], sum[i]-sum[k]);
					if(d[i][j] > maxV)
						d[i][j] = maxV;
				}
			}
		}
		
		printf("%d\n", d[n][m]);
	}
}