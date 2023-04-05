#include <iostream>
#include <deque>
#define MAXLEN 55
#define INF 5000000
using namespace std;

typedef pair<int, int> co;

// vc는 2의 갯수
int N, M, vc;
int grid[MAXLEN][MAXLEN];

// visited 각 항목
bool visited[MAXLEN][MAXLEN];

co viruses[15];
bool picked[15];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

int total_tick = INF;
int remainer;

bool OOB(int x, int y) {
    if(x<0 || x>=N || y<0 || y>=N) return true;
    else return false;
}

void initVisited() {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(grid[i][j] == 1) visited[i][j] = true;
            else visited[i][j] = false;
        }
    }
}

void bfs() {
    
    initVisited();
    
    deque<co> que;
    int remainer_copy = remainer;
    
    for(int i=0; i<vc; ++i) {
        if(picked[i]) {
            que.push_back(viruses[i]);
            visited[viruses[i].first][viruses[i].second] = true;
        }
    }
    
    if(remainer_copy == 0) {
        total_tick = 0;
        return;
    }
    
    int tick = 0;
    bool is_all_virus = false;
    
    while(!que.empty()) {
        int size = (int)que.size();
        
        is_all_virus = true;
        if(tick > total_tick) break;
        
        size = (int)que.size();
        for(int i=0; i<size; ++i) {
            co cur = que.front(); que.pop_front();
            
            if(grid[cur.first][cur.second] != 2) is_all_virus = false;
            
            for(int j=0; j<4; ++j) {
                int nx = cur.first + dx[j], ny = cur.second + dy[j];
                if(OOB(nx, ny)) continue;
                if(visited[nx][ny]) continue;
                
                // 일단 다음 것 추가
                que.push_back({nx, ny});
                visited[nx][ny] = true;
                
                // remainer 갯수 빼기
                if(grid[nx][ny] != 2) remainer_copy -= 1;
            }
        }
        
        tick += 1;
        
        if(remainer_copy == 0) {
            total_tick = total_tick > tick ? tick : total_tick;
            break;
        }
    
    }
    
    
}

void dfs(int virus, int cnt) {
    if(cnt == M) {
        bfs();
        return;
    }
    
    for(int i=virus; i<vc; ++i) {
        picked[i] = true;
        dfs(i+1, cnt+1);
        picked[i] = false;
    }
}

int main(void) {
    
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            scanf("%d", &grid[i][j]);
            if(grid[i][j] == 2) viruses[vc++] = {i, j};
            if(grid[i][j] == 0) remainer += 1;
        }
    }
    
    dfs(0, 0);
    
    printf("%d\n", total_tick == INF ? -1 : total_tick);
    
    return 0;
}
