// 좌,우,위,아래에 대한 압축을 어떻게 구현할 것인가?

#include <iostream>
#include <vector>
#define MAXLEN 25
using namespace std;

int N;
int maxValue = -1;

// grid에서 가장 큰 값 추출
int getMaxValue(int grid[][MAXLEN]) {
    int maxValue = -1;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(maxValue < grid[i][j])
                maxValue = grid[i][j];
        }
    }
    return maxValue;
}

// 특정 방향으로 그리드 값 압축 (중복 값 연산 + 밀어붙이기)
void pressLeft(int grid[][MAXLEN]) {
    vector<int> tmp, pushed;
    for(int i=0; i<N; ++i) {
        tmp.clear(); pushed.clear();
        for(int j=0; j<N; ++j) {
            if(grid[i][j]) tmp.push_back(grid[i][j]);
        }
        if(!tmp.empty()) {
            int size = (int)tmp.size();
            pushed.push_back(tmp[0]);
            vector<bool> pressed(tmp.size(), false);
            for(int j=1; j<size; ++j) {
                if(tmp[j] == tmp[j-1] && !pressed[j-1]) {
                    pressed[j] = true;
                    pushed.pop_back();
                    pushed.push_back(tmp[j]*2);
                }
                else {
                    pushed.push_back(tmp[j]);
                }
            }
            for(int j=0; j<N; ++j) {
                if(j < pushed.size()) grid[i][j] = pushed[j];
                else grid[i][j] = 0;
            }
        }
    }
}

void pressRight(int grid[][MAXLEN]) {
    vector<int> tmp, pushed;
    for(int i=0; i<N; ++i) {
        tmp.clear(); pushed.clear();
        for(int j=0; j<N; ++j) {
            if(grid[i][j]) tmp.push_back(grid[i][j]);
        }
        if(!tmp.empty()) {
            int size = (int)tmp.size();
            pushed.push_back(tmp[size-1]);
            vector<bool> pressed(tmp.size(), false);
            for(int j=size-2; j>=0; --j) {
                if(tmp[j] == tmp[j+1] && !pressed[j+1]) {
                    pushed.pop_back();
                    pushed.push_back(tmp[j]*2);
                    pressed[j] = true;
                }
                else {
                    pushed.push_back(tmp[j]);
                }
            }
            size = (int)pushed.size();
            for(int j=N-1, k=0; j>=0; --j, ++k) {
                if(k < size) grid[i][j] = pushed[k];
                else grid[i][j] = 0;
            }
        }
    }
}

void pressDown(int grid[][MAXLEN]) {
    vector<int> tmp, pushed;
    for(int j=0; j<N; ++j) {
        tmp.clear(); pushed.clear();
        for(int i=0; i<N; ++i) {
            if(grid[i][j]) tmp.push_back(grid[i][j]);
        }
        if(!tmp.empty()) {
            int size = (int)tmp.size();
            pushed.push_back(tmp[size-1]);
            vector<bool> pressed(tmp.size(), false);
            for(int i=size-2; i>=0; --i) {
                if(tmp[i] == tmp[i+1] && !pressed[i+1]) {
                    pushed.pop_back();
                    pushed.push_back(tmp[i]*2);
                    pressed[i] = true;
                }
                else {
                    pushed.push_back(tmp[i]);
                }
            }
            size = (int)pushed.size();
            for(int i=N-1, k=0; i>=0; --i, ++k) {
                if(k<size) grid[i][j] = pushed[k];
                else grid[i][j] = 0;
            }
        }
    }
}

void pressUp(int grid[][MAXLEN]) {
    vector<int> tmp, pushed;
    for(int j=0; j<N; ++j) {
        tmp.clear(); pushed.clear();
        for(int i=0; i<N; ++i) {
            if(grid[i][j]) tmp.push_back(grid[i][j]);
        }
        if(!tmp.empty()) {
            int size = (int)tmp.size();
            pushed.push_back(tmp[0]);
            vector<bool> pressed(tmp.size(), false);
            for(int i=1; i<size; ++i) {
                if(tmp[i] == tmp[i-1] && !pressed[i-1]) {
                    pushed.pop_back();
                    pushed.push_back(tmp[i]*2);
                    pressed[i] = true;
                }
                else {
                    pushed.push_back(tmp[i]);
                }
            }
            for(int i=0; i<N; ++i) {
                if(i < pushed.size()) grid[i][j] = pushed[i];
                else grid[i][j] = 0;
            }
        }
    }
}

void initGrid(int grid[][MAXLEN], int tmp[][MAXLEN]) {
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            tmp[i][j] = grid[i][j];
        }
    }
}

void dfs(int cnt, int grid[][MAXLEN]) {
    if(cnt == 5) {
        int curMaxValue = getMaxValue(grid);
        maxValue = maxValue > curMaxValue ? maxValue : curMaxValue;
        return;
    }
    
    int tmp[MAXLEN][MAXLEN];
    initGrid(grid, tmp);
    pressLeft(tmp);
    dfs(cnt+1, tmp);
    
    initGrid(grid, tmp);
    pressUp(tmp);
    dfs(cnt+1, tmp);
    
    initGrid(grid, tmp);
    pressDown(tmp);
    dfs(cnt+1, tmp);
    
    initGrid(grid, tmp);
    pressRight(tmp);
    dfs(cnt+1, tmp);
    
}

int main(void) {
    
    int grid[MAXLEN][MAXLEN];
    
    cin >> N;
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> grid[i][j];
        }
    }
    
    dfs(0, grid);
    
    cout << maxValue << endl;
    
    return 0;
}
