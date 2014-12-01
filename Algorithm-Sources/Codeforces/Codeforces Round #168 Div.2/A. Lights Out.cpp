#include<stdio.h>

int main() {
//	freopen("input.in", "r", stdin);
	bool board[3][3];
	for(int i = 0;i<3;i++)
		for(int j =0 ;j<3;j++)
			board[i][j] = true;
	
	//int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
	//int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
	int dx[5] = {-1, 0, 1, 0, 0};
	int dy[5] = {0, 1, 0, -1, 0};
	
	for(int i = 0;i<3;i++) {
		for(int j =0;j<3;j++) {
			int n;
			scanf("%d", &n);
			if(n % 2 == 0)
				continue;
			for(int k = 0;k<5;k++) {
				int x = i+dx[k], y = j+dy[k];
				if(x >= 0 && x < 3 && y >= 0 && y < 3)
					board[x][y] = !board[x][y];
			}
		}
	}
	
	for(int i = 0;i<3;i++) {
		for(int j = 0;j<3;j++)
			printf("%d", board[i][j] ? 1 : 0);
		printf("\n");
	}
}