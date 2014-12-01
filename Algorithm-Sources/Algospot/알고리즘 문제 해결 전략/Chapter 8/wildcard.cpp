#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int dynamic(int a, int b, char *w, char *s, int (*d)[200]) {
	if(d[a][b] != -1)
		return d[a][b];
	if(w[a] == 0)
		return d[a][b] = (s[b] == 0);
	if(w[a] == s[b] || w[a] == '?')
		return d[a][b] = dynamic(a+1, b+1, w, s, d);
	if(w[a] == '*' && ((s[b] != 0 && dynamic(a, b+1, w, s, d)) || dynamic(a+1, b, w, s, d)))
		return d[a][b] = 1;
	return d[a][b] = 0;
}

int main() {
//	freopen("input.in", "r", stdin);
	
	int c;
	scanf("%d", &c);
	while(c--) {
		int n;
		char cw[200];
		scanf("%s %d", cw, &n);
		cw[strlen(cw)] = 0;
		vector<string> ans;
		while(n--) {
			int d[200][200];
			char s[200];
			scanf("%s", s);
			s[strlen(s)] = 0;
			memset(d, -1, sizeof(d));
			
			if(dynamic(0, 0, cw, s, d))
				ans.push_back(string(s));
		}
		
		sort(ans.begin(), ans.end());
		for(int i = 0;i<ans.size();i++)
			printf("%s\n", ans[i].c_str());
	}
}