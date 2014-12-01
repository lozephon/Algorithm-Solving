#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int f[20000];
int g[20000][4];
pair<int, int> f2[20000];

int solve(int fr, int to) {
	int rtn = 0;
	if(to - fr == 0) return 0;
	else if(to - fr == 1) return f[fr];
	rtn = max(solve(fr, (fr+to)/2), solve((fr+to)/2, to));
	
	int st = (fr+to)/2-1, ed = st+1, nowMin = min(f[st], f[ed]);
	rtn = max(nowMin*2, rtn);
	while(st > fr || ed < to-1) {
		int left = -1, right = -1;
		if(st > fr)
			left = f[st-1];
		if(ed < to-1)
			right = f[ed+1];
		if(left > right)
			st--;
		else
			ed++;
		nowMin = min(nowMin, max(left, right));
		rtn = max(nowMin * (ed-st+1), rtn);
	}

	return rtn;
}

int gNum(int num) {
	vector<int> st;
	while(g[num][0] != num) {
		st.push_back(num);
		num = g[num][0];
	}
	for(int i = 0;i<st.size();i++)
		g[st[i]][0] = num;
	return num;
}

int main() {
	freopen("input.in", "r", stdin);
	int c;
	scanf("%d", &c);
	
	while(c--) {
		scanf("%d", &n);
		for(int i = 0;i<n;i++) {
			scanf("%d", f+i);
			g[i][0] = i;
			g[i][1] = f[i];
			g[i][2] = 1;
			g[i][3] = 0;
			f2[i].first = -f[i];
			f2[i].second = i;
		}
		
		//printf("%d\n", solve(0, n));
		
		int rtn = 0;
		sort(f2, f2+n);
		for(int i = 0;i<n;i++)
			f2[i].first = -f2[i].first;
		for(int i = 0;i<n;i++)
			printf("(%d %d) ", f2[i].first, f2[i].second);
		printf("\n");
		for(int i = 0;i<n;i++) {
			rtn = max(rtn, f2[i].first);
			int mid = f2[i].second, left = f2[i].second - 1, right = f2[i].second + 1;
			
			g[mid][3] = 1;
			
			if(left >= 0 && g[gNum(left)][3] == 1 && (g[gNum(right)][3] == 0 || f[left] > f[right])) {
				if(gNum(mid) < gNum(left)) {
					g[gNum(mid)][1] = min(g[gNum(left)][1], g[gNum(mid)][1]);
					g[gNum(mid)][2] += g[gNum(left)][2];
					g[gNum(left)][0] = gNum(mid);
					rtn = max(g[gNum(mid)][2] * g[gNum(mid)][1], rtn);
				}
				else if(gNum(mid) > gNum(left)) {
					g[gNum(left)][1] = min(g[gNum(left)][1], g[gNum(mid)][1]);
					g[gNum(left)][2] += g[gNum(mid)][2];
					g[gNum(mid)][0] = gNum(left);
					rtn = max(g[gNum(left)][2] * g[gNum(left)][1], rtn);
				}
			}
			else if(right < n && g[gNum(right)][3] == 1 && (g[gNum(left)][3] == 0 || f[right] > f[left])) {
				if(gNum(mid) < gNum(right)) {
					g[gNum(mid)][1] = min(g[gNum(right)][1], g[gNum(mid)][1]);
					g[gNum(mid)][2] += g[gNum(right)][2];
					g[gNum(right)][0] = gNum(mid);
					rtn = max(g[gNum(mid)][2] * g[gNum(mid)][1], rtn);
				}
				else if(gNum(mid) > gNum(right)) {
					g[gNum(right)][1] = min(g[gNum(right)][1], g[gNum(mid)][1]);
					g[gNum(right)][2] += g[gNum(mid)][2];
					g[gNum(mid)][0] = gNum(right);
					rtn = max(g[gNum(right)][2] * g[gNum(right)][1], rtn);
				}
			}
			for(int i = 0;i<n;i++)
				printf("%d ", g[i][0]);
			printf("\n");
		}
		printf("%d\n", rtn);
	}
}