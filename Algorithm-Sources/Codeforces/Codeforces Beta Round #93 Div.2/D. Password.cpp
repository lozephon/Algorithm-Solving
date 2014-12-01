#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string s;
int pi[1000001];

int main() {
//	freopen("input.in", "r", stdin);

	cin >> s;
	
	s = " " + s;
	pi[1] = 0;
	
	int k = 0, len = (int)s.length()-1;
	for(int i = 2;i<=len;i++) {
		while(k > 0 && s[k+1] != s[i]) 
			k = pi[k];
		
		if(s[k+1] == s[i])
			k++;
		
		pi[i] = k;
	}	
		
//	for(int i = 1;i<=len;i++)
//		printf("%d ", pi[i]);
//	printf("\n");
//	
//	printf("%d\n", pi[pi[len]]);

	if(pi[len] == 0)
		printf("Just a legend\n");
	else if(pi[len] < len) {
		int cnt = 0;
		for(int i = 0;i<len;i++) {
			if(pi[len] == pi[i])
				cnt++;
		}
		if(cnt > 0)
			printf("%s\n", s.substr(1, pi[len]).c_str());
		else if(pi[pi[len]] > 0)
			printf("%s\n", s.substr(1, pi[pi[len]]).c_str());
		else
			printf("Just a legend\n");
	}
	else {
		printf("%s\n", s.substr(1, pi[pi[len]]).c_str());
	}
}