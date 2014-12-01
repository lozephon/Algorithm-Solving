#include<stdio.h>
#include<memory.h>
#include<map>
#include<algorithm>
#include<vector>
#include<sstream>
#include<string>
#include<string.h>
using namespace std;

map<char, int> stoi;
map<int, char> itos;
int n;

void floyd(int d[][30]) {
	for(int k = 0;k<n;k++) {
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++) {
				if(d[i][k] != -1 && d[k][j] != -1 && (d[i][j] == -1 || d[i][j] > d[i][k]+d[k][j])) 
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}

int main() {
	freopen("input.in", "r", stdin);
	
	int m;
	while(scanf("%d", &m) == 1 && m != 0) {
		char line[100];
		gets(line);
		
		stoi.clear();
		itos.clear();
		n = 0;
		
		int dY[30][30], dM[30][30];
		memset(dY, 0xff, sizeof(dY));
		memset(dM, 0xff, sizeof(dM));
		
		for(int i = 0;i<m;i++) {
			gets(line);
			char YM, UB, fr, to;
			int cost;
			sscanf(line, "%c %c %c %c %d", &YM, &UB, &fr, &to, &cost);
			
			if(stoi.find(fr) == stoi.end()) {
				itos[n] = fr;
				stoi[fr] = n++;
			}
			if(stoi.find(to) == stoi.end()) {
				itos[n] = to;
				stoi[to] = n++;
			}
			
			if(YM == 'Y') {
				dY[stoi[fr]][stoi[to]] = dY[stoi[fr]][stoi[to]] == -1 ? cost : min(dY[stoi[fr]][stoi[to]], cost);
				if(UB == 'B')
					dY[stoi[to]][stoi[fr]] = dY[stoi[to]][stoi[fr]] == -1 ? cost : min(dY[stoi[to]][stoi[fr]], cost);
			}
			else {
				dM[stoi[fr]][stoi[to]] = dM[stoi[fr]][stoi[to]] == -1 ? cost : min(dM[stoi[fr]][stoi[to]], cost);
				if(UB == 'B')
					dM[stoi[to]][stoi[fr]] = dM[stoi[to]][stoi[fr]] == -1 ? cost : min(dM[stoi[to]][stoi[fr]], cost);
			}
		}
	
		char stY, stM;
		scanf("%c %c", &stY, &stM);
		if(stoi.find(stY) == stoi.end()) {
			itos[n] = stY;
			stoi[stY] = n++;
		}
		if(stoi.find(stM) == stoi.end()) {
			itos[n] = stM;
			stoi[stM] = n++;
		}
		
		for(int i = 0;i<n;i++)
			dY[i][i] = dM[i][i] = 0;
		
		floyd(dY);
		floyd(dM);
		
		int ans = 0x7fffffff;
		for(int i = 0;i<n;i++) {
			if(dY[stoi[stY]][i] != -1 && dM[stoi[stM]][i] != -1)
				ans = min(ans, dY[stoi[stY]][i] + dM[stoi[stM]][i]);
		}
		
		if(ans == 0x7fffffff)
			printf("You will never meet.\n");
		else {
			vector<char> anss;
			for(int i = 0;i<n;i++) {
				if(dY[stoi[stY]][i] != -1 && dM[stoi[stM]][i] != -1)
					if(dY[stoi[stY]][i] + dM[stoi[stM]][i] == ans)
						anss.push_back(itos[i]);
			}
			sort(anss.begin(), anss.end());
			printf("%d %c", ans, anss[0]);
			for(int i = 1;i<anss.size();i++)
				printf(" %c", anss[i]);
			printf("\n");
		}
	}
}