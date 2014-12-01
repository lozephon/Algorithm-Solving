#include<stdio.h>
#include<map>
using namespace std;

int main() {
//	freopen("input.in", "r", stdin);
	
	char s[1001];
	int k;
	map<char, int> m;
	
	scanf("%d%s", &k, s);
	
	for(int i = 0;s[i];i++) {
		if(m.find(s[i]) != m.end())
			m[s[i]]++;
		else
			m[s[i]] = 1;
	}
	map<char, int>::iterator it = m.begin();
	while(it != m.end() && it->second % k == 0) it++;

	if (it != m.end()) {
		printf("-1\n");
		return 0;
	}

	char ans[1001] = {0, };
	int now = 0;
	for(int i = 0;i<k;i++) {
		for(map<char, int>::iterator it = m.begin();it!=m.end();it++) {
			for(int j = 0;j<it->second/k;j++)
				ans[now++] = it->first;
		}
	}
	printf("%s\n", ans);
}