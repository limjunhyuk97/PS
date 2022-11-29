# DFS / BFS

## DFS

### 유형별 접근

- 정점 ~ 정점을 깊이 우선적으로 탐색하여 거리를 구할 때
    - 2644_촌수계산
    - 1189_컴백홈
- 사이클 판별
    - 1103_게임

```cpp
#include <iostream>
#include <vector>
#define MAX_LEN 1003
using namespace std;

vector<int> graph[MAX_LEN];
bool visited[MAX_LEN];

void dfs(int cur) {
    // [조심!] stack에 들어가는 순간 true 처리!
    visited[cur] = true;
    
    for(int i=0; i<graph[cur].size(); ++i) {
        int next = graph[cur][i];
        if(!visited[next])
            dfs(next);
    }
}

```

## BFS

### 유형별 접근

- 거리순으로 노드들을 방문하는 특성을 이용한다.
- Flood Fill 타입의 문제
- 시작점이 여러 개인 경우
    - 1697_숨바꼭질
- 시작점이 여러 타입인 경우
    - 4129_불!
- 1차원 배열에서의 BFS (1차원 배열에서 이동할 때 가장 빠른 도달은?)
    - 1326_폴짝폴짝

```cpp
#include <iostream>
#include <queue>
#define MAX_LEN 1003
using namespace std;

vector<int> graph[MAX_LEN];
queue<int> q;
bool visited[MAX_LEN];

void bfs(int cur) {
    
    // [조심!] queue에 들어가는 순간 true 처리!
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
