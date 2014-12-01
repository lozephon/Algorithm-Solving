#include<stdio.h>
#include<math.h>

long long com[1001][1001] = {0,};

long long combination(int n, int k) {
	if(com[n][k] != 0)
		return com[n][k];

	return com[n][k] = ((com[n-1][k-1] ? com[n-1][k-1] : combination(n-1, k-1)) + (com[n-1][k] ? com[n-1][k] : combination(n-1, k))) % 1000000007;
}

int main(void)
{
	
	for(int i = 1;i<=1000;i++) {
		com[i][0] = 1;
		com[i][1] = i;
		com[i][i] = 1;
	}

	long long a, b, c,f;
	int i;

	long long result = 1;

//	freopen("input.in", "r", stdin);

	scanf("%lld %lld %lld", &a, &b, &c);

	f = 2*c+1;

	if(2*c>a-1 || 2*c>b-1)
		result = 0;
	else {
		result *= combination(a-1,2*c)% 1000000007;
		result *= combination(b-1,2*c)% 1000000007;

	}

	printf("%lld",result%1000000007);
}