#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INF 1e9
using namespace std;

// first : weight, second :end
typedef pair<int, int> edge;
int V, E, S;
int u, v, w;

int path[20005];
vector<edge> Edge[20005];
priority_queue<edge> nextE;

int main(void) {

	cin >> V >> E >> S;
	
	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		Edge[u].push_back({ -w, v });
	}

	for (int i = 0; i < 20005; ++i)
		path[i] = INF;
	path[S] = 0;

	nextE.push({ 0 ,S });

	while (!nextE.empty()) {
		
		edge e = nextE.top(); nextE.pop();

		if (path[e.second] < -e.first) continue;
		for (int i = 0; i < Edge[e.second].size(); ++i) {
			int nextV = Edge[e.second][i].second;
			int nextW = -Edge[e.second][i].first;
			if (path[nextV] > path[e.second] + nextW) {
				path[nextV] = path[e.second] + nextW;
				nextE.push({ -path[nextV], nextV });
			}
		}

	}

	for (int i = 1; i <= V; ++i) {
		if (path[i] < INF) cout << path[i] << "\n";
		else cout << "INF" << "\n";
	}

	return 0;
}
