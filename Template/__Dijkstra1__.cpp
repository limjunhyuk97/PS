#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int N, M, S, E;
typedef long long ll;
struct edge {
   int to, cost;
};
struct node {
   ll idx, cost;
   bool operator < (const node& A)const {
      return cost > A.cost;
   }
};
priority_queue<node> que;
vector<edge> vec[20001];
ll dist[20001];
int main() {
   scanf("%d %d", &N, &M);
   for (int i = 0; i < M; ++i) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      vec[u].push_back({ v,c });
   }
   scanf("%d %d", &S, &E);
   for (int i = 1; i <= N; ++i)
      dist[i] = 1e9;
   dist[S] = 0;
   que.push({ S,0 });
   while (!que.empty()) {
      node cur = que.top(); que.pop();
      // 만약에 지금 고려하는 종착노드에 대한 distance 값이 이전 노드에서 출발한 edge의 cost보다 작은 경우 고려할 필요도 없다!
      if (dist[cur.idx] < cur.cost) continue;
      for (int i = 0; i < vec[cur.idx].size(); ++i) {
         edge nxt = vec[cur.idx][i];
         // 고려했을 때, 갱신된 경우에는, 해당 종착지에서 시작하는 edge에 대해서 고려가 다시 필요하다.
         // 그러므로 que에 넣어 준다.
         if (dist[nxt.to] > dist[cur.idx] + nxt.cost) {
            dist[nxt.to] = dist[cur.idx] + nxt.cost;
            que.push({ nxt.to,dist[nxt.to] });
         }
      }
   }
   printf("%lld\n", dist[E]);
   return 0;
}
