// 11/30
#include<stdio.h>

int main() {
//	freopen("input.in", "r", stdin);
	
	int nC;
	scanf("%d", &nC);
	
	for(int i = 0;i<nC;i++) {
		int N, C;
		scanf("%d %d", &N, &C);
		
		int v[1001];
		for(int j = 0;j<N;j++)
			scanf("%d", v+j);

		double ans = 1000.0;
		
		for(int j = 0;j<N-C+1;j++) {
			int sum = 0;
			for(int k = j;k<j+C;k++)
				sum += v[k];
			if(sum/(double)C < ans)
				ans = sum/(double)C;
			for(int k = j+C;k<N;k++) {
				sum += v[k];
				if(sum/(double)(k-j+1) < ans)
					ans = sum/(double)(k-j+1);
			}
		}
		printf("%.8lf\n", ans); // 정확도 문제로 8자리까지 표현
	}
}