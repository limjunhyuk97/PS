#include <iostream>
#include <vector>
#include <queue>
#define MAXN 15
#define MAXK 15
using namespace std;

struct horse {
    int x;
    int y;
    int d;
};

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int inverted[5] = {0, 2, 1, 4, 3};

int color_grid[MAXN][MAXN];
deque<int> horse_grid[MAXN][MAXN];
horse horses[MAXK];

int N, K;
int tick = -1;

void initColorGrid() {
    for(int i=0; i<MAXN; ++i) {
        for(int j=0; j<MAXN; ++j) {
            color_grid[i][j] = -1;
        }
    }
}

bool OOB(int x, int y) {
    if(x < 1 || y < 1 || x > N || y > N) return true;
    else return false;
}

bool run() {
    
    for(int idx=1; idx<=K; ++idx) {
        int d = horses[idx].d;
        int x = horses[idx].x;
        int y = horses[idx].y;
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if(OOB(nx, ny) || color_grid[nx][ny] == 2) {
            d = inverted[d];
            nx = x + dx[d];
            ny = y + dy[d];
        }
        
        // white
        if(color_grid[nx][ny] == 0) {
            // 내 위에 있는 것들만 추출
            deque<int> move_target;
            while(horse_grid[x][y].back() != idx) {
                int other = horse_grid[x][y].back();
                move_target.push_back(other);
                horse_grid[x][y].pop_back();
                // 따라온놈 위치 변경
                horses[other]={nx, ny, horses[other].d};
            }
            move_target.push_back(idx);
            horse_grid[x][y].pop_back();
            // 이동
            while(!move_target.empty()) {
                horse_grid[nx][ny].push_back(move_target.back());
                move_target.pop_back();
            }
            // 4 이상이면 탈출
            if(horse_grid[nx][ny].size() > 3) return true;
            // 내 위치 변경
            horses[idx] = {nx, ny, d};
            
        }
        
        // red
        else if(color_grid[nx][ny] == 1) {
            // 내 위에 있는 것들만 뒤집어서 데려간다.
            while(horse_grid[x][y].back() != idx) {
                int other = horse_grid[x][y].back();
                horse_grid[nx][ny].push_back(other);
                horse_grid[x][y].pop_back();
                // 따라온 놈 위치 변경
                horses[other]={nx, ny, horses[other].d};
            }
            horse_grid[nx][ny].push_back(idx);
            horse_grid[x][y].pop_back();
            // 4 이상이면 탈출
            if(horse_grid[nx][ny].size() > 3) return true;
            // 내 위치 변경
            horses[idx] = {nx, ny, d};
        }
        
        // blue of OOB
        else {
            // 아무데도 안움직임 . 방향만 전환
            horses[idx] = {x, y, d};
        }
    }
    
    
    return false;
}

int main(void) {
    
    scanf("%d %d", &N, &K);
    
    initColorGrid();
    
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            scanf("%d", &color_grid[i][j]);
        }
    }
    
    for(int i=1; i<=K; ++i) {
        int x, y, d; scanf("%d %d %d", &x, &y, &d);
        horses[i] = {x, y, d};
        horse_grid[x][y].push_back(i);
    }
    
    for(int time=1; time <=1000; ++time) {
        if(run()) {
            tick = time;
            break;
        }
    }
    
    printf("%d\n", tick);
    
    return 0;
}
