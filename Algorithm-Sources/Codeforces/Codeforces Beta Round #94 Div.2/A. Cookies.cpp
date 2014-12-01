#include<stdio.h>


int main()
{
        //freopen("input.in", "r", stdin);

        int a, n;
        int even, odd;
        int result;

        even=odd=0;

        scanf("%d", &n);

        for(int i=0; i<n; i++)
        {
                scanf("%d", &a);
                if(a%2==0)
                        even++;
                else
                        odd++;
        }


        if( odd%2==0 )
                printf("%d", even);
        else
                printf("%d", odd);
}