#include <iostream>
#define INF 1e18
using namespace std;

typedef long long int ll;
ll w, path[102][102];
int N, M, u, v;

void Floyd_Warshall(int vertex) {

	for (int k = 1; k <= vertex; ++k) {
		for (int i = 1; i <= vertex; ++i) {
			for (int j = 1; j <= vertex; ++j) {
				if (path[i][j] > path[i][k] + path[k][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 102; ++i) {
		for (int j = 0; j < 102; ++j) {
			if (i != j) path[i][j] = INF;
		}
	}

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v >> w;
		path[u][v] = (path[u][v] > w ? w : path[u][v]);
	}

	Floyd_Warshall(N);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (path[i][j] == INF) cout << 0 << " ";
			else cout << path[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
