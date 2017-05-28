//
//  Nexon1.cpp
//  Algorithm-Solving
//
//  Created by 김준엽 on 2017. 3. 13..
//  Copyright © 2017년 puertorico. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> Key;
map<Key, int> rowIds, colIds;
map<int, bool> rows, cols;
int cnt;
int maxN;
int n;

void Solve(int x, int y, int level)
{
    for(int i = x;i<n;++i)
    {
        int j = i == x ? y : 0;
        for(;j<n;++j)
        {
            Key key(i, j);
            map<Key, int>::iterator rowKey = rowIds.find(key), colKey = colIds.find(key);
            if(rowKey == rowIds.end())
                continue;
            
            if(rows[rowKey->second] == false && cols[colKey->second] == false)
            {
                rows[rowKey->second] = true;
                cols[colKey->second] = true;
                
                //printf("%d, %d, %d\n", i, j, level+1);
                Solve(i, j, level+1);
                
                rows[rowKey->second] = false;
                cols[colKey->second] = false;
            }
        }
    }
    
    if(maxN < level)
    {
        cnt = 1;
        maxN = level;
    }
    else if(maxN == level)
    {
        cnt++;
    }
    //printf("\n");
}

int main()
{
    freopen("input.in", "r", stdin);
    
    scanf("%d", &n);
    
    bool m[100][100];
    for(int i = 0;i<n;i++)
    {
        char line[100];
        scanf("%s", line);
        for(int j = 0;j<n;++j)
        {
            m[i][j] = line[j] == 'o';
        }
    }
    
    int rowId = 0, colId = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(m[i][j] == false)
                continue;
            
            Key key = make_pair(i, j);
            if(rowIds.find(key) == rowIds.end())
            {
                int newRowId = rowId++;
                
                for(int k = j;k<n;k++)
                {
                    if(m[i][k] == false)
                        break;
                    Key newKey = make_pair(i, k);
                    rowIds[newKey] = newRowId;
                }
                rows[newRowId] = false;
            }
            if(colIds.find(key) == colIds.end())
            {
                int newColId = colId++;
                
                for(int k = i;k<n;k++)
                {
                    if(m[k][j] == false)
                        break;
                    Key newKey = make_pair(k, j);
                    colIds[newKey] = newColId;
                }
                cols[newColId] = false;
            }
        }
    }
/*
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;++j)
        {
            Key key(i, j);
            map<Key, int>::iterator it = rowIds.find(key);
            if(it == rowIds.end())
                printf("00/");
            else
                printf("%02d/", (*it).second + 1);
        }
        printf("\n");
    }
    
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;++j)
        {
            Key key(i, j);
            map<Key, int>::iterator it = colIds.find(key);
            if(it == colIds.end())
                printf("00/");
            else
                printf("%02d/", (*it).second + 1);
        }
        printf("\n");
    }
*/

    Solve(0, 0, 0);
    
    printf("%d\t%d\n", maxN, cnt);
    
    return 0;
}

