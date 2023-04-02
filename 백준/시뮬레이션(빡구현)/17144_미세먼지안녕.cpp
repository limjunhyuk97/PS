#include <iostream>
#define MAXLEN 55
using namespace std;

typedef pair<int, int> co;

int R, C, T;
int dust[MAXLEN][MAXLEN];
int add_dust[MAXLEN][MAXLEN];

co cl1, cl2;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

bool OOB(int x, int y) {
    if(x < 0 || y < 0 || x >= R || y >= C) return true;
    else return false;
}

bool is_cleaner(int x, int y) {
    if(cl1 == co({x,y}) || cl2 == co({x, y})) return true;
    else return false;
}

void init_add_dust() {
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            add_dust[i][j] = 0;
        }
    }
}

void spread_dust() {
    init_add_dust();
    for(int x=0; x<R; ++x) {
        for(int y=0; y<C; ++y) {
            int add_cnt = 0;
            int adder = dust[x][y] / (int)5;
            if(dust[x][y] == 0) continue;
            for(int i=0; i<4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if(OOB(nx, ny)) continue;
                if(is_cleaner(nx, ny)) continue;
                add_dust[nx][ny] += adder;
                add_cnt += 1;
            }
            dust[x][y] -= (adder * add_cnt);
        }
    }
    // 생긴만큼 더하기
    for(int x=0; x<R; ++x) {
        for(int y=0; y<C; ++y) {
            dust[x][y] += add_dust[x][y];
        }
    }
}

void clean_dust() {
    // cleaner 1 구역 클렌징
    for(int r=cl1.first-2; r>=0; --r) dust[r+1][0] = dust[r][0];
    for(int c=1; c<C; ++c) dust[0][c-1] = dust[0][c];
    for(int r=1; r<=cl1.first; ++r) dust[r-1][C-1] = dust[r][C-1];
    for(int c=C-2; c>=0; --c) dust[cl1.first][c+1] = dust[cl1.first][c];
    // cleaner 2 구역 클렌징
    for(int r=cl2.first+2; r<R; ++r) dust[r-1][0] = dust[r][0];
    for(int c=1; c<C; ++c) dust[R-1][c-1] = dust[R-1][c];
    for(int r=R-2; r>=cl2.first; --r) dust[r+1][C-1] = dust[r][C-1];
    for(int c=C-2; c>=0; --c) dust[cl2.first][c+1] = dust[cl2.first][c];
}

int get_dust() {
    int dusts = 0;
//    cout << endl;
    for(int x=0; x<R; ++x) {
        for(int y=0; y<C; ++y) {
            dusts += dust[x][y];
//            cout << dust[x][y] << " ";
        }
//        cout << endl;
    }
    return dusts;
}

int main(void) {
    
    scanf("%d %d %d", &R, &C, &T);
    
    bool cf = false;
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            scanf("%d", &dust[i][j]);
            if(dust[i][j] == -1) {
                if(!cf) {
                    cl1 = {i, j};
                    cf = true;
                }
                else {
                    cl2 = {i, j};
                }
                dust[i][j] = 0;
            }
        }
    }
    
    for(int t=0; t<T; ++t) {
        spread_dust();
        clean_dust();
    }
    
    printf("%d\n", get_dust());
    
    return 0;
}
