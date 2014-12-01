// 12/31
// 바로 한자리수만 붙여서 나눠지면 그 뒤론 0만 붙여도 됨

#include<stdio.h>

int main() {
	int a, b, n;
	scanf("%d%d%d", &a, &b, &n);
	
	a *= 10;
	int i = 0;
	for(;i<10;i++) {
		if((a+i) % b == 0)
			break;
	}
	if(i == 10) {
		printf("-1\n");
		return 0;
	}
	a += i;

	printf("%d", a);
	for(int i = 1;i<n;i++)
		printf("0");
	printf("\n");
}