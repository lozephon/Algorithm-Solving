#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;

int d[100][10];
int ar[100];
int n, s;

int solve(int now, int k) {
	if(k == 0) {
		int sum = 0, dsum = 0;
		for(int i = 0;i<=now;i++) {
			sum += ar[i];
			dsum += ar[i]*ar[i];
		}
		int avr = sum/(now+1);
		int v = min((now+1)*avr*avr - 2*avr*sum + dsum, (now+1)*(avr+1)*(avr+1) - 2*(avr+1)*sum + dsum);
		d[now][k] = v;
		return d[now][k];
	}
	
	int sum = ar[now], dsum = ar[now]*ar[now];
	
	d[now][k] = 0x7fffffff;
	for(int i = now-1;i>=0;i--) {
		int avr = sum/(now-i);
		int v = min((now-i)*avr*avr - 2*avr*sum + dsum, (now-i)*(avr+1)*(avr+1) - 2*(avr+1)*sum + dsum);
		
		d[now][k] = min(d[now][k], (d[i][k-1] == -1 ? solve(i, k-1) : d[i][k-1]) + v);
		sum += ar[i];
		dsum += ar[i]*ar[i];
	}
	int avr = sum/(now+1);
	int v = min((now+1)*avr*avr - 2*avr*sum + dsum, (now+1)*(avr+1)*(avr+1) - 2*(avr+1)*sum + dsum);
	d[now][k] = min(d[now][k], v);
	
	return d[now][k];
}

int main() {
//	freopen("input.in", "r", stdin);
	
	int c;
	scanf("%d", &c);
	while(c--) {
		scanf("%d%d", &n, &s);
		
		for(int i = 0;i<n;i++)
			scanf("%d", ar+i);
		sort(ar, ar+n);
	//	for(int i = 0;i<n;i++)
	//		printf("%d ", ar[i]);
	//	printf("\n");
		
		memset(d, -1, sizeof(d));
		for(int i = 0;i<s;i++)
			d[0][i] = 0;
		
		printf("%d\n", solve(n-1, s-1));
	}
}
