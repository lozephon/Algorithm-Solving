#include<stdio.h>

bool map[2000][2000];
int sum[2000][2000], row[2000][2000], col[2000][2000];

int main() {
//	freopen("input.in", "r", stdin);

	int n, ans = 0;
	scanf("%d", &n);
	
	char line[4];
	gets(line);

	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			char ch;
			scanf("%c", &ch);

			if(ch == '1')
				map[i][j] = 1;
		}

		gets(line);
	}

	col[0][n-1] = row[0][n-1] = sum[0][n-1] = map[0][n-1];
	row[n-1][0] = col[n-1][0] = sum[n-1][0] = map[n-1][0];

	for(int i = n-2;i>0;i--) {
		col[0][i] = sum[0][i] = row[0][i+1] + map[0][i];
		row[0][i] = row[0][i+1] + sum[0][i];
		row[i][0] = sum[i][0] = col[i+1][0] + map[i][0];
		col[i][0] = col[i+1][0] + sum[i][0];
	}
	sum[0][0] = row[0][1] + col[1][0] + map[0][0];

	for(int i = 1;i<n-1;i++) {
		col[n-1][i] = sum[n-1][i] = row[n-1][i-1] + map[n-1][i];
		row[n-1][i] = row[n-1][i-1] + sum[n-1][i];
		row[i][n-1] = sum[i][n-1] = col[i-1][n-1] + map[i][n-1];
		col[i][n-1] = col[i-1][n-1] + sum[i][n-1];
	}
	sum[n-1][n-1] = row[n-1][n-2] + col[n-2][n-1] + map[n-1][n-1];

	for(int i = 1;i<n-1;i++) {
		for(int j = n-2;j>=i;j--) {
			sum[i][j] += col[i-1][j] + row[i][j+1] + map[i][j];
			col[i][j] =  col[i-1][j] + sum[i][j];
			row[i][j] =  row[i][j+1] + sum[i][j];
		}
	}

	for(int i = n-2;i>0;i--) {
		for(int j = 1;j<=i;j++) {
			sum[i][j] += col[i+1][j] + row[i][j-1] + map[i][j];
			if(i == j)
				sum[i][j] -= map[i][j];

			col[i][j] =  col[i+1][j] + sum[i][j];
			row[i][j] =  row[i][j-1] + sum[i][j];
		}
	}

	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++)
			ans += sum[i][j] & 1;
	}

	printf("%d\n", ans);
}