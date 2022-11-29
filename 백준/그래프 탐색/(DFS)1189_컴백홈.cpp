#include <iostream>
#include <string>
#define MAXLEN 10
using namespace std;

int R, C, K;
int cnt;
string grid[MAXLEN];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

bool OOB(int x, int y) {
    if(x<0 || y<0 || x>=R || y>=C) return true;
    else return false;
}

bool visited[MAXLEN][MAXLEN];
void dfs(int n, int m, int len) {
    if(n == 0 && m == C-1) {
        if(len == K) {
            cnt += 1;
        }
        return;
    }
    
    visited[n][m] = true;
    for(int i=0; i<4; ++i) {
        int nextX = n + dx[i];
        int nextY = m + dy[i];
        if(OOB(nextX, nextY) || visited[nextX][nextY] || grid[nextX][nextY] == 'T') continue;
        else {
            dfs(nextX, nextY, len+1);
        }
    }
    visited[n][m] = false;
}

int main(void) {
    
    cin >> R >> C >> K;
    
    for(int i=0; i<R; ++i) {
        cin >> grid[i];
    }
    
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            visited[i][j] = false;
        }
    }
    
    dfs(R-1, 0, 1);
    
    printf("%d\n", cnt);
    
    return 0;
}
