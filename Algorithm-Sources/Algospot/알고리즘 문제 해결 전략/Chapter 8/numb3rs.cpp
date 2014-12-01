#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

typedef vector<vector<double> > matrix;

void mulMatrix(matrix &a, matrix &b, matrix &c) {
	c.resize(a.size());
	for(int i = 0;i<c.size();i++)
		c[i].resize(b[0].size());
	
	for(int i = 0;i<a.size();i++) {
		for(int j = 0;j<b[0].size();j++) {
			c[i][j] = 0;
			for(int k = 0;k<b.size();k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
}

void printMatrix(matrix &a) {
	for(int i = 0;i<a.size();i++) {
		for(int j = 0;j<a[0].size();j++)
			printf("%lf ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main() {
	freopen("input.in", "r", stdin);
	
	int caseNum;
	scanf("%d", &caseNum);
	
	while(caseNum--) {
		int n, d, p;
		scanf("%d%d%d", &n, &d, &p);
		
		matrix a, b;
		int in[50] = {0, };
		a.resize(n);
		for(int i = 0;i<n;i++) {
			a[i].resize(n);
			for(int j = 0;j<n;j++) {
				int temp;
				scanf("%d", &temp);
				if(temp)
					in[i]++;
				a[i][j] = temp;
			}
		}
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++)
				a[j][i] /= in[i];
		}
		b.resize(n);
		for(int i = 0;i<n;i++) {
			b[i].resize(1);
			b[i][0] = 0.0;
		}
		b[p][0] = 1.0;
		matrix c;
		for(int i = 0;i<d;i++) {
			mulMatrix(a, b, c);
			b = c;
		}
		int nAns;
		scanf("%d", &nAns);
		for(int i = 0;i<nAns;i++) {
			if(i != 0)
				printf(" ");
			int num;
			scanf("%d", &num);
			printf("%.8lf", b[num][0]);
		}
		printf("\n");
	}
}

// Markov Chain