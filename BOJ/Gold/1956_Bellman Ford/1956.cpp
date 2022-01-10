#include <iostream>
#include <algorithm>
#define INF 1e18
using namespace std;

typedef long long int ll;
ll path[402][402], w, cycle = INF;
int V, E, u, v;

void Floyd_Warshall(int vertex) {

	for (int k = 1; k <= vertex; ++k) {
		for (int i = 1; i <= vertex; ++i) {
			for (int j = 1; j <= vertex; ++j) {
				if (path[i][j] == 0) path[i][j] = path[i][k] + path[k][j];
				else path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
			}
		}
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 402; ++i) {
		for (int j = 0; j < 402; ++j) {
			if (i != j) path[i][j] = INF;
		}
	}

	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		path[u][v] = w;
	}

	Floyd_Warshall(V);

	for (int i = 1; i <= V; ++i) {
		if (path[i][i] != 0 && cycle > path[i][i]) cycle = path[i][i];
	}

	if (cycle == INF) cout << "-1\n";
	else cout << cycle << "\n";

	return 0;
}
