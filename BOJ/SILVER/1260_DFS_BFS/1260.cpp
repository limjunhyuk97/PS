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

int N, M, V;
vector<int> edges[1005];
bool vertices[1005];

void DFS(int n){
    
    vector<int> pick;
    pick.push_back(n);
    
    while(!pick.empty()){
        int cur = pick.back();
        pick.pop_back();
        
        if(!vertices[cur]){
            cout << cur << " ";
            vertices[cur] = true;
        }
        
        for(int i=0; i<edges[cur].size(); ++i){
            if(!vertices[edges[cur][i]]){
                pick.push_back(edges[cur][i]);
            }
        }
    }
    cout << '\n';
    
}

void BFS(int n){
    
    queue<int> pick;
    pick.push(n);
    
    while(!pick.empty()){
        int cur = pick.front();
        pick.pop();
        
        if(!vertices[cur]){
            cout << cur << " ";
            vertices[cur] = true;
        }
        
        for(int i=0; i<edges[cur].size(); ++i){
            if(!vertices[edges[cur][i]]){
                pick.push(edges[cur][i]);
            }
        }
    }
    
    cout << '\n';
    
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> V;
    
    for(int i=0; i<M; ++i){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    for(int i=0; i<1005; ++i){
        if(!edges[i].empty())
            sort(edges[i].begin(), edges[i].end(), greater<>());
    }
    DFS(V);
    
    for(int i=0; i<1005; ++i)
        vertices[i] = false;
    for(int i=0; i<1005; ++i){
        if(!edges[i].empty())
            sort(edges[i].begin(), edges[i].end(), less<>());
    }
    BFS(V);
    
    return 0;
}

