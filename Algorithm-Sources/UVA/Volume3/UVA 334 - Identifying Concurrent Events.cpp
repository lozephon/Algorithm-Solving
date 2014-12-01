#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<iostream>
#include<set>
using namespace std;

map<string, int> ctoi;
map<int, string> itoc;
set<pair<int, int> > edge;

int main() {
	freopen("input.in", "r", stdin);
	
	int nC, nM, n, caseNum = 1;
	while(scanf("%d", &nC) == 1 && nC != 0) {
		ctoi.clear();
		itoc.clear();
		edge.clear();
		n = 0;

		string line; getline(cin, line);
		for(int i = 0;i<nC;i++) {
			getline(cin, line);
			istringstream sin(line);
			int len;
			string node, bfNode;
			sin >> len >> bfNode;
			if(ctoi.find(bfNode) == ctoi.end()) {
				ctoi[bfNode] = n;
				itoc[n++] = bfNode;
			}
			
			while(sin >> node) {
				if(ctoi.find(node) == ctoi.end()) {
					ctoi[node] = n;
					itoc[n++] = node;
				}
				edge.insert(make_pair(ctoi[bfNode], ctoi[node]));
				bfNode = node;
			}
		}
		scanf("%d", &nM);
		for(int i = 0; i<nM;i++) {
			string fr, to;
			cin >> fr >> to;
			edge.insert(make_pair(ctoi[fr], ctoi[to]));
		}
		
		vector<vector<int> > d(n);
		for(int i = 0;i<n;i++) {
			d[i].resize(n, 9999999);
			d[i][i] = 0;
		}
		
		for(set<pair<int, int> >::iterator i = edge.begin(); i != edge.end(); i++)
			d[i->first][i->second] = 1;

		for(int k = 0;k<n;k++) {
			for(int i = 0;i<n;i++) {
				for(int j = 0;j<n;j++) {
					if(d[i][j] > d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
		
		int nAns = 0;
		pair<int, int> ans[2];
		for(int i = 0;i<n;i++) {
			for(int j = i+1;j<n;j++) {
				if(d[i][j] == 9999999 && d[j][i] == 9999999) {
					if(nAns < 2)
						ans[nAns] = make_pair(i, j);
					nAns++;					
				}
			}
		}
		
		if(nAns) {
			printf("Case %d, %d concurrent events:\n", caseNum++, nAns);
			if(nAns == 1)
				printf("(%s,%s) \n", itoc[ans[0].first].c_str(), itoc[ans[0].second].c_str());
			else
				printf("(%s,%s) (%s,%s) \n", itoc[ans[0].first].c_str(), itoc[ans[0].second].c_str(), itoc[ans[1].first].c_str(), itoc[ans[1].second].c_str());
		}
		else
			printf("Case %d, no concurrent events.\n", caseNum++);
	}
}