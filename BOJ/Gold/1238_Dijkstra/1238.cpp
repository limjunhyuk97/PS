#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#define INF 1e9
#define MAXVERTEX 1005
using namespace std;

typedef pair<int, int> edge;

int N, M, X;
int u, v, w;
int Distance[MAXVERTEX];
vector<edge> Edges[MAXVERTEX];

int Dijkstra(int s, int e) {

	priority_queue<edge> nextE;
	int path[MAXVERTEX];

	for (int i = 0; i < MAXVERTEX; ++i) {
		path[i] = INF;
	}
	path[s] = 0;
	nextE.push({ 0, s });

	while (!nextE.empty()) {

		edge cur = nextE.top(); nextE.pop();

		if (path[cur.second] < -cur.first) continue;
		for (int i = 0; i < Edges[cur.second].size(); ++i) {
			if (path[Edges[cur.second][i].second] > path[cur.second] - Edges[cur.second][i].first) {
				path[Edges[cur.second][i].second] = path[cur.second] - Edges[cur.second][i].first;
				nextE.push({ -path[Edges[cur.second][i].second], Edges[cur.second][i].second });
			}
		}

	}

	return path[e];

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> X;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v >> w;
		Edges[u].push_back({ -w, v });
	}

	for (int i = 1; i <= N; ++i) {
		if (N == X) continue;
		Distance[i] = Dijkstra(i, X) + Dijkstra(X, i);
	}

	cout << *max_element(&Distance[0], &Distance[N + 1]) << "\n";

	return 0;
}
