#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

int main() {
//	freopen("input.in", "r", stdin);
	
	int t;
	scanf("%d", &t);
	while(t--) {
		int k;
		char str[10000];
		scanf("%d %s", &k, str);
		
		char ans[10000];
		strncpy(ans, str, k); ans[k] = 0;
		
		int len = strlen(str);
		
		char temp[10000]; temp[k] = 0;
		char temp2[10000]; temp2[k] = 0;

		for(int i = 0;i<=len-k;i++) {
			for(int j = 0;j<k;j++) {
				for(int l = 0;l<k;l++) {
					temp[l] = str[(j+l)%k + i];
					temp2[k-l-1] = str[(j+l)%k + i];
				}

//				printf("temp - %s, %s\n", temp, temp2);
				if(strcmp(ans, temp) > 0)
					strcpy(ans, temp);
				if(strcmp(ans, temp2) > 0)
					strcpy(ans, temp2);
			}
		}
		
		printf("%s\n", ans);
	}
}