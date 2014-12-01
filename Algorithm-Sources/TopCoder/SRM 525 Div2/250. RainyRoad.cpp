#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class RainyRoad {
public:
	string isReachable(vector <string> road) {
		int n = road[0].length();

		int i = 0;
		for(;i<n;i++) {
			if(road[0][i] == 'W' && road[1][i] == 'W')
				break;
		}
		if(i == n)
			return "YES";
		return "NO";
	}
};

int main() {
	RainyRoad r;
	vector<string> s;
	s.push_back(".W..");
	s.push_back("....");

	printf("%s\n", r.isReachable(s).c_str());
}