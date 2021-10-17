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

typedef long long int ll;

int weight[1005][1005];
int N, M, v1, v2, w, dist;
bool checked[1005];

vector<int> tree[1005];
deque<int> path;

bool DFS(int n){
    checked[n] = true;
    path.push_back(n);
    for(int i=0; i<tree[n].size(); ++i){
        if(tree[n][i] == v2){
            path.push_back(v2); return true;
        }
        else{
            if(!checked[tree[n][i]]){
                if(DFS(tree[n][i])) return true;
            }
        }
    }
    path.pop_back();
    return false;
}

// 그래프가 아니라 tree 상의 거리
// tree 상의 거리이므로, graph처럼 shortest 같은게 없다.
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N - 1; ++i){
        cin >> v1 >> v2 >> w;
        weight[v1][v2] = w; weight[v2][v1] = w;
        tree[v1].push_back(v2); tree[v2].push_back(v1);
    }
    
    for(int i=0; i<M; ++i){
        cin >> v1 >> v2;
        dist = 0;
        for(int j=0; j<1005; ++j){
            checked[j] = false;
        }
        DFS(v1);
        for(int j=0; j<path.size()-1; ++j){
            dist += weight[path[j]][path[j+1]];
        }
        cout << dist << '\n';
        path.clear();
    }
    
    return 0;
}
