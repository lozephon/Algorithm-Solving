#include<stdio.h>

void solve(int n, int m, bool now, int &a, int &b)
{
    if(now)
        n--;
    else
        m--;
 
    bool turn = false;
    while(n + m > 0)
    {
        if(turn)
        {
            if((now && n > 0) || (!now && m == 0)) {
                n--;
                if(now == true) a++;
                else b++;
                now = true;
            }
            else {
                m--;
                if(now == false) a++;
                else b++;
                now = false;
            }
        }
        else
        {
            if((now && m > 0) || (!now && n == 0)) {
                m--;
                if(now == false) a++;
                else b++;
                now = false;
            }
            else
            {
                n--;
                if(now == true) a++;
                else b++;
                now = true;
            }
        }
        turn = !turn;
    }
}

int main()
{
//    freopen("input.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    
    int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    solve(n, m, true, a1, b1);
    solve(n, m, false, a2, b2);
    
    printf("%d %d\n", a1 > a2 ? a1 : a2, a1 > a2 ? b1 : b2);
}