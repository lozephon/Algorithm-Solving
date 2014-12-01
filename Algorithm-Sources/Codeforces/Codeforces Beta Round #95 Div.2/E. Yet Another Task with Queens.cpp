#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<int, vector<pair<int, int> > > xlay, ylay, dlay, mlay;
vector<pair<int, int> > ps;

int main() {
//	freopen("input.in", "r", stdin);

	int n, m;
	scanf("%d%d", &n, &m);

	ps.resize(m);
	for(int i = 0;i<m;i++) {
		scanf("%d%d", &ps[i].first, &ps[i].second);
		xlay[ps[i].first].push_back(ps[i]);
		ylay[ps[i].second].push_back(ps[i]);
		dlay[ps[i].second-ps[i].first].push_back(ps[i]);
		mlay[ps[i].first+ps[i].second].push_back(ps[i]);
	}

	for(map<int, vector<pair<int, int> > >::iterator it = xlay.begin(); it != xlay.end();it++)
		sort(it->second.begin(), it->second.end());
	for(map<int, vector<pair<int, int> > >::iterator it = ylay.begin(); it != ylay.end();it++)
		sort(it->second.begin(), it->second.end());
	for(map<int, vector<pair<int, int> > >::iterator it = dlay.begin(); it != dlay.end();it++)
		sort(it->second.begin(), it->second.end());
	for(map<int, vector<pair<int, int> > >::iterator it = mlay.begin(); it != mlay.end();it++)
		sort(it->second.begin(), it->second.end());

	int ts[9] = {0, };
	for(int i = 0;i<m;i++) {
		int t = 0;
		if(xlay[ps[i].first].size() > 1) {
			int idx = lower_bound(xlay[ps[i].first].begin(), xlay[ps[i].first].end(), ps[i]) - xlay[ps[i].first].begin();
			t += 2;
			if(idx == 0 || idx == xlay[ps[i].first].size() - 1)
				t--;
		}
		if(ylay[ps[i].second].size() > 1) {
			int idx = lower_bound(ylay[ps[i].second].begin(), ylay[ps[i].second].end(), ps[i]) -ylay[ps[i].second].begin();
			t += 2;
			if(idx == 0 || idx == ylay[ps[i].second].size() - 1)
				t--;
		}
		if(dlay[ps[i].second - ps[i].first].size() > 1) {
			int idx = lower_bound(dlay[ps[i].second - ps[i].first].begin(), dlay[ps[i].second - ps[i].first].end(), ps[i]) - dlay[ps[i].second - ps[i].first].begin();
			t += 2;
			if(idx == 0 || idx == dlay[ps[i].second - ps[i].first].size() - 1)
				t--;
		}
		if(mlay[ps[i].first + ps[i].second].size() > 1) {
			int idx = lower_bound(mlay[ps[i].first + ps[i].second].begin(), mlay[ps[i].first + ps[i].second].end(), ps[i]) - mlay[ps[i].first + ps[i].second].begin();
			t += 2;
			if(idx == 0 || idx == mlay[ps[i].first + ps[i].second].size() - 1)
				t--;
		}
		ts[t]++;
	}

	printf("%d", ts[0]);
	for(int i = 1;i<9;i++)
		printf(" %d", ts[i]);
	printf("\n");
}