#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
//	freopen("input.in", "r", stdin);
	
	int n;
	int sector[1000] = {0, };
	bool isFirst[1000] = {0, };
	int ans = 0;
	
	scanf("%d", &n);
	vector<pair<int, int> > bridges;
	for(int i = 0;i<n;i++) {
		int k;
		scanf("%d", &k);
		for(int j = 0; j<k;j++) {
			int dist;
			scanf("%d", &dist);
			bridges.push_back(make_pair(dist, i));
		}
	}
	
	sort(bridges.begin(), bridges.end());
	
	for(int i = 0;i<bridges.size();i++) {
//		printf("%d %d - %d %d\n", bridges[i].first, bridges[i].second+1, sector[bridges[i].second], isFirst[bridges[i].second]);
//		if(sector[bridges[i].second] != 0 && isFirst[bridges[i].second])
//			printf("check\n");
		
		if(sector[bridges[i].second] != 0 && isFirst[bridges[i].second])
			ans++;
		
		isFirst[bridges[i].second] = true;
		
		sector[bridges[i].second] = 0;
		
		if(isFirst[(bridges[i].second + 1) % n])
			sector[(bridges[i].second + 1) % n]++;
		if(isFirst[(bridges[i].second - 1 + n) % n])
			sector[(bridges[i].second - 1 + n) % n]--;
	}
	
	printf("%d\n", ans);
}