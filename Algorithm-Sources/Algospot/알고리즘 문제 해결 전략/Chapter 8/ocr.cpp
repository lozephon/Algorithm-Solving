#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main() {
//	freopen("input.in", "r", stdin);
	
	char words[500][11];
	map<string, int> wtoi;
	map<int, string> itow;
	
	int m, q;
	scanf("%d%d", &m, &q);
	
	for(int i = 0;i<m;i++) {
		scanf("%s", words[i]);
		string word(words[i]);
		wtoi[word] = i;
		itow[i] = word;
	}
	
	double B[500];
	for(int i = 0;i<m;i++)
		scanf("%lf", &B[i]);
	
	double T[500][500];
	for(int i = 0;i<m;i++) {
		for(int j = 0;j<m;j++)
			scanf("%lf", &T[i][j]);
	}
	
	double M[500][500];
	for(int i = 0;i<m;i++) {
		for(int j =0;j<m;j++)
			scanf("%lf", &M[i][j]);
	}
	
	while(q--) {
		double d[100][500] = {0, };
		int p[100][500] = {0, };
		
		int n;
		scanf("%d", &n);
		int sent[100];
		for(int i = 0;i<n;i++) {
			char word[11];
			scanf("%s", word);
			sent[i] = wtoi[string(word)];
		}
		
		for(int i = 0;i<m;i++)
			d[0][i] = B[i]*M[i][sent[0]];
		
		for(int i = 1;i<n;i++) {
			for(int j = 0;j<m;j++) {
				double maxV = d[i-1][0]*T[0][j]*M[j][sent[i]];
				int maxIdx = 0;
				for(int k = 1;k<m;k++) {
					if(maxV < d[i-1][k]*T[k][j]*M[j][sent[i]]) {
						maxV = d[i-1][k]*T[k][j]*M[j][sent[i]];
						maxIdx = k;
					}
				}
				d[i][j] = maxV;
				p[i][j] = maxIdx;
			}
		}
		
		int now = (int)(max_element(d[n-1], d[n-1]+m)-d[n-1]);
		int ansSent[100];
		for(int i = n-1;i>=0;i--) {
			ansSent[i] = now;
			now = p[i][now];
		}

		bool isFirst = true;
		for(int i = 0;i<n;i++) {
			if(!isFirst)
				printf(" ");
			isFirst = false;
			printf("%s", itow[ansSent[i]].c_str());
		}
		printf("\n");
	}
}