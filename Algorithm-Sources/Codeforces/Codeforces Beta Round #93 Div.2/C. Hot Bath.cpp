#include<stdio.h>
#include<math.h>


int main(void)
{
	int t1,t2,x1,x2, t0, i;
	int a, b;
	int y1, y2;
	double temp, temp2;
	double rate=0;
	double remain=10;
	int c, d;
	int temp3;



//	freopen("input.in", "r", stdin);

	scanf("%d %d %d %d %d", &t1, &t2, &x1, &x2, &t0);

	a=t0-t1;
	b=t2-t0;

	y1=y2=0;


	if(t1!=t0 && t2!=t0)
	{
		rate=(double)(t2-t0)/(t0-t1);

		i=0;
		temp2=rate;
		temp3=(int)temp2;

		while(i<=x2 && temp3<=x1)
		{
			temp=temp2-temp3;

			if(remain>=temp)
			{
				
				remain=temp;
				y1=i;
				y2=temp3;
			
			}
			temp=temp3-temp2;

			if(temp<0)
				temp=temp+1;

			if(remain>=temp)
			{
				
				remain=temp;
				y1=i;
				y2=temp3;
			
			}
			
			i++;
			temp2=rate*i;
			temp3=(int)temp2;

		}

		if(y2!=0)
			a=(int)x1/y2;
		if(y1!=0)
			b=(int)x2/y1;

		c= (a<b)? a:b;

		if(c>1)
		{
			y1*=c;
			y2*=c;
		}
	}
	if(t1==t0)
	{
		y2=x1;
	}

	if(t2==t0)
	{
		y1=x2;
	}

	 if(y1==0 && y2==0)
	 {
		 y1=x2;
		 y2=x1;
	 }


	printf("%d %d\n", y2, y1);

}