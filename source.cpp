#include <iostream>
#include <queue>
#define MAXLEN 105
using namespace std;

typedef pair<int, int> co;

int N;
int grid[MAXLEN][MAXLEN];
bool visited[MAXLEN][MAXLEN];

int minH = 105;
int maxH = -1;
int maxSafe = 1;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void initVisited() {
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            visited[i][j] = false;
        }
    }
}

bool OOB(co node) {
    int x = node.first;
    int y = node.second;
    if(x < 0 || y < 0 || x >=N || y >= N) return true;
    else return false;
}

void bfs(int x, int y, int h) {
    co cur = {x, y};
    
    queue<co> que;
    que.push(cur);
    
    while(!que.empty()) {
        co cur = que.front(); que.pop();
        
        for(int i=0; i<4; ++i) {
            co next = {cur.first + dx[i], cur.second + dy[i]};
            if(OOB(next) || grid[next.first][next.second] <=h || visited[next.first][next.second]) continue;
            else {
                que.push(next);
                visited[next.first][next.second] = true;
            }
        }
    }
    
}

int main(void) {
    
    scanf("%d", &N);
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            scanf("%d", &grid[i][j]);
            minH = minH > grid[i][j] ? grid[i][j] : minH;
            maxH = maxH < grid[i][j] ? grid[i][j] : maxH;
        }
    }
    
    maxH += 1;
    for(int h=minH; h<maxH; ++h) {
        initVisited();
        int safe = 0;
        for(int x=0; x<N; ++x) {
            for(int y=0; y<N; ++y) {
                if(grid[x][y] <= h || visited[x][y]) continue;
                else {
                    safe += 1;
                    bfs(x, y, h);
                }
            }
        }
        maxSafe = maxSafe < safe ? safe : maxSafe;
    }
    
    printf("%d\n", maxSafe);
    
    return 0;
}
