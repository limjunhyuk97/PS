#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX_LEN 25
#define INF 2000000000
#define IMPOSSIBLE "impossible"
#define horizontal '-'
#define vertical '|'
using namespace std;

typedef pair<int, int> coord;
struct tick {
    char init;
    int LR;
    int NS;
    
    char currentTick(int time) {
        if(time == 0) return init;
        time -= 1;
        if(init == horizontal) {
            if(time % (LR + NS) < LR) return horizontal;
            else return vertical;
        }
        else {
            if(time % (LR + NS) < NS) return vertical;
            else return horizontal;
        }
    }
};

int M, N, L;
vector<string> grid;
coord lights[11], startingPoint, endPoint;
tick ticks[11];
int dist[MAX_LEN][MAX_LEN];
bool tickNearby[MAX_LEN][MAX_LEN];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

bool OOB(coord cur) {
    int x = cur.first;
    int y = cur.second;
    if(x < 0 || x > M-1 || y < 0 || y > N-1) return true;
    else return false;
}

void dijkstra(coord start) {
    priority_queue<pair<int, coord > > pq;
    pq.push({0, start});
    dist[start.first][start.second] = 0;
    
    while(!pq.empty()) {
        int curDist = -pq.top().first;
        coord cur = pq.top().second;
        int curX = cur.first;
        int curY = cur.second;
        pq.pop();
        
        // 근처에 신호가 없는 경우
        if(!tickNearby[curX][curY] && dist[curX][curY] < curDist) continue;
        
        for(int i=0; i<4; ++i) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            int nextDist = curDist + 1;
            // Out Of Bound
            if(OOB({nextX, nextY})) continue;
            // 차 못들어감
            if(grid[nextX][nextY]=='.') continue;
            // 도로 또는 종착점, 시작점
            else if( (grid[nextX][nextY]=='#' || grid[nextX][nextY]=='B' || grid[nextX][nextY]=='A')) {
                if(dist[nextX][nextY] > nextDist) {
                    pq.push({-(curDist+1), {nextX, nextY}});
                    dist[nextX][nextY] = nextDist;
                }
            }
            // 교차로
            else {
                char currentTick = ticks[grid[nextX][nextY]-'0'].currentTick(nextDist);
                // 위아래로 접근
                if(i == 0 || i == 3) {
                        if(dist[nextX][nextY] > nextDist) {
                            if(currentTick == vertical) {
                                pq.push({-nextDist, {nextX, nextY}});
                                dist[nextX][nextY] = nextDist;
                            }
                            else {
                                pq.push({-nextDist, {curX, curY}});
                            }
                        }
                }
                // 좌우로 접근
                else {
                        if(dist[nextX][nextY] > nextDist) {
                            if(currentTick == horizontal) {
                                pq.push({-nextDist, {nextX, nextY}});
                                dist[nextX][nextY] = nextDist;
                            }
                            else {
                                pq.push({-nextDist, {curX, curY}});
                            }
                        }
                
                }
            }
        }
    }
}

int main(void) {
    
    while(true) {
        // 행-열 길이 데이터 받기
        cin >> M >> N;
        if(M == 0 && N == 0) break;
        
        // 초기화
        grid.clear();
        L = 0;
        for(int i=0; i<MAX_LEN; ++i) {
            for(int j=0; j<MAX_LEN; ++j) {
                dist[i][j] = INF;
                tickNearby[i][j] = false;
            }
        }
        
        // grid 입력
        for(int i=0; i<M; ++i) {
            string str; cin >> str;
            grid.push_back(str);
            for(int j=0; j<N; ++j) {
                // 신호등 위치 입력
                if(grid[i][j]>='0' && grid[i][j]<='9') {
                    lights[grid[i][j]-'0']={i, j};
                    L += 1;
                }
                // 시작점 입력
                if(grid[i][j] == 'A') startingPoint = {i, j};
                // 끝점 입력
                if(grid[i][j] == 'B') endPoint = {i, j};
            }
        }
        
        // 신호등 정보 입력
        for(int i=0; i<L; ++i) {
            char direction;
            int cnt, LR, NS;
            cin >> cnt >> direction >> LR >> NS;
            ticks[cnt] = {direction, LR, NS};
        }
        
        // 근처에 신호등 있는지 여부 체크
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if(grid[i][j]=='.') continue;
                for(int k=0; k<4; ++k) {
                    if(OOB({i+dx[k], j+dy[k]})) continue;
                    if(grid[i+dx[k]][j+dy[k]] >= '0' && grid[i+dx[k]][j+dy[k]] <= '9') {
                        tickNearby[i][j] = true;
                        break;
                    }
                }
            }
        }
        
        // 거리측정
        dijkstra(startingPoint);
        if(dist[endPoint.first][endPoint.second] == INF) cout << IMPOSSIBLE << endl;
        else cout << dist[endPoint.first][endPoint.second]  << endl;
    }
    
    return 0;
}
