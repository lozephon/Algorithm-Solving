#include<stdio.h>

int minV;
int dc[10][10] = {
	{3, 0, 1, 2},
	{4, 3, 7, 9, 11},
	{4,	4, 10, 14, 15},
	{5, 0, 4, 5, 6, 7},
	{5, 6, 7, 8, 10, 12},
	{4, 0, 2, 14, 15},
	{3, 3, 14, 15},
	{5, 4, 5, 7, 14, 15},
	{5, 1, 2, 3, 4, 5},
	{5, 3, 4, 5, 9, 13}
};

void search(int now, int sum, int *clock) {
	if(now == 10) {
		int i = 0;
		for(;i<16;i++)
			if(clock[i] != 3)
				break;
		if(i == 16)
			minV = minV > sum ? sum : minV;
		return;
	}
	
	int nClock[16];
	for(int i = 0;i<16;i++)
		nClock[i] = clock[i];
	
	search(now+1, sum, clock);
	for(int i = 0;i<3;i++) {
		for(int j = 0;j<dc[now][0];j++)
			nClock[dc[now][j+1]] = (clock[dc[now][j+1]] + i + 1) % 4;
		search(now+1, sum+i+1, nClock);
	}
}

int main() {
//	freopen("input.in", "r", stdin);
	
	int c;
	scanf("%d", &c);
	
	while(c--) {
		int clock[16];
		for(int i = 0;i<16;i++) {
			scanf("%d", clock+i);
			clock[i] = clock[i]/3 - 1;
		}

		minV = 31;
		search(0, 0, clock);
		
		printf("%d\n", minV == 31 ? -1 : minV);
	}
}