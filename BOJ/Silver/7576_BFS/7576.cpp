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

int M, N, cnt;
int grid[1004][1004];
queue< pair<int,int> > ripe;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void BFS(){
    
    while(!ripe.empty()){
        int size = ripe.size();
        ++cnt;
        for(int i=0; i<size; ++i){
            pair<int, int> cur = ripe.front();
            ripe.pop();
            for(int j=0; j<4; ++j){
                if(cur.first + dx[j] <0 || cur.second + dy[j] <0 || cur.first + dx[j] >= N || cur.second + dy[j] >= M) continue;
                if(grid[cur.first + dx[j]][cur.second + dy[j]] == 0){
                    grid[cur.first + dx[j]][cur.second + dy[j]] = 1;
                    ripe.push({cur.first + dx[j], cur.second + dy[j]});
                }
            }
        }
    }
    
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin >> grid[i][j];
            if(grid[i][j] == 1) ripe.push({i, j});
        }
    }
    
    BFS();
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(grid[i][j] == 0){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    
    cout << cnt - 1 << endl;
    
    return 0;
}
