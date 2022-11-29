#include <iostream>
#include <algorithm>
#include <queue>
#define MAXLEN 105
using namespace std;

typedef pair<int, int> co;

int N, M, K, garbage;
bool grid[MAXLEN][MAXLEN];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
bool visited[MAXLEN][MAXLEN];

bool OOB(int x, int y) {
    if(x < 1 || y < 1 || x >N || y > M) return true;
    else return false;
}

void bfs(int x, int y) {
    int cnt = 1;
    
    queue<co> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while(!q.empty()) {
        co cur = q.front();
        q.pop();
        
        for(int i=0; i<4; ++i) {
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];
            if(OOB(nextX, nextY)) continue;
            if(visited[nextX][nextY]) continue;
            if(!grid[nextX][nextY]) continue;
            
            visited[nextX][nextY] = true;
            q.push({nextX, nextY});
            cnt += 1;
        }
    }
    
    garbage = max(garbage, cnt);
}

int main(void) {
    
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0; i<K; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        grid[x][y] = true;
    }
    
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=M; ++j) {
            if(!grid[i][j]) continue;
            if(visited[i][j]) continue;
            bfs(i, j);
        }
    }
    
    printf("%d\n", garbage);
    
    return 0;
}
