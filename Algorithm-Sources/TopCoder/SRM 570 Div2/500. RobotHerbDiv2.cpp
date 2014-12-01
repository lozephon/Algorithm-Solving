#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class RobotHerbDiv2 {
public:
	int getdist(int T, vector <int> a) {
		int x = 0, y = 0, dir = 1;
		int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
		
		for(int t = 0;t<T;t++) {
			for(int i = 0;i<a.size();i++) {
				x += dx[dir]*a[i];
				y += dy[dir]*a[i];
				dir = (dir+a[i]) % 4;
				//printf("%d %d %d\n", x, y, dir);
			}
		}
		int dist = abs(x) + abs(y);
		return dist;
	}
};

int main() {
	RobotHerbDiv2 r;
	printf("%d\n", r.getdist(1, {1,2,3}));
}