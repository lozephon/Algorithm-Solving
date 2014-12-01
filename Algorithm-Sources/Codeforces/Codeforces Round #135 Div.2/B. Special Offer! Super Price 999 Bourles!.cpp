#include<stdio.h>
#include<string>
#include<iostream>
#include<math.h>
#include<cstdlib>
using namespace std;

int main() {
    //  freopen("input.in", "r", stdin);
    
    string a, b;
    
    cin >> a >> b;
    
    long long ib = atoll(a.c_str())-atoll(b.c_str());
    
    int nine[1000] = {0, };
    bool serial = true;
    for(int i = (int)a.length()-1;i>=0;i--) {
        if(a[i] == '9' && serial)
            nine[i] = nine[i+1] + 1;
        else if(a[i] != '9' || serial == false) {
            serial = false;
            nine[i] = nine[i+1];
        }
    }
    
	//   printf("%I64d %I64d %I64d\n", atoll(a.c_str()), atoll(b.c_str()), ib);
    string c = "";
    
    int i = 0;
    for(;i<a.length();i++) {
        long long tA = atoll(c.c_str()) * (long long)pow((double)10, (double)(a.length()-i));
        long long tB = ((long long)(a[i]-'0')*(long long)pow((double)10, (double)(a.length()-i-1)) - 1);
        
        long long now = tA + tB;
        
		//    printf("-%d %I64d %I64d %I64d %I64d-\n", (int)(a[i]-'0'),tA, tB, now, atoll(c.c_str()));
        
        if(nine[i] >= (int)a.length()-1-i && a[a.length()-1] == '9') {
			//    printf("isbreak\n");
            break;
        }
        
        if(now < ib) {
            c = c+a[i];         
            continue;
        }
        else {
            if(now % 10 != 9)
                printf("%s\n", a.c_str());
            else
                printf("%I64d\n", now);
            return 0;
        }
    }
    
    c = c+a.substr(i, a.length()-i);
    
    if(c[c.length()-1] != '9')
        printf("%s\n", a.c_str());
    else
        printf("%s\n", c.c_str());
}