#include <iostream>
#include <queue>
#include <cmath>
#define MAXLEN 25
using namespace std;

typedef pair<int, int> co;

// compare를 쓸 때에는 '이 경우에 바꿔라!'
struct compare {
    bool operator()(const co & c1, const co & c2) const{
        if(c1.first != c2.first) return c1.first > c2.first;
        else return c1.second > c2.second;
    }
};

int N;
int grid[MAXLEN][MAXLEN];

int shark_size = 2;
int moves = 0;
int ate = 0;
co cur_pos, next_pos;

int dx[4]= {-1, 0, 0, 1};
int dy[4]={0, -1, 1, 0};
bool visited[MAXLEN][MAXLEN];

void initVisited() {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            visited[i][j] = false;
        }
    }
}

bool OOB(int x, int y) {
    if(x < 0 || y < 0 || x >=N || y >=N) return true;
    else return false;
}

bool movable(int x, int y) {
    if(OOB(x, y)) return false;
    if(visited[x][y]) return false;
    if(shark_size < grid[x][y]) return false;
    return true;
}

bool edible(int x, int y) {
    if(grid[x][y] == 0) return false;
    if(shark_size > grid[x][y]) return true;
    else return false;
}

int move_shark () {
    
    initVisited();
    cur_pos = next_pos;
    
    queue<co> que;
    que.push(cur_pos);
    visited[cur_pos.first][cur_pos.second] = true;
    int cnt = 0, tmp;
    
    while(!que.empty()) {
        cnt += 1;
        int size = (int)que.size();
        priority_queue<co, vector<co>, compare> pq;
        for(int q=0; q<size; ++q) {
            co cur = que.front(); que.pop();
            for(int i=0; i<4; ++i) {
                int nx = cur.first + dx[i], ny = cur.second + dy[i];
                if(!movable(nx, ny)) continue;
                else {
                    visited[nx][ny] = true;
                    pq.push({nx, ny});
                }
            }
        }
        size = (int)pq.size();
        for(int q=0; q<size; ++q) {
            co cur = pq.top(); pq.pop();
            int nx = cur.first, ny = cur.second;
            if(edible(nx, ny)) {
                tmp = grid[nx][ny];
                grid[cur_pos.first][cur_pos.second] = 0;
                grid[nx][ny] = 0;
                next_pos = {nx, ny};
                break;
            }
            else {
                que.push({nx, ny});
            }
        }
            
        if(next_pos != cur_pos) break;
    }
    
//    cout << "current size : " << shark_size << "/ before -> after : (" << cur_pos.first << "," << cur_pos.second << ")->(" << next_pos.first << "," << next_pos.second << ")" << " / target fish : " << tmp << " / move : " << cnt <<  endl;
//
//    for(int i=0; i<N; ++i) {
//        for(int j=0; j<N; ++j) {
//            cout << grid[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    return next_pos != cur_pos ? cnt : 0;
}

int main (void) {
    
    scanf("%d", &N);
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            scanf("%d", &grid[i][j]);
            if(grid[i][j] == 9) {
                cur_pos = {i, j};
                next_pos = {i, j};
            }
        }
    }

    while(true) {
        int move = move_shark();
        
        if(move == 0) break;
        else moves += move;
        
        ate += 1;
        if(shark_size == ate) {
            shark_size += 1;
            ate = 0;
        }
    }
    
    printf("%d\n", moves);
    
    return 0;
}
