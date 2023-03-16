// 위상정렬 : 순서가 정해져 있는 작업을 차례로 수행해주어야할 때 순서를 결정해주는 방식
// 단방향 그래프의 경우일 때
//   - 자식 노드를 인접리스트로 미리 정의해둠
//   - 부모 노드의 수를 계산 해둠
//   - 부모 제거하고 + 자식 노드의 부모 노드 수 갱신하고 + 부모 노드 수 0 이면 우선순위큐에 넣고

#include <iostream>
#include <vector>
#include <queue>
#define MAXLEN 32005
using namespace std;

int N, M;

vector<int> graph[MAXLEN];
int parents[MAXLEN];

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
