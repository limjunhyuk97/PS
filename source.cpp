#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define MAXLEN 15
using namespace std;

int N, M, K;

int aid[MAXLEN][MAXLEN];
deque<int> trees[MAXLEN][MAXLEN];
int A[MAXLEN][MAXLEN];
int addTreeCnt[MAXLEN][MAXLEN];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};

void initAid() {
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            aid[i][j] = 5;
        }
    }
}

void plantTree() {
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            for(int k=0; k<addTreeCnt[i][j]; ++k) {
                trees[i][j].push_front(1);
            }
            addTreeCnt[i][j] = 0;
        }
    }
}

void cycle() {
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            int alive = 0;
            // 봄
            for(deque<int>::iterator iter = trees[i][j].begin(); iter != trees[i][j].end(); ++iter) {
                if(aid[i][j] >= *iter) {
                    ++alive;
                    aid[i][j] -= *iter;
                    *iter += 1;
                    if(*iter % 5 == 0) {
                        for(int k=0; k<8; ++k) {
                            int nx = i + dx[k], ny = j + dy[k];
                            addTreeCnt[nx][ny] += 1;
                        }
                    }
                } else break;
            }
            // 여름
            int dead = (int)trees[i][j].size() - alive;
            while(dead--) {
                aid[i][j] += trees[i][j].back() / 2;
                trees[i][j].pop_back();
            }
            // 겨울
            aid[i][j] += A[i][j];
        }
    }
}

void sortTrees() {
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            sort(trees[i][j].begin(), trees[i][j].end());
        }
    }
}

int getTreeCnt() {
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
    
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    
    for(int i=0; i<M; ++i) {
        int x, y, age; scanf("%d %d %d", &x, &y, &age);
        trees[x][y].push_back(age);
    }
    
    initAid();
    sortTrees();
    
    for(int i=0; i<K; ++i) {
        cycle();
        plantTree();
    }
    
    printf("%d\n", getTreeCnt());
    
    return 0;
}
