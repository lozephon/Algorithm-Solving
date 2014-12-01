#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	freopen("input.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int B, K, in[11];
		scanf("%d %d", &B, &K);
		vector<int> S;
		vector<pair<int, int> > D;
		for(int i = 0; i < B; ++i)
		{
			scanf("%d", in+i);
			for(int j = 0; j <= i; ++j)
			{
				int pass = 1;
				for(int k = 0; k < 16 && pass; ++k)
				{
					if(((in[i] >> k) & 1) != ((in[j] >> (15-k)) & 1))
						pass = 0;
				}
				if(pass)
				{
					if(i == j)
						S.push_back(i);
					else
						D.push_back(make_pair(j, i));
				}
			}
		}
		sort(S.begin(), S.end());
		sort(D.begin(), D.end());
	}
	return 0;
}