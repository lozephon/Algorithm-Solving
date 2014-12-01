#include<stdio.h>

int map[501][501];

int main(void)
{
	freopen("input.in", "r", stdin);

	int n, m, k;
	int i, j;

	scanf("%d %d %d", &n, &m, &k);

	char temp[505];
	gets(temp);
	for(i=1; i<=n; i++)
	{
		gets(temp);
		for(j=1; j<=m; j++)
		{
			map[i][j] = temp[j-1] - '0';
		}
	}





}