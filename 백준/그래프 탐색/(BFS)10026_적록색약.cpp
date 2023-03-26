#include <iostream>
#include <queue>
#define MAXLEN 105
using namespace std;

typedef pair<int, int> co;

int N;
char grid[MAXLEN][MAXLEN];
bool checked[MAXLEN][MAXLEN];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool OOB(const co &c) {
    if(c.first < 0 || c.second < 0 || c.first >=N || c.second >= N) return true;
    else return false;
}

bool isTarget(int x, int y, const char & c) {
    if(grid[x][y] == c) return true;
    else return false;
}

void initChecked() {
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            checked[i][j] = false;
        }
    }
}

void floodfill(const co & cur, const char & target, bool isNormal) {
    queue<co> que;
    que.push(cur);
    
    while(!que.empty()) {
        co cur = que.front(); que.pop();
        for(int i=0; i<4; ++i) {
            co next = {cur.first + dx[i], cur.second + dy[i]};
            int x = next.first;
            int y = next.second;

            // 색맹과 일반인 구분
            if(isNormal) {
                if(!isTarget(x, y, target)) continue;
            }
            else {
                if((target == 'R' || target == 'G') && (isTarget(x, y, 'B'))) continue;
                if((target == 'B') && (!isTarget(x, y, 'B'))) continue;
            }
            
            if(OOB(next) || checked[x][y]) continue;
            else {
                que.push(next);
                checked[next.first][next.second] = true;
            }
        }
    }
    
    return;
}

int normalView() {
    initChecked();
    
    int cnt = 0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(checked[i][j]) continue;
            char target = grid[i][j];
            co cur = {i, j};
            floodfill(cur, target, true);
            cnt += 1;
        }
    }
    
    return cnt;
}

int rgbView() {
    initChecked();
    
    int cnt = 0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(checked[i][j]) continue;
            char target = grid[i][j];
            co cur = {i, j};
            floodfill(cur, target, false);
            cnt += 1;
        }
    }
    
    return cnt;
}

int main(void) {
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%s", grid[i]);
    }
    
    printf("%d %d\n", normalView(), rgbView());
    
    return 0;
}
