#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class NextOrPrev {
public:
	int getMinimum(int nextCost, int prevCost, string start, string goal) {
		vector<pair<int, int> > spans;
		for(int i = 0;i<start.length();i++) {
			spans.push_back(make_pair(start[i]-'a', goal[i]-'a'));
			//printf("%d %d\n", spans[i].first, spans[i].second);
		}
		bool isPossible = true;
		int cost = 0;
		for(int i = 0;i<spans.size();i++) {
			int range = spans[i].second - spans[i].first;
			if(range > 0)
				cost += range * nextCost;
			else
				cost -= range * prevCost;
			
			int f1 = spans[i].first, t1 = spans[i].second;
			
			for(int j = i;j<spans.size();j++) {
				int f2 = spans[j].first, t2 = spans[j].second;
				if((min(f1, t1) < min(f2, t2) && max(f1, t1) > max(f2, t2)) ||
				   (min(f2, t2) < min(f1, t1) && max(f2, t2) > max(f1, t1))) {
					isPossible = false;
				}
				else if((t1-f1)*(t2-f2)<0) {
					if(f1 < t1 && ((f1 < t2 && t1 > t2) || (f1 < f2 && t1 >= f2))) {
						isPossible = false;
					}
					else if(t1 < f1 && ((f1 < t2 && t1 > t2) || (f1 <= f2 && t1 > f2))) {
						isPossible = false;
					}
				}
			}
		}
		
		if(isPossible)
			return cost;
		
		return -1;
	}
};

int main() {
	freopen("input.in", "r", stdin);
	NextOrPrev n;
	printf("%d\n", n.getMinimum(563, 440, "fi", "ic"));
}