#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

int n, d[51][51][4][2], ar[50];

int solve(int fr, int to, int type, int turn) {
/*    printf("%d (%d %d) ", type, fr, to);
    for(int i = fr;i<to;i++)
        printf("%d ", ar[i]);
    printf("%d\n", turn);
*/
    if(d[fr][to][type][turn] != 0x0f0f0f0f)
        return d[fr][to][type][turn];
    
    if(to - fr <= 0)
        return d[fr][to][type][turn] = 0;
    else if(to - fr == 1)
        return d[fr][to][type][turn] = ar[fr];
    
    int rtn;

    rtn = ar[fr] - solve(fr + 1, to, 0, !turn);
    rtn = max(rtn, ar[to-1] - solve(fr, to - 1, 1, !turn));
    if(to - fr > 2) {
        rtn = max(rtn, - solve(fr, to - 2, 2, !turn));
        rtn = max(rtn, - solve(fr + 2, to, 3, !turn));
    }
    
    return d[fr][to][type][turn] = rtn;
}

int d2[51][51];
int solve2(int fr, int to) {
//    printf("%d %d %d\n", fr, to, n);
    if(d2[fr][to] != 0x0f0f0f0f)
        return d2[fr][to];
    
    if(to - fr <= 0)
        return d2[fr][to] = 0;
    else if(to - fr == 1)
        return d2[fr][to] = ar[fr];
    
    int rtn;
    
    rtn = ar[fr] - solve2(fr + 1, to);
    rtn = max(rtn, ar[to-1] - solve2(fr, to - 1));
    if(to - fr > 2) {
        rtn = max(rtn, - solve2(fr, to - 2));
        rtn = max(rtn, - solve2(fr + 2, to));
    }
    
    return d2[fr][to] = rtn;
}

int game(int l, int r)
{
    if (l > r)
		return 0;
    
    if(d2[l][r] != 0x0f0f0f0f)
        return d2[l][r];
	int ret = ar[l]-game(l+1, r);
	ret = max(ret, ar[r]-game(l, r-1));
	if (r-l > 1)
	{
		ret = max(ret, -game(l+2, r));
		ret = max(ret, -game(l, r-2));
	}
	
	return d2[l][r] = ret;
}
int main() {
//    freopen("input.in", "r", stdin);
    
    int caseNum;
    scanf("%d", &caseNum);
    
    while(caseNum--) {
        scanf("%d", &n);
        
        for(int i = 0;i<n;i++)
            scanf("%d", ar+i);
        
        //memset(d, 0x0f, sizeof(d));
        //printf("%d\n", solve(0, n, 0, 0));
        //memset(d2, 0x0f, sizeof(d2));
        //printf("%d\n", solve2(0, n));
        memset(d2, 0x0f, sizeof(d2));
        printf("%d\n", game(0, n-1));
    }
}