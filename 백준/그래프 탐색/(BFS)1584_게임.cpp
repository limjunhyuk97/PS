// 위험한 구역 + 죽음의 구역
#include <iostream>
#include <algorithm>
#include <queue>
#define DANGER 'A'
#define DEATH 'B'
#define INF 2000000000
#define MAXLEN 505
using namespace std;

typedef pair<int, int> Coord;
typedef pair<int, Coord> Node;

int N, M;
int grid[MAXLEN][MAXLEN];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool OOB(int x, int y) {
    if(x < 0 || x > 500) return true;
    if(y < 0 || y > 500) return true;
    return false;
}

void mark_grid(int x1, int y1, int x2, int y2, char ch) {
    int mark = (ch == DANGER ? 1 : INF);
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    for(int i=x1; i<=x2; ++i) {
        for(int j=y1; j<=y2; ++j) {
            if(grid[i][j] <= mark) grid[i][j] = mark;
            else continue;
        }
    }
}

int Dijkstra() {
    int dist[MAXLEN][MAXLEN];
    
    int MAXDIST = INF+300000;
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            dist[i][j] = MAXDIST;
        }
    }
    dist[0][0] = 0;
    
    priority_queue<Node> pq;
    pq.push({0, {0, 0}});
    
    while(!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        
        int cd = -cur.first;
        Coord cc = cur.second;
        
        if(cd > dist[cc.first][cc.second]) continue;
        
        for(int i=0; i<4; ++i) {
            int nx = cc.first + dx[i];
            int ny = cc.second + dy[i];
            if(OOB(nx, ny)) continue;
            if(grid[nx][ny] == INF) continue;
            if(dist[nx][ny] > dist[cc.first][cc.second] + grid[nx][ny]) {
                dist[nx][ny] = dist[cc.first][cc.second] + grid[nx][ny];
                pq.push({-dist[nx][ny], {nx, ny}});
            }
        }
    }
    
    if(dist[500][500] >= MAXDIST) return -1;
    else return dist[500][500];
}

int main(void) {
    
    // Danger zone
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        mark_grid(x1, y1, x2, y2, DANGER);
    }
    
    // Death zone
    scanf("%d", &M);
    for(int i=0; i<M; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        mark_grid(x1, y1, x2, y2, DEATH);
    }
    
    grid[0][0] = 0;
    
    printf("%d\n", Dijkstra());
    
    return 0;
}
