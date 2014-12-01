#include<stdio.h>
#include<set>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		set<int> p[11];
		int a, b;
		scanf("%d%d", &a, &b);

		int ans = 1;
		for(int i = 2;i<=a;i++) {
			int now = i, mul = 1;
			if(now == 4) {
				now = 2;
				mul = 2;
			}
			else if(now == 8) {
				now = 2;
				mul = 3;
			}
			else if(now == 9) {
				now = 3;
				mul = 2;
			}

			for(int j = 1;j<=b;j++) 
				p[now].insert(j*mul);
		}

		for(int i = 2;i<=a;i++) 
			ans += p[i].size();

		printf("%d\n", ans);
	}
}