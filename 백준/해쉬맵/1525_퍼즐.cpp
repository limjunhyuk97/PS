#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

set<string> history;
queue<string> que;
string status = "";
const string target = "123456780";

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int grid[3][3];

// grid 상태를 status로 변경한다.
string get_status() {
    string status = "";
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            status += to_string(grid[i][j]);
        }
    }
    return status;
}

// grid를 벗어날 경우 확인한다.
bool OOB(int x, int y) {
    if(x < 0 || x > 2 || y < 0 || y > 2) return true;
    else return false;
}

// status 정보를 int [3][3] 짜리 그리드에 옮길때 사용한다.
void insert_grid(const string &status) {
    for(int i=0; i<status.size(); ++i) {
        grid[i/3][i%3] = status[i] - '0';
    }
}

// grid내 값 위치 이동시킬때 사용한다.
void switch_grid(int x1, int y1, int x2, int y2) {
    int tmp = grid[x1][y1];
    grid[x1][y1] = grid[x2][y2];
    grid[x2][y2] = tmp;
}

// grid에서 0 주위로 옮겨가면서 que에 넣는다.
void move_grid() {
    int x0 = 0, y0 = 0;
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            if(grid[i][j] == 0) {
                x0 = i; y0 = j; break;
            }
        }
    }
    int px, py;
    for(int i=0; i<4; ++i) {
        px = x0 + dx[i];
        py = y0 + dy[i];
        if(OOB(px, py)) continue;
        switch_grid(x0, y0, px, py);
        string tmp = get_status();
        if(history.find(tmp) == history.end()) {
            history.insert(tmp);
            que.push(tmp);
        }
        switch_grid(x0, y0, px, py);
    }
}

int main(void) {
    
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            int tmp; scanf("%d", &tmp);
            grid[i][j] = tmp;
            status += to_string(tmp);
        }
    }
    
    history.insert(status);
    que.push(status);
    
    string cur; int cnt = 0; bool flag = false;
    // 모든 조건을 다 탐색하여 queue에 넣는다.
    // 이미 탐색한 적이 있는 상태라면 set에 넣는다.
    while(!que.empty()) {
        int que_length = (int)que.size();
        cnt += 1;
        for(int i=0; i<que_length; ++i) {
            cur = que.front(); que.pop();
            if(cur == target) {
                flag = true;
                break;
            }
            insert_grid(cur);
            move_grid();
        }
        if(flag) break;
    }
    
    cout << (flag ? cnt - 1 : -1) << endl;
    
    return 0;
}
