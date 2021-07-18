#include <iostream>
#include <queue>
#include <vector>
#define INF 1e18
using namespace std;

typedef long long int ll;
struct edge {
	int end;
	ll weight;
	bool operator<(const edge& other) const {
		return weight > other.weight;
	}
};

int beforeV[1005];
vector<int> trace;
vector<edge> Edges[1005];
int N, M, S, E;
int u, v;
ll w;

ll Dijkstra(int s, int e) {

	ll path[1005];
	priority_queue<edge> nextE;

	for (int i = 0; i < 1005; ++i) {
		path[i] = INF;
	}
	path[S] = 0;

	nextE.push({ S, 0 });
	
	while (!nextE.empty()) {

		edge cur = nextE.top(); nextE.pop();
		if (path[cur.end] < cur.weight) continue;

		for (int i = 0; i < Edges[cur.end].size(); ++i) {
			if (path[Edges[cur.end][i].end] > path[cur.end] + Edges[cur.end][i].weight) {
				path[Edges[cur.end][i].end] = path[cur.end] + Edges[cur.end][i].weight;
				nextE.push({ Edges[cur.end][i].end, path[Edges[cur.end][i].end] });
				beforeV[Edges[cur.end][i].end] = cur.end;
			}
		}

	}

	return path[e];
}

int makeTrace(int s, int e) {
	int cnt = 0;
	for (; beforeV[e] != s; e = beforeV[e]) {
		++cnt;
		trace.push_back(e);
	}
	trace.push_back(e);
	trace.push_back(s);

	return cnt + 2;

}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < M; ++i) {
		cin >> u >> v >> w;
		Edges[u].push_back({ v, w });
	}

	cin >> S >> E;
	beforeV[S] = S;

	cout << Dijkstra(S, E) << "\n";
	cout << makeTrace(S, E) << "\n";
	for (auto iter = trace.rbegin(); iter != trace.rend(); ++iter)
		cout << *iter << " ";
	cout << "\n";

	return 0;
}
