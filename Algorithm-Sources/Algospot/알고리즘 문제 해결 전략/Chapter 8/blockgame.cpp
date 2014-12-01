#include<stdio.h>
#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

int n = 5;
vector<int> moves;
char d[1<<25];

int dx[6][3] = {{0, 1}, {0, 0}, {0, 1, 1}, {1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
int dy[6][3] = {{0, 0}, {0, 1}, {0, 0, 1}, {0, 1, 1} ,{0, 1, 1}, {0, 0, 1}};
int nd[6] = {2,2,3,3,3,3};

bool solve(int state) {
    if(d[state] != -1)
        return d[state];
    
    for(int i = 0;i<moves.size();i++)
        if(!(state & moves[i]))
           if(!solve(state | moves[i]))
               return d[state] = 1;
    
    return d[state] = 0;
}

void makeMoves() {
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            for(int k = 0;k<6;k++) {
                int s = 0;
                bool poss = true;
                for(int l = 0;l<nd[k];l++) {
                    int ii = i+dx[k][l];
                    int jj = j+dy[k][l];
                    if(ii >= n || jj >= n)
                        poss = false;
                    s |= 1 << (ii*5 + jj);
                }
                if(poss)
                    moves.push_back(s);
            }
        }
    }
}

inline int cell(int y, int x) {return 1 << (y*5 + x); }
void makeMoves2() {
    for(int y = 0; y<4; y++) {
        for(int x = 0;x<4;x++) {
            vector<int> cells;
            for(int dy = 0;dy<2;dy++) {
                for(int dx = 0;dx<2;dx++)
                    cells.push_back(cell(y+dy, x+dx));
            }
            int square = cells[0] + cells[1] + cells[2] + cells[3];
            for(int i = 0;i<4;i++)
                moves.push_back(square - cells[i]);
        }
    }
    
    for(int i = 0;i<5;i++) {
        for(int j = 0;j<4;j++) {
            moves.push_back(cell(i, j) + cell(i, j+1));
            moves.push_back(cell(j, i) + cell(j+1, i));
        }
    }
}

int main() {
//    freopen("input.in", "r", stdin);
    int caseNum;
    scanf("%d", &caseNum);
    
    /*
    for(int i = 0;i<6;i++) {
        for(int j = 0;j<nd[i];j++)
            printf("(%d, %d) ", dx[i][j], dy[i][j]);
        printf("\n");
    }*/
    
    makeMoves();
   
    memset(d, -1, sizeof(d));
    
    while(caseNum--) {
        char line[10];
        int state = 0;
        for(int i = 0;i<n;i++) {
            scanf("%s", line);
            for(int j = 0;j<n;j++)
                if(line[j] == '#')
                    state += 1 << (i*5+j);
        }
        
        printf("%s\n", solve(state) ? "WINNING" : "LOSING");
    }
}