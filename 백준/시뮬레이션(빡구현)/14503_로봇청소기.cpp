#include <iostream>
#define BLOCK 200
#define NO_POS pair<int, int>({-1, -1})
using namespace std;

typedef pair<pair<int, int>, int> pos_vector;

int N, M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int r, c, d;
int grid[55][55];

int moves = 0;

int reverse_pos(int d) {
    return (d + 2) % 4;
}

int spin_pos(int d) {
    if(d>0) return d-1;
    else return 3;
}

pos_vector next_pos(int x, int y, int d) {
    int pos = d;
    // 빈칸이있다면 그쪽으로 이동한다.
    for(int i=0; i<4; ++i) {
        pos = spin_pos(pos);
        if(grid[x+dx[pos]][y+dy[pos]] == 0) return {{x+dx[pos], y+dy[pos]}, pos};
    }
    // 빈칸이없다면 현재 방향을 반환한다.
    return {NO_POS, d};
}

void movement(int x, int y, int dir) {
    // 현재 칸 청소
    if(grid[x][y] == 0) moves += 1;
    grid[x][y] = 1;
    
    // 다음 청소할 곳을 찾는다.
    pos_vector npos = next_pos(x, y, dir);
    
    // 청소되지 않은 빈칸이 없다면
    if(npos.first == NO_POS) {
        int reverse = reverse_pos(npos.second);
        int nextX = x+dx[reverse], nextY = y+dy[reverse];
        // 바라보는 방향의 뒤가 벽이라면 작동 멈춘다.
        if(grid[nextX][nextY] == BLOCK ) return;
        // 그렇지 않다면 바라보는 방향을 유지한 채 뒤로간다.
        else movement(nextX, nextY, dir);
    }
    // 청소되지 않은 빈칸이 있다면 한칸 전진한다.
    else {
        movement(npos.first.first, npos.first.second, npos.second);
        return;
    }
}

int main(void) {
    
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            int cur; scanf("%d", &cur);
            if(cur == 1) grid[i][j] = BLOCK;
            else grid[i][j] = 0;
        }
    }
    
    movement(r, c, d);
    
    printf("%d\n", moves);
    
    return 0;
}
