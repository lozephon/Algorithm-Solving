// 12/31
// Pattern String Matching 문제

#include<iostream>
#include<string>
#include<map>
#include<fstream>
using namespace std;

int main() {
//	ifstream cin("input.in");
	
	string s;
	cin >> s;
	
	int state[11] = {0, };
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	map<pair<int, pair<int, int> >, int> dates;
	
	for(int i = 0;i<s.length();i++) {
		if(s[i] != '-')
			state[0] = 1;
		
		int tempState[11];
		for(int j = 0;j<10;j++)
			tempState[j] = state[j];
		
//		for(int j = 0;j<10;j++)
//			printf("%d ", state[j]);
//		printf("\n");
		
		for(int j = 9;j>=0;j--) {
			if(tempState[j] == 0)
				continue;
//			printf("i : %d(%c), j : %d, state[%d] : %d -> ", i, s[i], j, j, state[j]);
			state[j] = 0;			
			switch(j) {
				case 0:
					if(s[i] == '-')
						state[j] = 0;
					else
						state[j+1] = 1;
					break;
				case 1:
					if(s[i] == '-')
						state[j] = 0;
					else
						state[j+1] = 1;
					break;
				case 2:
					if(s[i] == '-')
						state[j+1] = 1;
					else
						state[j] = 1;
					break;
				case 3:
					if(s[i] == '-')
						state[j] = 0;
					else
						state[j+1] = 1;
					break;
				case 4:
					if(s[i] == '-')
						state[j] = 0;
					else
						state[j+1] = 1;
					break;
				case 5:
					if(s[i] == '-')
						state[j+1] = 1;
					else
						state[2] = 1;
					break;
				case 6:
					if(s[i] == '-')
						state[j] = 0;
					else
						state[j+1] = 1;
					break;
				case 7:
					if(s[i] == '-')
						state[j] = 0;
					else
						state[j+1] = 1;
					break;
				case 8:
					if(s[i] == '-')
						state[6] = 1;
					else
						state[j+1] = 1;
					break;
				case 9:
					if(s[i] == '-')
						state[2] = 1;
					else {
						int dd = (s[i-9]-'0')*10 + (s[i-8]-'0');
						int mm = (s[i-6]-'0')*10 + (s[i-5]-'0');
						int yyyy = (s[i-3]-'0')*1000 + (s[i-2]-'0')*100 + (s[i-1]-'0')*10 + (s[i]-'0');
						if(mm > 0 && mm < 13 && dd > 0 && dd <= days[mm] && yyyy >= 2013 && yyyy <= 2015) {
							if(dates.find(make_pair(yyyy, make_pair(mm, dd))) == dates.end())
								dates[make_pair(yyyy, make_pair(mm, dd))] = 1;
							else
								dates[make_pair(yyyy, make_pair(mm, dd))]++;
//							printf("\nend : %02d-%02d-%d\n", dd,mm,yyyy);
						}
					}
					break;
			}
//			printf("i : %d(%c), j : %d, state[%d] : %d\n", i, s[i], j, j, state[j]);
//			
//			for(int j = 0;j<10;j++)
//				printf("%d ", state[j]);
//			printf("\n");
		}
//		printf("\n");
	}

	map<pair<int, pair<int, int> >, int>::iterator ii = dates.begin(), ans = dates.begin();
	ii++;
//	printf("%d\n", ans->second);
	while(ii != dates.end()) {
//		printf("%d\n", ii->second);
		if(ii->second > ans->second)
			ans = ii;
		ii++;
	}
	
	printf("%02d-%02d-%d", ans->first.second.second, ans->first.second.first, ans->first.first);
}