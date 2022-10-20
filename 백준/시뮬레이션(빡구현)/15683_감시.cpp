// 지나간 자리에 흔적을 남기는 방법 : 배열에 남길 수 있다.

#include <string>
#include <vector>
#include <iostream>
#define MIN_UNVISIBLE 100
#define CCTV 1000
#define WALL -1
using namespace std;

typedef pair<int, int> coord;

int N, M;
char grid[10][10];
int checked[10][10];

vector<coord> cctv;
int min_unvisibles = MIN_UNVISIBLE;

int getUnvisible() {
    int unvisibles = 0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(checked[i][j] == 0)
                unvisibles += 1;
        }
    }
    return unvisibles;
}

void moveUpward(int x, int y, const string &order) {
    if(order == "scan") {
        while(x > -1) {
            if(grid[x][y] == '6') break;
            checked[x][y] += 1;
            x -= 1;
        }
    }
    if(order == "reverse") {
        while(x > -1) {
            if(grid[x][y] == '6') break;
            checked[x][y] -= 1;
            x -= 1;
        }
    }
}

void moveDownward(int x, int y, const string &order) {
    if(order == "scan") {
        while(x < N) {
            if(grid[x][y] == '6') break;
            checked[x][y] += 1;
            x += 1;
        }
    }
    if(order == "reverse") {
        while(x < N) {
            if(grid[x][y] == '6') break;
            checked[x][y] -= 1;
            x += 1;
        }
    }
}

void moveLeft(int x, int y, const string &order) {
    if(order == "scan") {
        while(y > -1) {
            if(grid[x][y] == '6') break;
            checked[x][y] += 1;
            y -= 1;
        }
    }
    if(order == "reverse") {
        while(y > -1) {
            if(grid[x][y] == '6') break;
            checked[x][y] -= 1;
            y -= 1;
        }
    }
}

void moveRight(int x, int y, const string &order) {
    if(order == "scan") {
        while(y < M) {
            if(grid[x][y] == '6') break;
            checked[x][y] += 1;
            y += 1;
        }
    }
    if(order == "reverse") {
        while(y < M) {
            if(grid[x][y] == '6') break;
            checked[x][y] -= 1;
            y += 1;
        }
    }
}

void dfs(int cur) {
    if(cur == cctv.size()) {
        int unvisibles = getUnvisible();
        if(min_unvisibles > unvisibles) min_unvisibles = unvisibles;
        return;
    }
    
    int x = cctv[cur].first;
    int y = cctv[cur].second;
    
    if(grid[x][y] == '1') {
        moveLeft(x, y, "scan");
        dfs(cur + 1);
        moveLeft(x, y, "reverse");
        
        moveRight(x, y, "scan");
        dfs(cur + 1);
        moveRight(x, y, "reverse");
        
        moveUpward(x, y, "scan");
        dfs(cur + 1);
        moveUpward(x, y, "reverse");
        
        moveDownward(x, y, "scan");
        dfs(cur + 1);
        moveDownward(x, y, "reverse");
    }
    else if(grid[cctv[cur].first][cctv[cur].second] == '2') {
        moveLeft(x, y, "scan");
        moveRight(x, y, "scan");
        dfs(cur + 1);
        moveLeft(x, y, "reverse");
        moveRight(x, y, "reverse");
        
        moveUpward(x, y, "scan");
        moveDownward(x, y, "scan");
        dfs(cur + 1);
        moveUpward(x, y, "reverse");
        moveDownward(x, y, "reverse");
    }
    else if(grid[cctv[cur].first][cctv[cur].second] == '3') {
        moveUpward(x, y, "scan");
        moveRight(x, y, "scan");
        dfs(cur + 1);
        moveUpward(x, y, "reverse");
        moveRight(x, y, "reverse");
        
        moveRight(x, y, "scan");
        moveDownward(x, y, "scan");
        dfs(cur + 1);
        moveRight(x, y, "reverse");
        moveDownward(x, y, "reverse");
        
        moveDownward(x, y, "scan");
        moveLeft(x, y, "scan");
        dfs(cur + 1);
        moveDownward(x, y, "reverse");
        moveLeft(x, y, "reverse");
        
        moveUpward(x, y, "scan");
        moveLeft(x, y, "scan");
        dfs(cur + 1);
        moveUpward(x, y, "reverse");
        moveLeft(x, y, "reverse");
    }
    else if(grid[cctv[cur].first][cctv[cur].second] == '4') {
        moveUpward(x, y, "scan");
        moveRight(x, y, "scan");
        moveDownward(x, y, "scan");
        dfs(cur + 1);
        moveUpward(x, y, "reverse");
        moveRight(x, y, "reverse");
        moveDownward(x, y, "reverse");
        
        moveRight(x, y, "scan");
        moveDownward(x, y, "scan");
        moveLeft(x, y, "scan");
        dfs(cur + 1);
        moveRight(x, y, "reverse");
        moveDownward(x, y, "reverse");
        moveLeft(x, y, "reverse");
        
        moveDownward(x, y, "scan");
        moveLeft(x, y, "scan");
        moveUpward(x, y, "scan");
        dfs(cur + 1);
        moveDownward(x, y, "reverse");
        moveLeft(x, y, "reverse");
        moveUpward(x, y, "reverse");
        
        moveUpward(x, y, "scan");
        moveLeft(x, y, "scan");
        moveRight(x, y, "scan");
        dfs(cur + 1);
        moveUpward(x, y, "reverse");
        moveLeft(x, y, "reverse");
        moveRight(x, y, "reverse");
    }
    else {
        moveUpward(x, y, "scan");
        moveLeft(x, y, "scan");
        moveRight(x, y, "scan");
        moveDownward(x, y, "scan");
        dfs(cur + 1);
        moveUpward(x, y, "reverse");
        moveLeft(x, y, "reverse");
        moveRight(x, y, "reverse");
        moveDownward(x, y, "reverse");
    }

}

int main(void) {
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            char tmp; scanf("%c", &tmp);
            if(tmp == ' ' || tmp == '\n') j -=1;
            else {
                grid[i][j] = tmp;
                if(0<tmp-'0' && tmp-'0'<6) {
                    checked[i][j] = CCTV;
                    cctv.push_back({i, j});
                }
                if(tmp == '6') checked[i][j] = WALL;
            }
        }
    }
    
    dfs(0);
    
    printf("%d\n", min_unvisibles);
    
    return 0;
}
