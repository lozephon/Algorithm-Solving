#include <stdio.h>
#include <vector>

using namespace std;

int e[100][100] = {0,};
bool isDeleted[100] = {0,};

int main(){
	int n, m, x, y;
	int out = 0;
	vector< pair <int, int> > list;

//	freopen("input.in", "r", stdin);
	
	scanf("%d %d",&n,&m);

	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		x--;
		y--;
		e[x][y] = e[y][x] = 1;
		list.push_back(make_pair(x,y));
	}

	while(1){
		int count[100] = {0,};
		bool groupdeleted = false;

		for(int i=0;i<(int)list.size();i++){
			if(!isDeleted[list[i].first] && !isDeleted[list[i].second]){
				count[list[i].first]++;
				count[list[i].second]++;
			}
		}

		for(int i=0;i<n;i++){
			if(count[i] == 1){
				isDeleted[i] = true;
				groupdeleted = true;
			}
		}

		if(!groupdeleted)	break;

		out++;
	}

	printf("%d\n",out);
}
