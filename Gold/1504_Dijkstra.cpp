#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define INF 1e18
using namespace std;

// first : -weight,, second : end vertex
typedef long long int ll;
typedef pair<ll, int > edge;

ll w, ans;
int N, E, v1, v2;
int u, v;
int sv1, sv2, v1v2, ev1, ev2;
vector<edge> Edges[805];

ll Dijkstra(int s, int e) {

	ll path[803];
	priority_queue<edge> nextE;

	for (int i = 0; i < 803; ++i)
		path[i] = INF;
	path[s] = 0;

	nextE.push({ 0, s });

	while (!nextE.empty()) {

		edge e = nextE.top(); nextE.pop();

		if (path[e.second] < -e.first) continue;
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

	ans = min( Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, N), Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, N) );

	if (ans < INF) cout << ans << "\n";
	else cout << -1 << "\n";

	return 0;
}
