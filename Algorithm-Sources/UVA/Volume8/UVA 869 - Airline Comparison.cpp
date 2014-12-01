#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#include<memory.h>
#include<set>
using namespace std;

map<char, int> ctoi;
set<pair<int, int> > eA, eB;

int main() {
	freopen("input.in", "r", stdin);
	
	int caseNum;
	scanf("%d", &caseNum);
	
	while(caseNum--) {
		ctoi.clear();
		eA.clear();
		eB.clear();
		
		int nA, nB, n = 0;

		scanf("%d", &nA);
		
		char line[100]; gets(line);
		for(int i = 0;i<nA;i++) {
			gets(line);
			char fr, to;
			sscanf(line, "%c %c", &fr, &to);
			
			if(ctoi.find(fr) == ctoi.end())
				ctoi[fr] = n++;
			if(ctoi.find(to) == ctoi.end())
				ctoi[to] = n++;			
			
			eA.insert(make_pair(ctoi[fr], ctoi[to]));
		}
		
		scanf("%d", &nB);
		
		gets(line);
		for(int i = 0;i<nB;i++) {
			gets(line);
			char fr, to;
			sscanf(line, "%c %c", &fr, &to);
			
			if(ctoi.find(fr) == ctoi.end())
				ctoi[fr] = n++;
			if(ctoi.find(to) == ctoi.end())
				ctoi[to] = n++;			
			
			eB.insert(make_pair(ctoi[fr], ctoi[to]));
		}
		
		vector<vector<int> > dA(n), dB(n);
		
		for(int i = 0;i<n;i++) {
			dA[i].resize(n, 99999);
			dB[i].resize(n, 99999);
			dA[i][i] = dB[i][i] = 0;
		}
		
		for(set<pair<int, int> >::iterator it = eA.begin(); it != eA.end();it++)
			dA[it->first][it->second] = 1;
		for(set<pair<int, int> >::iterator it = eB.begin(); it != eB.end();it++)
			dB[it->first][it->second] = 1;
		
		for(int k = 0;k<n;k++) {
			for(int i = 0;i<n;i++) {
				for(int j = 0;j<n;j++) {
					if(dA[i][j] > dA[i][k] + dA[k][j])
						dA[i][j] = dA[i][k] + dA[k][j];
				}
			}
		}
		
		for(int k = 0;k<n;k++) {
			for(int i = 0;i<n;i++) {
				for(int j = 0;j<n;j++) {
					if(dB[i][j] > dB[i][k] + dB[k][j])
						dB[i][j] = dB[i][k] + dB[k][j];
				}
			}
		}		
		
/*		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++)
				printf("%2d ", dA[i][j] == 99999 ? -1 : dA[i][j]);
			printf("\n");
		}
		printf("\n");
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++)
				printf("%2d ", dB[i][j] == 99999 ? -1 : dB[i][j]);
			printf("\n");
		}
		*/
		
		bool isSame = true;
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++)
				if((dA[i][j] != 99999 && dB[i][j] == 99999) || (dA[i][j] == 99999 && dB[i][j] != 99999)) {
					isSame = false;
					i = n;
					break;
				}
		}
		
		static bool firstLine = false;
		if(firstLine)
			printf("\n");
		firstLine = true;
		printf("%s\n", isSame ? "YES" : "NO");
	}
}