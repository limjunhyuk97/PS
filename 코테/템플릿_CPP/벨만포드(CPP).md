# 벨만 포드

## 벨만 포드 코드

- 가중치 그래프에서 모든 간선의 가중치가 양수라면 다익스트라 알고리즘을 사용하여 노드 간의 최단 거리를 구할 수 있다.
- 하지만, 가중치 그래프에서 [**어떤 간선의 가중치가 음수라면**] 다익스트라 알고리즘이 [**무한 루프**]에 들어갈 수 있다. 이런 경우 벨만 포드 알고리즘이 해법이 될 수 있다.
- 그럼 [**어떻게 루프를 탐지하는가?**]
    - 노드의 갯수가 N개인 그래프에서 "지점i -> 지점j" 까지의 최단경로는 [최대 N개의 노드, 최대 N-1개의 간선]을 포함할 수 있다.
    - 때문에, 최대 N-1 번의 그래프 전역에서의 dist(시작점으로부터 각 노드 까지의 거리) 갱신 과정을 수행 하면 최단 거리가 구해질 것이다.
    - 이때, **한번 더 그래프 전역에서의 dist(시작점으로부터 각 노드 까지의 거리) 갱신을 수행했는데, 갱신이 또 일어난다면 (N번째 갱신) 사이클이 있는 것으로 판단**한다.
    - 때문에 약 O(N^2 \* E) 의 시간 복잡도로 음의 가중치가 있는 그래프에서의 최단 거리를 구할 수 있게 된다.

```cpp
#define MAXLEN 1005
#define INF 2000000000

struct edge {
    int to, cost;
}

int dist[MAXLEN];
vector<edge> graph[MAXLEN];

// s 시작점 , N 총 노드 수, dist 거리값 저장 배열
bool bellmanFord(int s, int N) {
    
    // dist 값 초기화
    for(int i=0; i<MAXLEN; ++) {
        dist[i] = INF;
    }
    dist[s] = 0;
    
    // 갱신 됬는지 여부를 체크하기 위한 값 선언
    bool updated = false;
    
    // N번 순회 (N-1번 순회 기본 / N번째 갱신여부 체크)
    for(int i=0; i<N; ++i) {
        updated = false;
        
        // 노드의 수만큼 순회
        for(int cur=0; cur<N; ++cur) {
            if(dist[cur] == INF) continue;
            
            for(int j=0; j<graph[cur].size(); ++j) {
                int next = graph[cur][j].to;
                int nextDist = dist[cur] + graph[cur][j].cost;
                if(dist[next] > nextDist) {
                    dist[next] = nextDist;
                    updated = true;
                }
            }
        }
        
        // 업데이트 안일어났다면 더이상 안봐도 돼 아예. 이는 N-1 이하 번쨰의 순회에서 일어날 수 있음
        if(!updated) break;
    }  
    
    // 마지막에 N번째에 순회가 일어났다면 사이클이 있던거임
    if(updated) return false;
    else return true;
}
```


## 유의점

### '사이클 발생 위치'가 '내가 구하고자 하는 거리값에 영향'을 미치는가?

- 사이클의 탐지는 기본적으로 N번째 반복에서 dist의 갱신이 일어나는지 여부로 판단할 수 있다. **하지만, 해당 사이클의 발생이 내가 구하려하는 "특정 출발지 - 목적지 간의 최단 거리"를 측정하는데 영향을 끼칠지 끼치지 않을지에 대해서 고려해야 한다면, 일반적인 코드에서의 수정이 필요하다.** / 2129_드라이브 파이널
