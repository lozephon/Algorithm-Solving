#include<stdio.h>


int main(void)
{
	//freopen("input.in", "r", stdin);

	int number;
	int zero=0;
	int minu[11]={0,};
	int plus[11]={0,};


	int i;
	int temp;

	long long result=0;

	scanf("%d", &number);

	for(i=0;i<number; i++)
	{
		scanf("%d", &temp);
		if(temp==0)
			zero++;
		else if(temp>0)
			plus[temp]++;
		else if(temp<0)
			minu[-temp]++;
	}

	for(i=1; i<11; i++)
		result+=(long long)plus[i]*minu[i];
	
	if(zero>1)
		result+=(long long)zero*(zero-1)/2;

	printf("%lld", result);
	
}

