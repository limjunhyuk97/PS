#include <iostream>
#include <vector>
#include <utility>
#define INF 1e18
using namespace std;

typedef long long int ll;
typedef pair<int, ll> edge;

int N, M;
int u, v;
ll w, path[502];
vector<edge> edges[502];

int Bellman_Ford(int s, int v) {

	// path 전체와 시작 vertex 초기화
	for (int i = 1; i <= v; ++i)
		path[i] = INF;
	path[s] = 0;

	// v - 1 횟수만큼 반복시킨다. v 번째에서 cycle 여부를 확인한다.
	// cycle 여부의 확인은 path 값 갱신 여부를 통해서 확인한다.
	bool update = false;

	// v번의 cycle을 돌린다
	for (int i = 0; i < v; ++i) {
		update = false;

		// v - 1 번의 loop(1 ~ v의 각 vertex들까지에 대한 path 값 갱신), v 번째에서 확인
		for (int j = 1; j <= v; ++j) {

			// path 값이 무한대이면 고려할 필요도 없다.
			if (path[j] == INF) continue;

			// 각 vertex와 연결된 다음 vertex까지의 path 값들을 갱신.
			for (int k = 0; k < edges[j].size(); ++k) {
				if (path[edges[j][k].first] > path[j] + edges[j][k].second) {
					path[edges[j][k].first] = path[j] + edges[j][k].second;
					update = true;
				}

			}
		}

		// update가 일어나지 않았다면, 다음번 cycle에서도 일어나지 않을 것이다.
		if (!update)
			break;
	}

	if (update) return -1;
	else return 0;

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v >> w;
		edges[u].push_back({ v, w });
	}

	w = Bellman_Ford(1, N);

	if (w == -1) cout << "-1" << "\n";
	else {
		for (int i = 2; i <= N; ++i) {
			if (path[i] == INF) cout << "-1" << "\n";
			else cout << path[i] << "\n";
		}
	}

	return 0;
}
