// 그냥 BFS - 시간초과
// 들어가는 inflow 0인 놈들만 BFS - 시간초과

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
    int path[505][505];
    for(int i=0; i<505; ++i){
        for(int j=0; j<505; ++j){
            path[i][j]=0;
        }
    }
    path[0][0]=1;
    set<coordinate> cd; cd.insert({0, 0});
    while(!cd.empty()){
        vector<coordinate> targetToErase;
        for(auto iter=cd.begin(); iter!=cd.end(); ++iter){
            coordinate cur=*iter;
            if(inflow[cur.first][cur.second]==0){
                // 다음것 집어넣는다.
                for(int i=0; i<4; ++i){
                    int x=cur.first+dx[i], y=cur.second+dy[i];
                    if(x<0 || y<0 || x>=M || y>=N) continue;
                    if(grid[cur.first][cur.second]>grid[x][y]){
                        inflow[x][y] -= 1;
                        path[x][y] += path[cur.first][cur.second];
                        if(path[x][y] != 0) cd.insert({x, y});
                    }
                }
                // 지울 항목에 추가한다.
                targetToErase.push_back({cur.first, cur.second});
            }
        }
        for(int i=0; i<targetToErase.size(); ++i){
            cd.erase(targetToErase[i]);
        }
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
