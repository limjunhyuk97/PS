#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> Point;

struct Edge{
    int start;
    int end;
    int weight;
    bool operator<(const Edge& other) const{
        return weight > other.weight;
    }
};

int N, M, groupCount;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int grid[11][11];
Point gridParent[11][11];
int groupParent[103];

vector<Point> cGroup[103];
map<Point, int> pGroup;
priority_queue<Edge> Edges;

Point Find(Point p){
    
    Point root = p;
    for(; gridParent[root.first][root.second].first >= 0; root = gridParent[root.first][root.second]);
    
    while(root != p){
        Point tmp = gridParent[p.first][p.second];
        gridParent[p.first][p.second] = root;
        p = tmp;
    }
    
    return root;
    
}

void Union(const Point& p1, const Point& p2){
    
    Point p1root = Find(p1);
    Point p2root = Find(p2);
    int tmp = gridParent[p1root.first][p1root.second].first + gridParent[p2root.first][p2root.second].first;
    
    if(p1root != p2root){
        if(gridParent[p1root.first][p1root.second].first > gridParent[p2root.first][p2root.second].first){
            gridParent[p1root.first][p1root.second] = p2root;
            gridParent[p2root.first][p2root.second].first = tmp;
        }
        else{
            gridParent[p2root.first][p2root.second] = p1root;
            gridParent[p1root.first][p1root.second].first = tmp;
        }
    }
    
}

int Find(int n){
    if(groupParent[n] < 0) return n;
    else return groupParent[n] = Find(groupParent[n]);
}

void Union(int n, int m){
    int nroot = Find(n);
    int mroot = Find(m);
    int tmp = groupParent[nroot] + groupParent[mroot];
    if(nroot != mroot){
        if(groupParent[nroot] > groupParent[mroot]){
            groupParent[nroot] = mroot;
            groupParent[mroot] = tmp;
        }
        else{
            groupParent[mroot] = nroot;
            groupParent[nroot] = tmp;
        }
    }
}

int Kruskal(){
    
    int ret = 0;
    
    while(!Edges.empty()){
        Edge edge = Edges.top(); Edges.pop();
        int sroot = Find(edge.start);
        int eroot = Find(edge.end);
        if(sroot != eroot){
            Union(sroot, eroot);
            ret += edge.weight;
        }
    }
    
    return ret;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<11; ++i){
        for(int j=0; j< 11; ++j){
            gridParent[i][j].first = -1;
            gridParent[i][j].second = -1;
        }
    }
    
    for(int i=0; i<103; ++i)
        groupParent[i] = -1;
    
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin >> grid[i][j];
        }
    }
    
    // 각 섬들을 한 덩어리로 묶어주는 작업
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(grid[i][j] == 1){
                for(int k=0; k<4; ++k){
                    if(0 <= ( i + dx[k] ) && ( i + dx[k] ) < N && 0<= (j + dy[k]) && (j + dy[k]) < M && grid[i + dx[k]][j + dy[k]] == 1)
                        Union({i, j}, {i + dx[k], j + dy[k]});
                }
            }
        }
    }
    
    // gridParent 정리
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j)
            if(grid[i][j] == 1) Find({i, j});
    }
    
    // 각 섬의 대표 위치를 pGroup에 넣는다
    int cnt = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(grid[i][j] == 1 && gridParent[i][j].first <= -1){
                pGroup[{i, j}] = cnt++;
                gridParent[i][j] = {i , j};
            }
        }
    }
    groupCount = (int)pGroup.size();
    
    // 섬의 각 위치정보를 cGroup에 넣는다
    for(int i=0; i<N; ++i){
        for(int j=0; j< M; ++j){
            if(grid[i][j] == 1){
                cGroup[pGroup[gridParent[i][j]]].push_back({i, j});
            }
        }
    }
    
    // 섬 사이의 edge 생성
    // cGroup의 각 지점에서 뻗어나가는 것을 구현해야 함
    for(int i=0; i<groupCount; ++i){
        for(int j=0; j<cGroup[i].size(); ++j){
            int x = cGroup[i][j].first;
            int y = cGroup[i][j].second;
            
            // 위로
            cnt = 0;
            while(--x >= 0 && gridParent[x][y] != gridParent[cGroup[i][j].first][cGroup[i][j].second]){
                ++cnt;
                if(grid[x][y] == 1){
                    if(cnt == 2 ) break;
                    else{
                        Edges.push({i, pGroup[gridParent[x][y]], cGroup[i][j].first - x - 1});
                        break;
                    }
                }
            }
            
            // 아래로
            cnt = 0; x = cGroup[i][j].first; y = cGroup[i][j].second;
            while(++x < N && gridParent[x][y] != gridParent[cGroup[i][j].first][cGroup[i][j].second]){
                ++cnt;
                if(grid[x][y] == 1){
                    if(cnt == 2 ) break;
                    else{
                        Edges.push({i, pGroup[gridParent[x][y]], x - cGroup[i][j].first- 1});
                        break;
                    }
                }
            }
            
            // 왼쪽으로
            cnt = 0; x = cGroup[i][j].first; y = cGroup[i][j].second;
            while(--y >= 0 && gridParent[x][y] != gridParent[cGroup[i][j].first][cGroup[i][j].second]){
                ++cnt;
                if(grid[x][y] == 1){
                    if(cnt == 2) break;
                    else{
                        Edges.push({i, pGroup[gridParent[x][y]], cGroup[i][j].second - y - 1});
                        break;
                    }
                }
            }
            
            // 오른쪽으로
            cnt = 0; x = cGroup[i][j].first; y = cGroup[i][j].second;
            while(++y < M && gridParent[x][y] != gridParent[cGroup[i][j].first][cGroup[i][j].second]){
                ++cnt;
                if(grid[x][y] == 1){
                    if(cnt == 2) break;
                    else{
                        Edges.push({i, pGroup[gridParent[x][y]], y - cGroup[i][j].second - 1});
                        break;
                    }
                }
            }
        }
    }
    
    
    int ans = Kruskal();
    cnt = 0;
    for(int i=0; i<groupCount; ++i)
        if(groupParent[i] < 0) cnt++;
    
    if(cnt >=2) cout<< -1 << "\n";
    else cout << ans << "\n";
    
    
    return 0;
}
