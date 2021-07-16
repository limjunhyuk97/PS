#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

struct edge {

    int end;
    int weight;

    bool operator<(const edge& other) const {
        return weight > other.weight;
    }
};

int V, E, S, u, v, w;
int path[20005];
vector<edge> edges[20005];
priority_queue<edge> nextEdges;

int main(void) {

    scanf("%d %d %d", &V, &E, &S);

    for (int i = 0; i < E; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({ v, w });
    }
    
    // path 값들을 초기화 한다
    for (int i = 0; i < 20005; ++i)
        path[i] = INF;
    // 시작지점에 대한 path 값은 0으로 설정한다
    path[S] = 0;
  
  
    // 다음으로 고려할 edge를 선택하는 것과 관련된 priority_queue에 시작점으로 들어가는 가상의 edge를 넣는셈 친다.
    nextEdges.push({ S, 0 });
    
  
    // priority_queue가 비워질 때까지 loop를 돌린다 : dijkstra를 통해서 특정 src에서 나머지 지점들까지의 최단거리를 구하는 본격적인 과정
    while (!nextEdges.empty()) {
      
        // cur : 다음으로 고려할 edge를 priority_queue에서 꺼낸다
        // curV : 다음으로 고려할 vertex 후보, curW : 다음으로 고려할 vertex까지의 weight
        edge cur = nextEdges.top(); nextEdges.pop();
        int curV = cur.end; int curW = cur.weight;
      
        // 고려할 vertex후보까지의 path 값이, 이전에 다른 지점에서 갱신되어서 priority_queue에 전달된 curW값보다 이미 작다면, 고려할 필요도 없다!
        if (path[curV] < curW) continue;
        
        // 그렇지 않다면 고려해야한다!
        for (int i = 0; i < edges[curV].size(); ++i) {
            int nextV = edges[curV][i].end;
            int nextW = edges[curV][i].weight;
          
            // 다음으로 고려하는 vertex와 연결된 vertex들까지의 path 값이 갱신되어야 한다면 갱신해라!
            if (path[nextV] > path[curV] + nextW) {
                path[nextV] = path[curV] + nextW;
              
                // path 값이 갱신되었다면, 다음으로 고려하는 vertex와 연결된 vertex 번호와 그 vertex까지의  path 값을 전달한다.
                nextEdges.push({ nextV, path[nextV] });
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (path[i] < INF) printf("%d\n", path[i]);
        else printf("INF\n");
    }
    printf("\n");

    return 0;
}
