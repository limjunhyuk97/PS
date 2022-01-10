#include <iostream>
#include <utility>
#include <queue>
#define INF 1e18
using namespace std;

typedef long long int ll;

struct edge {
	ll first;
	int second;

	bool operator<(const edge& other) const {
		return first > other.first;
	}
};

int N, M, S, E, u, v;
ll w;

ll path[1004];
vector<edge> Edges[1004];
priority_queue<edge> nextE;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		cin >> u >> v >> w;
		Edges[u].push_back({w, v});
	}
	cin >> S >> E;

	for (int i = 0; i < 1004; ++i)
		path[i] = INF;
	path[S] = 0;

	nextE.push({ 0, S });
	while (!nextE.empty()) {

		edge curE = nextE.top(); nextE.pop();

		if (path[curE.second] < curE.first) continue;

		for (int i = 0; i < Edges[curE.second].size(); ++i) {
			if (path[Edges[curE.second][i].second] > path[curE.second] + Edges[curE.second][i].first) {
				path[Edges[curE.second][i].second] = path[curE.second] + Edges[curE.second][i].first;
				nextE.push({ path[Edges[curE.second][i].second], Edges[curE.second][i].second });
			}
		}

	}

	cout << path[E] << "\n";

	return 0;
}
