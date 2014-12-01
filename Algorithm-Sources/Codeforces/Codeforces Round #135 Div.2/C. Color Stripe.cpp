#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
//	freopen("input.in", "r", stdin);
	
	int n, k;
	string s;
	cin >> n >> k >> s;
	
	int ans = 0;
	if(n > 1) {
		for(int i = 1;i<n-1;i++) {
			if(s[i] == s[i-1] || s[i] == s[i+1]) {
				if(k > 2) {
					for(int j = 0;j<k;j++)
						if('A'+j != s[i-1] && 'A'+j != s[i+1]) {
							s[i] = 'A'+j;
							ans++;
							break;
						}
				}
				else {
					if(s[i] == s[i-1]) {
						if(s[i] == 'A')
							s[i] = 'B';
						else
							s[i] = 'A';
						ans++;						
					}
				}
			}
		}
		if(s[n-1] == s[n-2]) {
			for(int j = 0;j<k;j++)
				if('A'+j != s[n-2]) {
					s[n-1] = 'A'+j;
					ans++;
					break;
				}	
		}
	}
	
	printf("%d\n%s\n", ans, s.c_str());
}