#include<iostream>
#include<string>
#include<vector>
using namespace std;

class EasyHomework {
public:
	string determineSign(vector <int> A) {
		int result = 1;
		for(int i = 0;i<A.size();i++) {
			if(A[i] == 0)
				result = 0;
			else if(A[i] > 0)
				result *= 1;
			else
				result *= -1;
		}
		if(result > 0)
			return "POSITIVE";
		else if(result < 0)
			return "NEGATIVE";
		return "ZERO";
	}
};
