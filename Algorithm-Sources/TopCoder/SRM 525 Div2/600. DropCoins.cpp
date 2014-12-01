#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class DropCoins {
public:
	int getMinimum(vector<string> board, int K) {
		int row = board.size(), col = board[0].length();
		int map[30][30] = {0, };
		map[0][0] = board[0][0] == '.' ? 0 : 1;

		int arRow[30] = {0, }, arCol[30] = {0, };
		vector<int> coinRow, coinCol;

		for(int i = 1;i<col;i++) 
			map[0][i] = map[0][i-1] + (board[0][i] == '.' ? 0 : 1);
		for(int i = 1;i<row;i++)
			map[i][0] = map[i-1][0] + (board[i][0] == '.' ? 0 : 1);

		for(int i = 1;i<row;i++) {
			for(int j = 1;j<col;j++) {
				map[i][j] = map[i][j-1] + map[i-1][j] - map[i-1][j-1] + (board[i][j] == '.' ? 0 : 1);
			}
		}

		for(int i = 0;i<row;i++)
			for(int j = 0;j<col;j++)
				if(board[i][j] != '.')
					arRow[i] = arCol[j] = 1;

		for(int i = 0;i<row;i++)
			if(arRow[i])
				coinRow.push_back(i);
		for(int i = 0;i<col;i++)
			if(arCol[i])
				coinCol.push_back(i);

/*		for(int i = 0;i<row;i++) {
			for(int j = 0;j<col;j++)
				printf("%2d ", map[i][j]);
			printf("\n");
		}
		printf("\n");
*/
		int minNum = -1;

		for(int i = 0;i<row;i++) {
			for(int j = 0;j<col;j++) {
				for(int m = i;m<row;m++) {
					for(int n = j;n<col;n++) {
						int minus = 0;
						if(i-1 >= 0 && j-1 >=0)
							minus -= map[i-1][j-1];
						if(i-1 >= 0)
							minus += map[i-1][n];
						if(j-1 >= 0)
							minus += map[m][j-1];

						int num = map[m][n]-minus;
						if(num == K) {
							printf("(%d, %d), (%d, %d)\n", i, j, m, n);
							int rA = 0, rB = 0, cA = 0, cB = 0;
						
							int h;
							for(h = 0;coinRow[h] < i && h<row;h++) ;
							if(h-1 >= 0 && coinRow[h] < i)
								rA = coinRow[h];

							for(h = coinRow.size()-1;coinRow[h] > m && h>=0;h--) ;
							if(h+1 < coinRow.size() && coinRow[h] > m)
								rB = coinRow[h];

							for(h = 0;coinCol[h] < j && h<col;h++) ;
							if(h-1 >= 0 && coinCol[h] < j)
								cA = coinCol[h];

							for(h = coinCol.size()-1;coinCol[h] > n && h>=0;h--) ;
							if(h+1 < coinCol.size() && coinCol[h] > n)
								cB = coinCol[h];

							int newMin = rA + rB + min(rA, rB) + cA + cB + min(cA, cB);

							if(minNum == -1)
								minNum = newMin;
							else
								minNum = min(minNum, newMin);
						}
					}
				}
			}
		}

		return minNum;
	}
};

int main() {
	freopen("input.in", "r", stdin);

	int k;
	scanf("%d", &k);
	string s;
	vector<string> ss;
	while(cin >> s) {
		ss.push_back(s);
	}
	DropCoins d;
	printf("%d\n", d.getMinimum(ss, k));
}