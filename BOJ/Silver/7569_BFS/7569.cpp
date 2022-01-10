#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;
struct point{
    int x;
    int y;
    int z;
};

int M, N, H, cnt;
int grid[104][104][104];
queue<point> ripe;

const int dx[6] = {-1, 1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};

void BFS(){
    
    while(!ripe.empty()){
        int size = ripe.size();
        ++cnt;
        for(int i=0; i<size; ++i){
            point cur = ripe.front();
            ripe.pop();
            for(int j=0; j<6; ++j){
                if(cur.x + dx[j] <0 || cur.y + dy[j] <0 || cur.z + dz[j] < 0 || cur.x + dx[j] >= N || cur.y + dy[j] >= M || cur.z + dz[j] >= H) continue;
                if(grid[cur.z + dz[j]][cur.x + dx[j]][cur.y + dy[j]] == 0){
                    grid[cur.z + dz[j]][cur.x + dx[j]][cur.y + dy[j]] = 1;
                    ripe.push({cur.x + dx[j], cur.y + dy[j], cur.z + dz[j]});
                }
            }
        }
    }
    
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> N >> H;
    for(int k=0; k< H; ++k){
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                cin >> grid[k][i][j];
                if(grid[k][i][j] == 1) ripe.push({i, j, k});
            }
        }
    }
    
    BFS();
    
    for(int k=0; k<H; ++k){
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(grid[k][i][j] == 0){
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    
    cout << cnt - 1 << endl;
    
    return 0;
}
