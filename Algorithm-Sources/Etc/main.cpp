#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int strcmp(char *s1, char *s2)
{
    while((*s1 != '\0' && *s2 != '\0') && *s1 == *s2) {s1++;s2++;}
    if(*s1 == *s2) return 0;
    else if(*s1 > *s2) return 1;
    return -1;
}

char norepeat(char *s)
{
    for(int i = 0;s[i];i++)
    {
        int j = i+1;
        for(;s[j];j++)
            if(s[i] == s[j]) break;
        if(s[j] == '\0')
            return s[i];
    }
    return '\0';
}
#include<iostream>
#include<string>
using namespace std;

int nCnt = 0;
void solve(int left, int right, int n, string &s)
{
    static bool comma = false;
    if(left == n && right == n) {
        if(comma) cout << ", ";
        comma = true;
        cout << s;
        nCnt++;
        if(nCnt % 5 == 0) cout << endl;
        return;
    }
    if(left >= right && left < n) {
        s += "(";
        solve(left+1, right, n, s);
        s = s.substr(0, s.length()-1);
    }
    if(right < left)
    {
        s += ")";
        solve(left, right+1, n, s);
        s = s.substr(0, s.length()-1);
    }
}

int main() {
    char (*func)(char *s) = norepeat;
    
    printf("%d\n", strcmp("abc", "cba"));
    printf("%c\n", (*func)("tear"));
    
    string s("");
    solve(0, 0, 3, s);
    cout<<endl << nCnt << endl;
}