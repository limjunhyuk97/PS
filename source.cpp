#include <iostream>
#include <list>
#include <set>
#define MAXLEN 15
using namespace std;

typedef pair<int, int> seed;

int N, M, K;
int grid[MAXLEN][MAXLEN];
int A[MAXLEN][MAXLEN];

set<seed> seeds;
list<int> trees[MAXLEN][MAXLEN];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {0, 1, -1, 1, -1, 0, 1, -1};

void initGrid() {
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            grid[i][j] = 5;
        }
    }
}

bool OOB(int x, int y) {
    if(x < 1 || x > N || y < 1 || y > N) return true;
    else return false;
}

void spring_summer() {
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(trees[i][j].empty()) continue;
            list<int>::iterator point;
            
            bool flag = false;
            int deads = 0;
            
            // 봄의 연산
            for(auto iter = trees[i][j].begin(); iter != trees[i][j].end(); ++iter) {
                if(grid[i][j] >= *iter) {
                    grid[i][j] -= *iter;
                    *iter += 1;
                    if(*iter % 5 == 0) {
                        for(int k=0; k<8; ++k) {
                            int nx = i + dx[k], ny = j + dy[k];
                            if(OOB(nx, ny)) continue;
                            trees[nx][ny].push_front(1);
                        }
                    }
                } else {
                    if(!flag) {
                        point = iter;
                        flag = true;
                    }
                    deads += *iter / 2;
                }
            }
            
            // 죽은 놈들 지우기
            if(flag) trees[i][j].erase(point, trees[i][j].end());
            
            // 여름에 양분으로 된다
            grid[i][j] += deads;
            
            grid[i][j] += A[i][j];
        }
    }
}

void fall() {
    for(auto seed : seeds){
        for(auto tree : trees[seed.first][seed.second]) {
            if(tree % 5 != 0) continue;
            for(int k=0; k<8; ++k) {
                int nx = seed.first + dx[k], ny = seed.second + dy[k];
                if(OOB(nx, ny)) continue;
                trees[nx][ny].push_front(1);
            }
        }
    }
    seeds.clear();
}


int countTrees() {
    int cnt = 0;
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            cnt += (int)trees[i][j].size();
        }
    }
    return cnt;
}

int main(void) {
    
    scanf("%d %d %d", &N, &M, &K);
    
    initGrid();

    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    
    for(int i=0; i<M; ++i) {
        int x, y, age; scanf("%d %d %d", &x, &y, &age);
        trees[x][y].push_back(age);
    }
    
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            trees[i][j].sort();
        }
    }
    
    for(int i=0; i<K; ++i) {
        spring_summer();
        fall();

    }
    
    printf("%d\n", countTrees());
    
    return 0;
}
