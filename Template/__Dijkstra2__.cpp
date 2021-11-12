#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define INF 1e18
using namespace std;

// first : -weight, second : end vertex
// priority_queue는 기본빵으로 max heap이므로, weight가 가장 작은 놈 먼저 위로 올라갈 것이다.
typedef long long int ll;
typedef pair<ll, int > edge;

ll w, ans;
int N, E, v1, v2;
int u, v;
int sv1, sv2, v1v2, ev1, ev2;
vector<edge> Edges[805];

// Dijkstra : 갱신된 edge들 기준으로 다시 갱신
ll Dijkstra(int s, int e) {

    ll path[803];
    priority_queue<edge> nextE;
    
    // s로 부터 나머지 까지의 거리를 INF로 초기화 한다.
    for (int i = 0; i < 803; ++i) path[i] = INF;
    path[s] = 0;
    
    // 처음에 priority_queue에 weight가 0이고, s로 들어가는 edge를 넣어준다.즉, s에서 부터 시작하는 것이다.
    nextE.push({ 0, s });
    
    // nextE가 비어있다면 종료. 즉, 더이상 고려할 갱신된 edge가 없다면 종료
    while (!nextE.empty()) {
        
        edge e = nextE.top(); nextE.pop();
        
        // '지금 꺼낸 edge의 종료지점 까지의 shortest path값' < '지금 꺼낸 edge의 종료지점 까지의 path값' : 고려할 필요 X
        if (path[e.second] < -e.first) continue;
        
        // '지금 꺼낸 edge의 종료지점에서 시작하는 edge들 shortest path 값' > 'edge 값 + 종료지점까지의 shortest path 값' : 갱신 + nextE에 되먹임
        for (int i = 0; i < Edges[e.second].size(); ++i) {
            if (path[Edges[e.second][i].second] > path[e.second] - Edges[e.second][i].first) {
            path[Edges[e.second][i].second] = path[e.second] - Edges[e.second][i].first;
            nextE.push({ -path[Edges[e.second][i].second], Edges[e.second][i].second });
            }
        }
    }

    return path[e];

}

int main(void) {

   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> E;
   for (int i = 0; i < E; ++i) {
      cin >> u >> v >> w;
      Edges[u].push_back({ -w, v });
      Edges[v].push_back({ -w, u });
   }
   cin >> v1 >> v2;

   ans = min(Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, N), Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, N));

   if (ans < INF) cout << ans << "\n";
   else cout << -1 << "\n";

   return 0;
}
