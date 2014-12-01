#include<stdio.h>
#include<math.h>

int main(void)
{
	int n, k;

	int i;
	double sum = 0.0;

//	freopen("input.in", "r", stdin);

	scanf("%d %d", &n, &k);

	int bx, by, x, y;
	scanf("%d%d", &bx, &by);

	for(i=1; i<n; i++)
	{
		scanf("%d %d", &x, &y);

		sum = sum + sqrt( (double)(bx-x)*(bx-x)+(by-y)*(by-y) ) ;
		bx = x; 
		by = y;
	}

	sum= sum*k*0.005*4;

	printf("%.8lf\n", sum);

}