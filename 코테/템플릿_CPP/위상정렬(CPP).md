# 위상정렬

- 순서가 정해져 있는 작업을 차례로 수행해야 하는 경우 순서를 결정하기 위해 사용하는 알고리즘

## 구현방법

### 초기 선언

- 각 노드의 자식 노드의 정보를 담기 위해 인접 리스트를 구현한다.
- 각 노드의 부모 노드의 수를 담기 위해 배열을 선언한다.
- 부모 노드의 수가 0인 노드정보를 담기 위한 우선순위 큐를 선언한다.

### 이후 동작

- 우선순위 큐에서 노드를 하나 꺼낸다.
- 해당 노드의 자식 노드들의 부모 노드 수를 -1 시킨다. 이때, -1된 자식 노드의 부모 노드 수가 0이면 우선순위 큐에 넣는다.

## 예시

- 1766_문제집

```cpp
#include <iostream>
#include <vector>
#include <queue>
#define MAXLEN 32005
using namespace std;

int N, M;

// 인접 리스트, 부모노드 수
vector<int> graph[MAXLEN];
int parents[MAXLEN];

// 우선순위 큐
priority_queue<int, vector<int>, greater<int> > pq;

int main(void) {
    
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<M; ++i) {
        int n1, n2; scanf("%d %d", &n1, &n2);
        parents[n2] += 1;
        graph[n1].push_back(n2);
    }
    
    for(int i=1; i<=N; ++i) {
        if(parents[i] == 0) pq.push(i);
    }
    
    while(!pq.empty()) {
        int top = pq.top(); pq.pop();
        
        for(int i=0; i< (int)graph[top].size(); ++i) {
            parents[graph[top][i]] -= 1;
            if(parents[graph[top][i]] == 0) pq.push(graph[top][i]);
        }
        
        printf("%d ", top);
    }
    
    printf("\n");
    
    return 0;
}

```
