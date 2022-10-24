# Dijkstra

- 경로 최단거리를 구하기 위한 기본적인 알고리즘
- 경로 상에 음수값이 없어야 한다.

## Dijkstra

- 우선순위 큐를 사용하여 최단 거리 순으로 추출한다.
- 우선순위 큐에서 뽑은 [현재 바라보는 노드]를 기준으로..
    - dist 배열을 통해 현재 노드에서 [다음 노드로의 고려가 가치 있는 지 판단]
    - 다음 노드로의 고려가 가치가 있다면 [현재 노드 ~ 다음 노드 고려 시 거리 vs 현재의 다음 노드까지 거리]를 비교

### 유형별 접근

- [정점 ~ 정점 사이 최단거리]를 구할 때 (있는 간선 바탕으로 거리 계산) / 1261
- [정점 ~ 정점 잇기] 위해서 최단 비용의 간선을 개척할 때 (없는 간선의 비용을 바탕으로 거리 계산) / 1277
    - 이미 있는 간선은 0
    - 없는 간선 중 이을 수 있는 간선은 비용 처리
    - 없는 간선 중 이을 수 없는 간선은 INF 처리

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 가중치 그래프({다음 노드, 간선 가중치}). 경로 데이터.
vector<pair<int,int> > graph;
int dist[2005];

void dijkstra(int cur) {
    priority_queue<pair<int,int> > pq;
    pq.push({0, cur});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();
        
        if(curDist > dist[cur]) continue;
        
        for(int i=0; i<graph[cur].size(); ++i) {
            int next = graph[cur][i].first;
            int nextDist = graph[cur][i].second;
            if(dist[next] > dist[cur] + nextDist) {
                dist[next] = dist[cur] + nextDist;
                pq.push({-dist[next], next});
            }
        }
    }
}
```
