#include<stdio.h>
#include<algorithm>
using namespace std;

double e[20][20];
double d[20][20];
int p[20][20], n;

void printPath(int fr, int to) {
    int mid = p[fr][to];
    if(mid == -1)
        return;
        
    p[fr][to] = -1;
    printPath(fr, mid);
    printf(" %d", mid+1);
    printPath(mid, to);
}

int floyd() {
    for(int l = 0;l<2;l++) {
        for(int k = 0;k<n;k++) {
            for(int i = 0;i<n;i++) {
                for(int j = 0;j<n;j++) {
                    if(d[i][k]*d[k][j] > d[i][j]) {
//                        printf("update : %d -> %d(%.5lf) : %d -> %d -> %d(%.5lf)\n", i, j, d[i][j], i, k, j, d[i][k]*d[k][j]);                        
                        d[i][j] = d[i][k]*d[k][j];
                        p[i][j] = k;
                    }
                    if(i == j && d[i][j] > 1.01) {
                        printf("%d", i+1);
                        printPath(i, i);
                        printf(" %d\n", i+1);
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
//    freopen("input.in", "r", stdin);
    
    while(scanf("%d", &n) == 1) {
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(i == j)
                    e[i][j] = 1.0;
                else
                    scanf("%lf", &e[i][j]);
                d[i][j] = e[i][j];
                p[i][j] = -1;
            }
        }

        if(floyd())
            printf("no arbitrage sequence exists\n");
    }
}