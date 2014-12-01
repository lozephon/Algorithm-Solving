#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<memory.h>
#include<string>
#include<iostream>
using namespace std;

map<string, int> stoi;
struct edge {
	int fr, to, cost;
	edge(int _fr, int _to, int _cost) {
		fr = _fr;
		to = _to;
		cost = _cost;
	}
};
vector<edge> e;

int main() {
	freopen("input.in", "r", stdin);
	
	int c;
	scanf("%d", &c);
	while(c--) {
		stoi.clear();
		e.clear();

		int nCity, nFlight, n = 0;
		scanf("%d", &nCity);
		for(int i = 0;i<nCity;i++) {
			string s;
			cin >> s;
			stoi[s] = n++;
		}
		
		scanf("%d", &nFlight);
		for(int i = 0;i<nFlight;i++) {
			string fr, to;
			int cost;
			cin >> fr >> to >> cost;
			e.push_back(edge(stoi[fr], stoi[to], cost));
		}
		
		int d[101][101];
		memset(d, 0xff, sizeof(d));
		
		d[0][0] = 0;
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<e.size();j++) {
				for(int k = 0;k<n-1;k++) {
					if(d[e[j].fr][k] == -1)
						continue;
					
					if(d[e[j].to][k+1] == -1 || d[e[j].fr][k] + e[j].cost < d[e[j].to][k+1])
						d[e[j].to][k+1] = d[e[j].fr][k] + e[j].cost;
				}
			}
		}
		
		int stop[101] = {d[n-1][1], };
		for(int i = 1;i<n-1;i++) {
			if(stop[i-1] == -1)
				stop[i] = d[n-1][i+1];
			else if(d[n-1][i+1] == -1)
				stop[i] = stop[i-1];
			else
				stop[i] = min(stop[i-1], d[n-1][i+1]);
		}
		
		static int caseNum = 1;
		if(caseNum > 1)
			printf("\n");
		
		printf("Scenario #%d\n", caseNum++);
		int nQ;
		scanf("%d", &nQ);
		for(int i = 0;i<nQ;i++) {
			int q;
			scanf("%d", &q);
			if(q >= n-1)
				q = n-2;
			
			if(q < 0)
				printf("No satisfactory flights\n");
			else if(stop[q] == -1)
				printf("No satisfactory flights\n");
			else
				printf("Total cost of flight(s) is $%d\n", stop[q]);
		}
	}
}