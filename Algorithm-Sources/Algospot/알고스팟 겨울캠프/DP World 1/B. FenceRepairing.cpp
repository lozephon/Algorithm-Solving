#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

double d[2501];
bool calculed[2501];
vector<int> fence;

/*
double solve(int now) {
    double rtn = sqrt(fence[now]-fence[0]+1.f);
    calculed[now] = true;
    
    for(int i = now;i>0;i--) {
        double rtn2 = sqrt(fence[now]-fence[i]+1.f) + (calculed[i-1] ? d[i-1] : solve(i-1));
        if(rtn > rtn2)
            rtn = rtn2;
    }
    
    return d[now] = rtn;
}
*/

int main() {
    freopen("input.in", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n;
        scanf("%d", &n);
        char line[100]; gets(line);
        int idx = 0;
        
        memset(calculed, 0, sizeof(calculed));
		
        fence.clear();
        for(int i = 0;i<n;i++) {
            gets(line);
            int len = (int)strlen(line);
            for(int j = 0;j<len;j++) {
                if(line[j] == 'X')           
                    fence.push_back(idx);
                idx++;
            }
        }
        
        for(int i = 0; i < fence.size(); ++i) {
            d[i] = sqrt(fence[i]-fence[0]+1);
            for(int j = 0; j < i; ++j)
                d[i] = min(d[i], d[j]+sqrt(fence[i]-fence[j+1]+1));
        }
        
        printf("%.3lf\n", fence.size() ? d[fence.size()-1] : 0);
    }
}