#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<set>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	long long ar[10] = { 0, };
	set<int> sSet;

	for (int i = 0; i < 10; i++)
	{
		ar[i] = i;
		sSet.insert(i);
	}

	long long p[13] = { 1, };
	for (int i = 1; i < 13; i++)
		p[i] = p[i - 1] * 10;

	
	set<int> used;
	char str[50][100];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		
		scanf("%s", str[i]);
		for (int j = 0; str[i][j]; j++)
		{
			ar[toupper(str[i][j]) - 'A'] += p[strlen(str[i]) - j];
			used.insert(toupper(str[i][j]) - 'A');
		}
		if (sSet.find(toupper(str[i][0]) - 'A') != sSet.end())
		{
			sSet.erase(toupper(str[i][0]) - 'A');
		}
	}
	
	int idx = -1;
	long long minV = 1000000000000;
	if (used.size() == 10) {
		for (set<int>::iterator it = sSet.begin(); it != sSet.end(); it++) {
			if (minV > ar[*it])
			{
				minV = ar[*it];
				idx = *it;
			}
		}

		if (idx != -1)
		{
			ar[idx] = -1000 + idx;
		}
	}

	sort(ar, ar + 10);
	int num[10] = { 0, };
	for (int i = 9; i >= 0; i--)
	{
		num[(ar[i] % 10 + 10) % 10] = i;
		printf("%lld %d\n", ar[i], num[(ar[i] % 10 + 10) % 10]);
	}
	 
	long long ans = 0;
	for (int i = 0; i < n; i++)	
	{
		long long sum = 0;
		for (int j = 0; str[i][j]; j++)
		{
			sum += num[toupper(str[i][j]) - 'A'] * p[strlen(str[i]) - j - 1];
		}
		printf("%s - %d\n", str[i], sum);
		ans += sum;
	}
	printf("%lld\n", ans);
}