// DFS

#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#define MAXLEN 55
using namespace std;

typedef pair<int, int> co;

int N, L, R;
int grid[MAXLEN][MAXLEN];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

bool visited[MAXLEN][MAXLEN];

bool OOB(co node) {
    if(node.first < 0 || node.second < 0 || node.first >=N || node.second >=N) return true;
    else return false;
}

bool getGap(const co & c1, const co & c2) {
    int gap = abs(grid[c1.first][c1.second]-grid[c2.first][c2.second]);
    return (L<=gap) && (gap <=R);
}

void initVisited() {
    for(int i=0; i<MAXLEN; ++i) {
        for(int j=0; j<MAXLEN; ++j) {
            visited[i][j] = false;
        }
    }
}

bool bfs(int x, int y) {
    queue<co> que;
    vector<co> nodes;
    
    que.push({x, y});
    nodes.push_back({x, y});
    visited[x][y] = true;
    
    bool flag = false;
    int people = grid[x][y];
    
    while(!que.empty()) {
        co cur = que.front(); que.pop();
        for(int i=0; i<4; ++i) {
            co next = {cur.first + dx[i], cur.second + dy[i]};
            
            if(OOB(next) || visited[next.first][next.second]) continue;
            if(!getGap(cur, next)) continue;
            
            visited[next.first][next.second] = true;
            people += grid[next.first][next.second];
            
            nodes.push_back(next);
            que.push(next);
            flag = true;
        }
    }
    
    for(auto node : nodes) {
        grid[node.first][node.second] = (int) (people / nodes.size());
    }
    
    return flag;
}

int main(void) {
    
    scanf("%d %d %d", &N, &L, &R);
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    int moved = 0;
    bool move_flag = false;
    while(true) {
        move_flag = false;
        initVisited();
        
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                if(visited[i][j]) continue;
                if(bfs(i, j)) move_flag = true;
            }
        }
        
        if(!move_flag) break;
        else moved += 1;
    }
    
    printf("%d\n", moved);
    
    return 0;
}
