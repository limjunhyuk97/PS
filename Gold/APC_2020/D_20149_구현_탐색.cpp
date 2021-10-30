// 재귀적 구현
// 경로를 일단 구한다 -> 경로 속에서 오른쪽 왼쪽을 변환하여 도달가능한 것인지 또 확인한다.

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
#include <array>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef pair<int, int> loc;
typedef long long int ll;

int R, C, K;
char grid[55][55];

set<loc> initialpath;

// 1 : 왼쪽, 0 : 오른쪽
void change_word(int i, int j, int lr){
    
    // 왼쪽 - 반시계
    if(lr){
        if(grid[i][j] == 'L') grid[i][j] = 'D';
        else if(grid[i][j] == 'R') grid[i][j] = 'U';
        else if(grid[i][j] == 'U') grid[i][j] = 'L';
        else grid[i][j] = 'R';
    }
    /// 오른쪽 - 시계
    else{
        if(grid[i][j] == 'L') grid[i][j] = 'U';
        else if(grid[i][j] == 'R') grid[i][j] = 'D';
        else if(grid[i][j] == 'U') grid[i][j] = 'R';
        else grid[i][j] = 'L';
    }
}

// U, D, L, R
map<char, int> dmove;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool path_search(set<loc> & path){
    
    int i = 0, j = 0;
    path.insert({0, 0});
    while(1){
        loc tmp = {i, j};
        i += dx[dmove[grid[tmp.first][tmp.second]]];
        j += dy[dmove[grid[tmp.first][tmp.second]]];
        if(i<0 || j<0 || i>=R || j>=C) break;
        if(i == R-1 && j == C-1) return true;
        if(path.find({i, j}) != path.end()) break;
        path.insert({i, j});
    }
    
    return false;
}

bool change_path(int i, int j, int cnt, int click){
    
    if(cnt == 0) return false;
    set<loc> path;
    
    // 반시계
    if(click == -1 || click == 0){
        change_word(i, j, 1);
        if(path_search(path)) return true;
        for(auto iter = path.begin(); iter != path.end(); ++iter){
            if((*iter).first == i && (*iter).second == j) continue;
            if(change_path((*iter).first, (*iter).second, cnt-1, 1)) return true;
        }
        change_word(i, j, 0);
    }
    
    // 시계
    path.clear();
    if(click == 1 || click == -1){
        change_word(i, j, 0);
        if(path_search(path)) return true;
        for(auto iter = path.begin(); iter != path.end(); ++iter){
            if((*iter).first == i && (*iter).second == j) continue;
            if(change_path((*iter).first, (*iter).second, cnt-1, 0)) return true;
        }
        change_word(i, j, 1);
    }
    
    return false;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dmove.insert({'U', 0}); dmove.insert({'D', 1}); dmove.insert({'L', 2}); dmove.insert({'R', 3});
    cin >> R >> C >> K;
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            cin >> grid[i][j];
        }
    }
    
    // 먼저 그냥 두었을 때 어떤 경로를 통해서 가는지 확인 + 한번에 도착하면 바꿀 필요가 X
    if (path_search(initialpath)){
        cout << "Yes\n";
        return 0;
    }
    
    if(K == 0){
        cout << "No\n";
        return 0;
    }
    
    // 경로 상에 존재하는 문자를 변경 + 가능하다면 Yes
    for(auto iter = initialpath.begin(); iter != initialpath.end(); ++iter){
        if(change_path((*iter).first, (*iter).second, 2, -1)){
            cout << "Yes\n";
            return 0;
        }
    }
            
    cout << "No\n";

    return 0;
}

