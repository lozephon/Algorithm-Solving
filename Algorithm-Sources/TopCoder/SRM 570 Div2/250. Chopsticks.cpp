#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Chopsticks {
public:
	int getmax(vector <int> length) {
		int len[101] = {0, };
		for(int i = 0;i<length.size();i++) {
			len[length[i]]++;
		}
		int rtn = 0;
		for(int i = 1;i<=100;i++)
			rtn += len[i]/2;
		
		return rtn;
	}
};

int main() {

}