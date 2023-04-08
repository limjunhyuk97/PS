#include <iostream>
#include <queue>
#define MAXLEN 55
using namespace std;

struct co {
    int x;
    int y;
};

struct turn {
    int x;
    int d;
    int k;
};

int N, M, T;
int grid[MAXLEN][MAXLEN];
turn turns[MAXLEN];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1 ,-1, 0};

bool OOB(int r, int c) {
    if(r < 0 || c < 0 || r >= N || c >= M) return true;
    else return false;
}

bool isGridEmpty() {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(grid[i][j] != 0) return false;
        }
    }
    return true;
}

int getGridSum() {
    int sum = 0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            sum += grid[i][j];
        }
    }
    return sum;
}

void turnGrid(turn & t) {
    for(int r=0; r<N; ++r) {
        int row = r + 1;
        // x 배수 아니면 다음거
        if(row % t.x) continue;
        
        // 배열 임시 복제
        int tmp[M];
        for(int i=0; i<M; ++i) {
            tmp[i] = grid[r][i];
        }
        // 이동 - 시계
        if(t.d == 0) {
            for(int i=0; i<M; ++i) {
                grid[r][(i+t.k)%M] = tmp[i];
            }
        }
        // 이동 - 반시계
        else {
            for(int i=0; i<M; ++i) {
                grid[r][(i-t.k+M)%M] = tmp[i];
            }
        }
    }

}

// true면 인접한데 수 같은 것 존재했던 것.
// false면 인접한데 수 같은 것 없던 것.
// 너비 우선 탐색으로 지워야 함
bool trimGridBFS(int r, int c, int val) {
    queue<co> que;
    que.push({r, c});
    
    bool renewed = false;
    
    while(!que.empty()) {
        co cur = que.front(); que.pop();
        
        // left
        if(val == grid[cur.x][(cur.y-1+M)%M]) {
            renewed = true;
            grid[cur.x][(cur.y-1+M)%M] = 0;
            que.push({cur.x, (cur.y-1+M)%M});
        }
        // right
        if(val == grid[cur.x][(cur.y+1)%M]) {
            renewed = true;
            grid[cur.x][(cur.y+1)%M] = 0;
            que.push({cur.x, (cur.y+1)%M});
        }
        // up
        if(cur.x > 0 && val == grid[cur.x-1][cur.y]) {
            renewed = true;
            grid[cur.x-1][cur.y] = 0;
            que.push({cur.x-1, cur.y});
        }
        // down
        if(cur.x < N-1 && val == grid[cur.x+1][cur.y]) {
            renewed = true;
            grid[cur.x+1][cur.y] = 0;
            que.push({cur.x+1, cur.y});
        }
        if(renewed) grid[r][c] = 0;
    }
    
    
    return renewed;
}

void avgGrid() {
    int sum = 0, cnt = 0;
    double avg = 0;
    for(int r=0; r<N; ++r) {
        for(int c=0; c<M; ++c) {
            sum += grid[r][c];
            if(grid[r][c] != 0) cnt += 1;
        }
    }
    avg = (double)sum / (double)(cnt);
    for(int r=0; r<N; ++r) {
        for(int c=0; c<M; ++c) {
            if(grid[r][c] == 0) continue;
            if ((double)grid[r][c] > avg) grid[r][c] -= 1;
            else if ((double)grid[r][c] < avg) grid[r][c] += 1;
        }
    }
}

void printGrid() {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    
    scanf("%d %d %d", &N, &M, &T);
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    for(int i=0; i<T; ++i) {
        int x, d, k; scanf("%d %d %d", &x, &d, &k);
        turns[i] = {x, d, k};
    }
    
    for(int i=0; i<T; ++i) {
        turnGrid(turns[i]);
        
        ///
//        printGrid();
        ///
        
        if(isGridEmpty()) break;
        
        bool trimmed = false;
        
        for(int r=0; r<N; ++r) {
            for(int c=0; c<M; ++c) {
                if(grid[r][c] == 0) continue;
                if(trimGridBFS(r, c, grid[r][c])) trimmed = true;
            }
        }
        
        ///
//        printGrid();
        ///
        
        
        if(!trimmed) avgGrid();
    }
    
    printf("%d\n", getGridSum());
    
    return 0;
}
