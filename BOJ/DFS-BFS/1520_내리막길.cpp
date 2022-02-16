// 그냥 BFS - 시간초과
// 들어가는 inflow 0인 놈들만 BFS - 시간초과
// 10억 개에 육박하는 경로의 수를 세는 것 -> 각 위치 기준으로 한번씩 셀 수 있도록 바꿀 수 있을까?


#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> coordinate;

int N, M, grid[505][505];
int inflow[505][505];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void calculateInflow(){
    queue<coordinate> tmpQue; tmpQue.push({0, 0});
    set<coordinate> onPath; onPath.insert({0, 0});
    // BFS
    while(!tmpQue.empty()){
        coordinate cur=tmpQue.front(); tmpQue.pop();
        for(int i=0; i<4; ++i){
            int x=cur.first+dx[i], y=cur.second+dy[i];
            if(x<0 || y<0 || x>=M || y>=N) continue;
            if(grid[cur.first][cur.second]>grid[x][y]){
                tmpQue.push({x, y});
                onPath.insert({x, y});
            }
        }
    }
    for(auto iter=onPath.begin(); iter!=onPath.end(); ++iter){
        for(int i=0; i<4; ++i){
            int x=(*iter).first+dx[i], y=(*iter).second+dy[i];
            if(x<0 || y<0 || x>=M || y >= N) continue;
            if(onPath.find({x,y})!=onPath.end() && grid[(*iter).first][(*iter).second]<grid[x][y]){
                inflow[(*iter).first][(*iter).second] += 1;
            }
        }
    }
}

int BFS(){
    
    struct node{
        int x; int y;
        bool operator<(const node &other) const{
            // inflow가 작을수록 먼저 pq 빠져나오도록 고려
            return inflow[x][y] > inflow[other.x][other.y];
        }
    };
    priority_queue<node> pq;
    
    int path[505][505];
    for(int i=0; i<505; ++i){
        for(int j=0; j<505; ++j){
            path[i][j]=0;
            if(inflow[i][j]!=0) pq.push({i, j});
        }
    }
    path[0][0]=1; pq.push({0, 0});
    
    while(!pq.empty()){
        node cur = pq.top();
        for(int i=0; i<4; ++i){
            int nextX=cur.x+dx[i], nextY=cur.y+dy[i];
            if(nextX<0 || nextY<0 || nextX>=M || nextY>=N) continue;
            inflow[nextX][nextY] -= 1;
            path[nextX][nextY] += path[cur.x][cur.y];
        }
        pq.pop();
    }
    
    return path[M-1][N-1];
}

int main(void){
        
    scanf("%d %d", &M, &N);
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    
    // inflow 연산
    calculateInflow();
    
    printf("%d\n", BFS());
    
    return 0;
}
