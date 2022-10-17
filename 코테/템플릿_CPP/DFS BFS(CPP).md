# DFS / BFS

## DFS

```cpp
#include <iostream>
#include <vector>
#define MAX_LEN 1003
using namespace std;

vector<int> graph[MAX_LEN];
bool visited[MAX_LEN];

void dfs(int cur) {
    visited[cur] = true;
    for(int i=0; i<graph[cur].size(); ++i) {
        int next = graph[cur][i];
        if(!visited[next])
            dfs(next);
    }
}

```

## BFS

```cpp
#include <iostream>
#include <queue>
#define MAX_LEN 1003
using namespace std;

vector<int> graph[MAX_LEN];
queue<int> q;
bool visited[MAX_LEN];

void bfs(int cur) {
    
    visited[cur] = true;
    q.push(cur);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if(visited[cur]) continue;
    
        for(int i=0; i<graph[cur].size(); ++i) {
            int next = graph[cur][i];
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

```
