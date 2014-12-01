#include<stdio.h>

long long com[31][31]={0,};

long long combi(int n, int m)
{
	if(n==m)
		return 1;
	if(m==0)
		return 1;

	if(com[n][m] != 0)
		return com[n][m];
	

//	printf("%d %d\n", n, m);
	return com[n][m] = combi(n-1,m) + combi(n-1,m-1);
}

int main(void)
{
	long long result=0;
	int n, m, t;
	int i;

//	freopen("input.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &t);

	for(i=0; i<=t-5; i++)
	{
		if(4+i > n || 1+(t-5-i) > m)
			continue;

		result+=(long long)combi(n,4+i)*(long long)combi(m,1+(t-5-i));
	}

	printf("%I64d", result);
}