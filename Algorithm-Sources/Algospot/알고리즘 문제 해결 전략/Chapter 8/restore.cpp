#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int k;
string s[16];
int d[1<<16][16];
string ds[1<<16][16];
int p[1<<16][16];
int sub[16][16];

pair<int, string> solve(int selected, int bf) {
	if(d[selected][bf] != -1)
		return make_pair(d[selected][bf], ds[selected][bf]);
	
	if(selected == ((1<<k) - 1)) {
		d[selected][bf] = (int)s[bf].length();
		ds[selected][bf] = s[bf];
		return make_pair((int)s[bf].length(), s[bf]);
	}
	
	pair<int, string> rtn = make_pair(0x7fffffff, "");
	for(int i = 1;i<=k;i++) {
		if(!(selected & (1<<(i-1)))) {
			pair<int, string> temp;
			if(bf != 0) {
				if(sub[i][bf] == 0)
					temp = solve(selected | (1<<(i-1)), bf);
				else {
					temp = solve(selected | (1<<(i-1)), i);
					temp.first += sub[bf][i];
					temp.second = s[bf].substr(0, sub[bf][i]) + temp.second;
				}
			}
			else
				temp = solve(selected | (1<<(i-1)), i);
			if(temp.first < rtn.first)
				rtn = temp;
		}
	}
	
	d[selected][bf] = rtn.first;
	ds[selected][bf] = rtn.second;
	return rtn;
}

string reconstruct(int selected, int bf) {
	if(selected == ((1<<k) - 1))
		return s[bf];
	
	for(int i = 1;i<=k;i++) {
		if(!(selected & (1<<(i-1)))) {
			//printf("%d, %d\n", d[selected][bf], sub[bf][i] + d[selected | (1 << (i-1))][i]);
			//if(d[selected][bf] == (int)s[bf].length() - sub[bf][i] + d[selected | (1 << (i-1))][i])
			if(d[selected][bf] == sub[bf][i] + d[selected | (1 << (i-1))][i])
				return s[bf].substr(0, sub[bf][i]) + reconstruct(selected | (1 << (i-1)), i);
		}
	}
	
	return "??";
}

int solve2(int selected, int bf) {
	if(d[selected][bf] != -1)
		return d[selected][bf];

	if(selected == ((1<<k) - 1))
		return d[selected][bf] = 0;
	
	int rtn = -1;
	for(int i = 1;i<=k;i++) {
		if(!(selected & (1<<(i-1))))
			rtn = max(rtn, (int)s[bf].length() - sub[bf][i] + solve2(selected | (1<<(i-1)), i));
	}
	
	return d[selected][bf] = rtn;
}

int main() {
//	freopen("input.in", "r", stdin);
	
	int c;
	scanf("%d", &c);

	while(c--) {
		scanf("%d", &k);
		
		s[0] = "";
		for(int i = 1;i<=k;i++)
			cin >> s[i];
		
		memset(d, -1, sizeof(d));
		memset(sub, 0, sizeof(sub));
		
		int used = 0;
		for(int i = 1;i<=k;i++) {
			for(int j = 1;j<=k;j++) {
				if(i == j)
					continue;
				
				if(s[j].find(s[i]) != string::npos) {
					sub[i][j] = 0;
					used |= 1<<(i-1);
					continue;
				}
				
				sub[i][j] = (int)s[i].length();
				for(int l = (int)s[i].length()-1;l>=0;l--) {
					if(s[i].length()-l > s[j].length())
						break;
					int pa = l, pb = 0;
					while(pa < s[i].length() && s[i][pa] == s[j][pb]) {
						pa++; pb++;
					};
					if(pa == s[i].length())
						sub[i][j] = l;
				}
			}
		}

		pair<int, string> rtn = solve(used, 0);
		printf("%s\n", rtn.second.c_str());
		//solve2(used, 0);
		//printf("%d ", rtn.first);
		//printf("%s\n", reconstruct(used, 0).c_str());
	}
}