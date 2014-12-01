#include <stdio.h>
 
int main(void)
{
	freopen("input.in", "r", stdin);
    int T;
    scanf("%d", &T);
 
    long long b[2001] = {1,};
	long long h[2001] = {0,};
    for(int i = 1; i < 2001; ++i)
        b[i] = (b[i-1] << 1LL)%1000000009LL;
	for(int i = 0; i < 2001; ++i)
	{
		for(int j = 0; j < i; ++j)
			h[i] = (h[i] + h[j] + 1)%1000000009LL;
	}
 
    while(T--) {
        int N, in[2001];
		long long dd[2001] = {0,}, du[2001] = {0,}, eq[2001] = {0,};
        scanf("%d", &N);
 
        long long ans = 0;
        for(int i = 0; i < N; ++i)
        {
            scanf("%d", in+i);
            long long sumDU = 0, sumUD = 0;
            for(int j = 0; j < i; ++j)
            {
                if(in[j] > in[i])
                {
                    dd[i] = dd[i] + dd[j] + 1LL;
					sumUD = sumUD + du[j] - h[eq[j]];
                }
                else if(in[j] < in[i])
                {
                    du[i] = du[i] + du[j] + 1LL;
					sumDU = sumDU + dd[j] - h[eq[j]];
                }
				else
				{
					dd[i] = dd[i] + dd[j] + 1LL;
					du[i] = du[i] + du[j] + 1LL;
					eq[i] = eq[j] + 1;
				}
            }
 
            dd[i] %= 1000000009LL;
            sumDU %= 1000000009LL;
            du[i] %= 1000000009LL;
            sumUD %= 1000000009LL;
 
            ans += ((sumUD + sumDU) * b[N-i-1]) % 1000000009LL;
            ans %= 1000000009LL;
        }
 
        printf("%lld\n", ans);
    }
 
    return 0;
}