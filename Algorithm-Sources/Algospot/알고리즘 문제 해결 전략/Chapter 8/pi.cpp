#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

void getDiff(char *s, int l, int *rtn) {
	int off = l-3;
	if(s[off] == s[off+1] && s[off] == s[off+2])
		rtn[0] = 1;
	else if(s[off] - s[off+1] == s[off+1] - s[off+2])
		if(abs(s[off] - s[off+1]) == 1)
			rtn[0] = 2;
		else
			rtn[0] = 5;
	else if(s[off] == s[off+2])
		rtn[0] = 4;
	else
		rtn[0] = 10;
	if(l > 3) {
		if(rtn[0] == 1 && s[off-1] == s[off])	rtn[1] = 1;
		else if((rtn[0] == 2 || rtn[0] == 5) && s[off-1] - s[off] == s[off] - s[off+1]) rtn[1] = rtn[0];
		else if(rtn[0] == 4 && s[off-1] == s[off+1]) rtn[1] = 4;
		else rtn[1] = 10;
	}
	if(l == 5) {
		off--;
		if(rtn[1] == 1 && s[off-1] == s[off])	rtn[2] = 1;
		else if((rtn[1] == 2 || rtn[1] == 5) && s[off-1] - s[off] == s[off] - s[off+1]) rtn[2] = rtn[1];
		else if(rtn[1] == 4 && s[off-1] == s[off+1]) rtn[2] = 4;
		else rtn[2] = 10;
	}
}

int main() {
//	freopen("input.in", "r", stdin);
	int caseNum;
	scanf("%d", &caseNum);
	
	char s[10001];
	while(caseNum--) {
		scanf("%s", s);
		int d[10001];
		memset(d, 0x0f, sizeof(d));
		
		int len = (int)strlen(s);
		int rtn[3];
		d[0] = 0;
		getDiff(s, 3, rtn);
		d[3] = rtn[0];
		getDiff(s, 4, rtn);
		d[4] = rtn[1];
		for(int i = 5;i<=len;i++) {
			getDiff(s+i-5, 5, rtn);
			d[i] = min(d[i], d[i-5] + rtn[2]);
			d[i] = min(d[i], d[i-4] + rtn[1]);
			d[i] = min(d[i], d[i-3] + rtn[0]);
		}
		printf("%d\n", d[len]);
	}
}
