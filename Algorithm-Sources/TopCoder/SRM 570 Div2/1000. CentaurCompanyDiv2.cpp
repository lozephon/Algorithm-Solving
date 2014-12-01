#include<iostream>
#include<vector>
using namespace std;

class CentaurCompanyDiv2 {
public:
	long long dfs(int now, vector<int> *edge, bool *visited) {
		long long rtn = 0;
		vector<long long> each;
		for(int i = 0;i<edge[now].size();i++) {
			long long temp;
			if(!visited[edge[now][i]]) {
				visited[edge[now][i]] = true;
				temp = 1 + dfs(edge[now][i], edge, visited);
				visited[edge[now][i]] = false;
				if(rtn == 0)
					rtn = temp;
				else
					rtn += rtn*temp+temp;
			}
		}
		return rtn;
	}
	long long count(vector <int> a, vector <int> b) {
		int n = (int)a.size()+1;
		vector<int> edge[51];
		for(int i = 0;i<a.size();i++) {
			edge[a[i]-1].push_back(b[i]-1);
			edge[b[i]-1].push_back(a[i]-1);
		}
		long long rtn = 0;
		for(int i = 0;i<n;i++) {
			bool visited[51] = {0, };
			for(int j = 0;j<=i;j++)
				visited[j] = true;
			long long temp = 1+dfs(i, edge, visited);
			rtn += temp;
		}
		return rtn+1;
	}
};

int main() {
	CentaurCompanyDiv2 c;
	printf("%lld\n", c.count({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51}));

	//printf("%lld\n", c.count({1,2}, {2,3}));
	printf("%lld\n", c.count({10, 7, 2, 5, 6, 2, 4, 9, 7}, {8, 10, 10, 4, 1, 6, 2, 2, 3}));
}