#include <stdio.h>
#include<vector>
using namespace std;

vector<pair<int, int> > statue;
bool canGo[8][8][9];

int temp = 0;

bool dfs(int x, int y, int level) {
	temp++;
	int dx[] = {0, 0, 0, -1, -1, -1, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

	if(level == 8)
		return true;

	for(int i = 0;i<9;i++) {
		int nx = x+dx[i], ny = y+dy[i];
		if(nx < 0 || nx > 7 || ny < 0 || ny > 7)
			continue;

		if(!canGo[nx][ny][level] && !canGo[nx][ny][level+1]) {
			if(dfs(nx, ny, level+1))
				return true;
		}
	}

	return false;
}

int main(){
//	freopen("input.in", "r", stdin);

	char line[10];
	for(int i = 0;i<8;i++) {
		gets(line);
		for(int j = 0;j<8;j++) {
			if(line[j] == 'S') {
				statue.push_back(make_pair(i, j));
				canGo[i][j][0] = true;
			}
		}
	}

	for(int i = 1;i<=8;i++) {
		for(int j = 0;j<statue.size();j++) {
			if(statue[j].first+i < 8)
				canGo[statue[j].first+i][statue[j].second][i] = true;
		}
	}

	printf("%s\n", dfs(7, 0, 0) ? "WIN" : "LOSE");
}