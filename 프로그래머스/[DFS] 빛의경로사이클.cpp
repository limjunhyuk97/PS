#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int>  XY;

XY path[505][505][4];
bool passed[505][505][4];

vector<int> answer;

// out 따라서 in 찾아주기
int ConvertIn(char direction, int in) {
    if(direction == 'S') {
        if(in == 0) return 7;
        if(in == 2) return 5;
        if(in == 4) return 3;
        if(in == 6) return 1;
    }
    if(direction == 'L') {
        if(in == 0) return 5;
        if(in == 2) return 3;
        if(in == 4) return 1;
        if(in == 6) return 7;
    }
    if(direction == 'R') {
        if(in == 0) return 1;
        if(in == 2) return 7;
        if(in == 4) return 5;
        if(in == 6) return 3;
    }
    return 0;
}

// DFS
void DFS(int fromX, int fromY, int out, int len, const vector<string> & grid) {
    int in = 7 - out;
    int curX = path[fromX][fromY][(out-1)/2].first;
    int curY = path[fromX][fromY][(out-1)/2].second;
    int nextOut = ConvertIn(grid[curX][curY], in);
    
    if(passed[curX][curY][(nextOut-1)/2]) {
        answer.push_back(len);
    }
    else {
        passed[curX][curY][(nextOut-1)/2] = true;
        DFS(curX, curY, nextOut, len+1, grid);
    }
    return;
}

vector<int> solution(vector<string> grid) {
    
    int N = (int)grid.size();
    int M = (int)grid[0].size();
    
    // 경로 배열 path 생성
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            path[i][j][0] = {i-1 >= 0 ? i-1 : N-1, j};
            path[i][j][1] = {i, j+1 > M-1 ? 0 : j+1};
            path[i][j][2] = {i+1 > N-1 ? 0 : i+1, j};
            path[i][j][3] = {i, j-1 >= 0 ? j-1 : M-1};
        }
    }
    
    // DFS 돌리기
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            for(int k=0; k<4; ++k) {
                if(!passed[i][j][k]) {
                    DFS(i, j, 2*k+1, 0, grid);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
