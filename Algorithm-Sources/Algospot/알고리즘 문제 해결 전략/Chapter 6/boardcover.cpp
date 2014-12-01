#include<stdio.h>

int h, w;
char line[21][21];

int search(int x, int y) {
//	printf("%d, %d\n", x, y);
	int rtn = 0;
	int dx[4][3] = { {0, 0, 1}, {0, 1, 1}, {0, 0, 1}, {0, 1, 1} };
	int dy[4][3] = { {0, 1, 1}, {0, 0, 1}, {0, 1, 0}, {0, -1, 0}};
	
	for(int i = 0;i<4;i++) {
		int j = 0;
		for(;j<3;j++) {
			if(x+dx[i][j] >= 0 && x+dx[i][j] < h &&
			   y+dy[i][j] >= 0 && y+dy[i][j] < w && line[x+dx[i][j]][y+dy[i][j]] == '.')
				continue;
			else
				break;
		}
		
		if(j == 3) {
			for(int k = 0;k<3;k++) 
				line[x+dx[i][k]][y+dy[i][k]] = '#';
		//	for(int a = 0;a<h;a++)
		//		printf("%s\n", line[a]);
			int nB = 0;
			for(int n = y+1; n < w;n++) {
				if(line[x][n] == '.') {
					nB++;
					rtn += search(x, n);
					break;
				}
			}
			if(nB == 0) {
				for(int m = x+1; m < h; m++) {
					for(int n = 0; n < w; n++) {
						if(line[m][n] == '.') {
							nB++;
							rtn += search(m, n);
							m = h;
							break;
						}
					}
				}
			}
			for(int k = 0;k<3;k++)
				line[x+dx[i][k]][y+dy[i][k]] = '.';
			if(nB == 0) {
			//	printf("------------\n");
				return 1;
			}
		}
	}
	return rtn;
}

int main() {
//	freopen("input.in", "r", stdin);
	
	int c;
	scanf("%d", &c);
	
	while(c--) {
		scanf("%d%d", &h, &w);
		for(int i = 0;i<h;i++)
			scanf("%s", line[i]);

		int ans = 0;
		for(int i = 0;i<h;i++) {
			for(int j = 0;j<w;j++) {
				if(line[i][j] == '.') {
					ans = search(i, j);
					i = h;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
}