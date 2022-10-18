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
    
    // [조심!] queue에 들어가는 순간 true 처리! -> queue에서 꺼내 보는 것들은 중복되어 봐지지 않는다.
    visited[cur] = true;
    q.push(cur);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
    
        // [조심!] 마찬가지로 queue에 들어가는 순간 true 처리! 
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
