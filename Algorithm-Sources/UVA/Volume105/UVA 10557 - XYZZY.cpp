#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	freopen("input.in", "r", stdin);
	
	int n;
	while(scanf("%d", &n) == 1) {
		if(n == -1)
			break;
		int d[101];
		int energy[101];
		vector<pair<int, int> > e;
		
		for(int i = 1;i<=n;i++) {
			int nEdge, to;
			scanf("%d%d", &energy[i], &nEdge);
			for(int j = 0; j<nEdge;j++) {
				scanf("%d", &to);
				e.push_back(make_pair(i, to));
			}
			d[i] = -1;
		}
		
		d[1] = 100;
		for(int i = 0;i<n-1;i++) {
			for(int j = 0;j<e.size();j++) {
				if(d[e[j].first] == -1)
					continue;
				
				int newD = d[e[j].first] + energy[e[j].second];
				if(newD > 0 && (d[e[j].second] == -1 || d[e[j].second] < newD))
					d[e[j].second] = d[e[j].first] + energy[e[j].second];
			}
		}
		
		if(d[n] == -1) {
			int d2[101];
			for(int i = 1;i<=n;i++)
				d2[i] = d[i];
			
			int j = 0;
			for(;j<e.size();j++) {
				if(d[e[j].first] == -1)
					continue;
				
				int newD = d[e[j].first] + energy[e[j].second];
				if(newD > 0 && (d[e[j].second] == -1 || d[e[j].second] < newD))
					d[e[j].second] = d[e[j].first] + energy[e[j].second];
			}
			
			for(int i = 1;i<=n;i++)
				if(d[i] > d2[i])
					d[i] = 9999999;
			
			for(int i = 0;i<n-1;i++) {
				for(int j = 0;j<e.size();j++) {
					if(d[e[j].first] == -1)
						continue;
					
					int newD = d[e[j].first] + energy[e[j].second];
					if(newD > 0 && (d[e[j].second] == -1 || d[e[j].second] < newD))
						d[e[j].second] = d[e[j].first] + energy[e[j].second];
				}
			}
			
			if(d[n] > 0) 
				printf("winnable\n");
			else
				printf("hopeless\n");
		}
		else
			printf("winnable\n");
	}
}