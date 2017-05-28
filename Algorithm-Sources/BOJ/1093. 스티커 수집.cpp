#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>

using namespace std;

int n, k;
map<int, pair<int, int> > d;
set<int> used;
vector<pair<int, int> > ar;

int solve(int key, int now)
{
    int minPrice = d[key].first, value = d[key].second;
    for(int i = now;i<n;i++)
    {
        if(d[key].second - ar[now].second >= k)
        {
            int newKey = key ^ (1 << now);
            int newPrice;
            if(now + 1 == n)
                newPrice = d[key].first - ar[now].first;
            else if(used.find(newKey) != used.end())
                newPrice = d[newKey].first;
            else
            {
                d[newKey] = make_pair(d[key].first - ar[now].first, d[key].second - ar[now].second);
                newPrice = solve(newKey, now + 1);
            }
            
            if(minPrice > newPrice)
            {
                minPrice = newPrice;
                value = d[key].second - ar[now].second;
            }
        }
    }
    
    d[key] = make_pair(minPrice, value);
    used.insert(key);
    
    return minPrice;
}

int main()
{
    freopen("input.in", "r", stdin);
    
    scanf("%d", &n);
    
    for(int i = 0;i<n;i++)
    {
        int price;
        scanf("%d", &price);
        ar.push_back(make_pair(price, 0));
    }
    
    for(int i = 0;i<n;i++)
    {
        int value;
        scanf("%d", &value);
        ar[i].second = value;
    }
    
    int key = 0;
    int sumPrice = 0, sumValue = 0;
    for(int i = 0;i<n;i++)
    {
        key |= 1 << i;
        sumPrice += ar[i].first;
        sumValue += ar[i].second;
    }
    
    scanf("%d", &k);
    int nHave, sumHave = 0;
    scanf("%d", &nHave);
    for(int i = 0;i<nHave;i++)
    {
        int idx;
        scanf("%d", &idx);
        sumHave += ar[i].first;
    }
    
    d[key] = make_pair(sumPrice, sumValue);
    solve(key, 0);
    printf("%d\n", sumValue >= k ? solve(key, 0) - sumHave : -1);
}