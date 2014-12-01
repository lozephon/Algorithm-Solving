#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<memory.h>
#include<list>
#include<vector>
using namespace std;

int n, subLen[50];
char str[120];
char sub[50][120];
int p[120][120], d[120][120];
vector<int> path;

int solve(int fr, int to) {
	d[fr][to] = 0;
	
	for(int i = fr;i<to;i++) {
		int newD = (d[fr][i] != -1 ? d[fr][i] : solve(fr, i)) && (d[i+1][to] != -1 ? d[i+1][to] : solve(i+1, to)); 
		if(newD) {
			d[fr][to] = newD;
			p[fr][to] = i;
			return d[fr][to];
		}
	}
	
	for(int i = 0;i<n;i++) {
		if(to-fr+1 == subLen[i] && !strncmp(str+fr, sub[i], subLen[i])) {
			d[fr][to] = 1;
			break;
		}
	}
	
	return d[fr][to];
}

void makePath(int fr, int to) {
	if(p[fr][to] == -1)
		return;
	
	makePath(fr, p[fr][to]);
	path.push_back(p[fr][to]);
	makePath(p[fr][to]+1, to);
}

string DP(int len) {
	memset(d, -1, sizeof(d));
	memset(p, -1, sizeof(p));
	path.clear();
	
	string ans = "";
	if(solve(0, len-1)) {
		makePath(0, len-1);
		
		int idx = 0;
		for(int i = 0;i<len;i++) {
			ans += str[i];
			if(idx < path.size() && path[idx] == i) {
				ans += " ";
				idx++;
			}
		}
	}
	
	return ans;
}
int main() {
	freopen("input.in", "r", stdin);
	
	int t;
	scanf("%d", &t);
	
	while(t--) {
		scanf("%s %d", str, &n);

		for(int i = 0;i<n;i++) {
			scanf("%s", sub[i]);
			subLen[i] = (int)strlen(sub[i]);
		}
		
		int baseLen = (int)strlen(str);
		
		for(int i = 0;i<baseLen-1;i++)
			str[baseLen+i] = str[baseLen-i-2];
		
		string ansA = DP(baseLen*2-1);
		
		for(int i = 0;i<baseLen;i++)
			str[baseLen+i] = str[baseLen-i-1];

		string ansB = DP(baseLen*2);
		
		if(!ansA.length() && !ansB.length())
			printf("IMPOSSIBLE\n");
		else if(!ansA.length())
			printf("%s\n", ansB.c_str());
		else if(!ansB.length())
			printf("%s\n", ansA.c_str());
		else 
			printf("%s\n", ansA < ansB ? ansA.c_str() : ansB.c_str());
	}
}