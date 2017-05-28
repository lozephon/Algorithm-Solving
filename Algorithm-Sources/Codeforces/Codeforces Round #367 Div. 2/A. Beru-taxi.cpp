//
//  A.cpp
//  Algorithm-Solving
//
//  Created by 김준엽 on 2016. 9. 5..
//  Copyright © 2016년 puertorico. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    freopen("input.in", "r", stdin);
    int a, b;
    scanf("%d%d", &a, &b);
    
    int n;
    scanf("%d", &n);
    
    double ans = 100000;
    for(int i = 0;i<n;i++)
    {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        
        double c = (x-a)*(x-a) + (y-b)*(y-b);
        ans = min(sqrt(c)/v, ans);
    }
    
    printf("%f", ans);
}