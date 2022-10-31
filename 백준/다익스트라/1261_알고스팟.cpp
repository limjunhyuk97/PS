/**
    Q. 어느 지점에 도착하기위해 거쳐갈 최단 거리는 얼마인가?
    A. Dijkstra가 해법이 될 수 있다.
 */

#include <iostream>
#include <queue>
#include <string>
#define MAX_LEN 105
#define DEFAULT 2000000000;
using namespace std;

typedef pair<int, pair<int,int> > node;

int N, M;
int grid[MAX_LEN][MAX_LEN];
int dist[MAX_LEN][MAX_LEN];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

bool OOB(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= M) return false;
    else return true;
}

int dijkstra(int x, int y) {
    priority_queue<node> pq;
    pq.push({0, {x, y}});
    
    while(!pq.empty()) {
        node cur = pq.top();
        pq.pop();
        
        int cur_dist = -cur.first;
        int curX = cur.second.first;
        int curY = cur.second.second;
        
        if(cur_dist > dist[curX][curY]) continue;
        
        for(int i=0; i<4; ++i) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(!OOB(nextX, nextY)) continue;
            if(dist[nextX][nextY] > cur_dist + grid[nextX][nextY]) {
                pq.push({-(cur_dist+grid[nextX][nextY]), {nextX, nextY}});
                dist[nextX][nextY] = cur_dist + grid[nextX][nextY];
            }
        }
    }
    return dist[N-1][M-1];
}

// (0,0) - (N-1, M-1) 까지 최단경로
int main(void) {
    
    cin >> M >> N;
    
    for(int i=0; i<N; ++i) {
        string input; cin >> input;
        for(int j=0; j<M; ++j) {
            grid[i][j] = (input[j]-'0');
        }
    }
    
    // dist 배열 초기화
    for(int i=0; i<MAX_LEN; ++i) {
        for(int j=0; j<MAX_LEN; ++j) {
            dist[i][j] = DEFAULT;
        }
    }
    
    if(M == 1 && N == 1) cout << 0 << endl;
    else cout << dijkstra(0, 0) << endl;
    
    return 0;
}
