// 벨만포드의 사이클 탐색 원리를 이용하여 구함.
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define INF 2000000000
#define MAXLEN 60
using namespace std;

typedef pair<int, int> cord;

int N, M;
int grid[MAXLEN][MAXLEN];
int dist[MAXLEN][MAXLEN];

bool OOB(int x, int y) {
    if(x < 0 || x >=N || y < 0 || y >=M) return true;
    else return false;
}

// 사이클 탐지 로직을 위해 벨만포드의 원리를 사용
int Search() {
    // dist 초기화
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            dist[i][j] = -1;
        }
    }
    
    priority_queue<cord, vector<cord> > pq;
    pq.push({0, 0});
    dist[0][0] = 0;
    
    int nodes = N * M;
    bool changed = false;
    
    // 노드의 수만큼 순회. N번째 순회 일어나면 사이클 존재.
    for(int i=0; i<nodes; ++i) {
        changed = false;
        
        // 노드의 수만큼 순회하면서 갱신
        for(int x=0; x<N; ++x) {
            for(int y=0; y<M; ++y) {
                if(dist[x][y] == -1) continue;
                if(grid[x][y] == 'H'-'0') continue;
                if(!OOB(x+grid[x][y], y) && (dist[x+grid[x][y]][y] < dist[x][y] + 1)) {
                    dist[x+grid[x][y]][y] = dist[x][y] + 1;
                    changed = true;
                }
                if(!OOB(x, y+grid[x][y]) && (dist[x][y+grid[x][y]] < dist[x][y] + 1)) {
                    dist[x][y+grid[x][y]] = dist[x][y] + 1;
                    changed = true;
                }
                if(!OOB(x-grid[x][y], y) && (dist[x-grid[x][y]][y] < dist[x][y] + 1)) {
                    dist[x-grid[x][y]][y] = dist[x][y] + 1;
                    changed = true;
                }
                if(!OOB(x, y-grid[x][y]) && (dist[x][y-grid[x][y]] < dist[x][y] + 1)) {
                    dist[x][y-grid[x][y]] = dist[x][y] + 1;
                    changed = true;
                }
            }
        }
        
        if(!changed) break;
    }
    
    if(changed) return -1;
    else {
        int answer = -1;
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                answer = max(answer, grid[i][j] != 'H'-'0' ? dist[i][j] + 1 : dist[i][j]);
            }
        }
        return answer;
    }
}

int main(void) {
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i) {
        string tmp; cin >> tmp;
        for(int j=0; j<M; ++j) {
            grid[i][j] = tmp[j] - '0';
        }
    }
    
    printf("%d\n", Search());
    
    return 0;
}
