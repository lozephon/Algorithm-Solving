#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<algorithm>
using namespace std;

int d[20][1<<15][2], n, m, digit[15];
char e[15];

int solve(int now, int rem, int rest, bool isCheck) {
	/*
	printf("%d %d - ", now, rem);
	for(int i = 0;i<n;i++)
		printf("%d ", (rest & (1<<i)) ? 1 : 0);
	printf(", %d\n", rest);
	*/
	
	if(now == n) {
		if(rem == 0)
			return 1;
		return 0;
	}
	
	if(d[rem][rest][isCheck] != -1)
		return d[rem][rest][isCheck];
	
	int rtn = 0;
	for(int i = 0;i<n;i++) {
		if(!(rest & 1 << i)) {
			if(i != 0 && digit[i-1] == digit[i] && !(rest & 1 << (i-1)))
				continue;

			if(isCheck) {
				if(digit[i] == (e[now]-'0'))
					rtn += solve(now+1, ((rem * 10 + digit[i]) % m), rest | 1 << i, true);
				else if(digit[i] < (e[now]-'0'))
					rtn += solve(now+1, ((rem * 10 + digit[i]) % m), rest | 1 << i, false);
				else
					break;
			}
			else
				rtn += solve(now+1, ((rem * 10 + digit[i]) % m), rest | 1 << i, false);
			rtn %= 1000000007;
		}
	}
	return d[rem][rest][isCheck] = rtn;
}

int main() {
//	freopen("input.in", "r", stdin);
	
	int caseNum;
	scanf("%d", &caseNum);
	
	while(caseNum--) {
		scanf("%s%d", e, &m);
		
		n = (int)strlen(e);
		int rem = 0;
		for(int i = 0;i<n;i++) {
			digit[i] = e[i] - '0';
			rem = (rem*10 + digit[i]) % m;
		}
		sort(digit, digit+n);
		
		memset(d, -1, sizeof(d));
		
		//for(int i = 0;i<n;i++)
		//	printf("%d", digit[i]);
		//printf("\n");
		
		printf("%d\n", solve(0, 0, 0, true)-(rem == 0));
	}
}