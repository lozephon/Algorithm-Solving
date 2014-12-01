#include<stdio.h>
#include<math.h>

int main(void)
{
	int n;
	int i;
	int A[101]={0,};
	int sum=0;
	
//	freopen("input.in", "r", stdin);

	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		int temp;
		scanf("%d", &temp);
		A[temp]++;
	}

	for(i=0; i<101;i++)
	{
		sum += A[i]/2;

	}
	printf("%d\n",sum/2); 









}