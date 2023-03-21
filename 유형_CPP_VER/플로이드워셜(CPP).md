# 플로이드 워셜

## 플로이드 워셜 코드

- 모든 노드 간의 최단 거리를 구하고 싶다면 플로이드 워셜을 사용할 수 있다.
- O(N^3)의 시간복잡도를 갖기에 시간 효율적인 측면에서 느리다.

```cpp
#include <algorithm>
#define MAXLEN 1005

int N;
int dist[MAXLEN][MAXLEN];

void floydWarshall() {

    // 초기화
    //  - 직접적인 연결이 있는 i,j 노드 사이에 대해서는 : dist[i][j], dist[j][i] 값이 존재해야 한다.
    //  - 직접적인 연결이 없는 i,j 노드 사이에 대해서는 : dist[i][j], dist[j][i] 값이 INF여야 한다.
    //  - i와 j가 같은 값인 경우에 대해서는 : dist[i][j] 값이 0이어야 한다. 
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(i == j) dist[i][j] = 0;
            // ... 그 외의 dist 초기화 작업 요구됨
        }
    }
    
    // 갱신 과정
    //  - i->j로 가는데, k를 경유하여 가는 과정이 최소 거리를 만들어 준다면 이를 반영하여 갱신하는 방식이다.
    for(int k=0; k<N; ++k) {
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++J) {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

}
``` 

## 유의점

### 노드 간 연결이 어떻게 형성되어 있는가? : 초기화 과정에 영향
### 노드를 대표하기 방식으로 인해 for문이 다중으로 쓰일 수 있는가? : 2차원 격자에서 플로이드 와셜은 6중포문을 부를 수도 있다.
