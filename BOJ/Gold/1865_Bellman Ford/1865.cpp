// N개의 지점, M개의 도로(무방향, 양의 가중치), W개의 웜홀(방향, 음의 가중치)
// 시간이 줄어들면서 '출발위치로 돌아오는 것'이 가능한것 : 출발 위치로 돌아오는 cycle이 있는가?

#include <iostream>
#include <vector>
#include <utility>
#define INF 1e18
using namespace std;

typedef long long int ll;
typedef pair<int, ll> edge;
int TC, M, N, W;
int S, E;
ll T, path[502];

int Bellman_Ford(int s, int v, const vector<edge> edges[]) {

	for (int i = 0; i < 502; ++i)
		path[i] = INF;

	path[s] = 0;
	bool update = false;

	for (int i = 0; i < v; ++i) {
		update = false;
		for (int j = 1; j <= v; ++j) {
			if (path[j] == INF) continue;
			for (int k = 0; k < edges[j].size(); ++k) {
				if (path[edges[j][k].first] > path[j] + edges[j][k].second) {
					path[edges[j][k].first] = path[j] + edges[j][k].second;
					update = true;
				}
			}
		}
		if (!update)
			break;
	}

	if (update) return -1;
	else return 0;

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> TC;
	while (TC--) {

		vector<edge> Edges[502];

		cin >> N >> M >> W;
		
		// 도로에 대한 input 
		for (int i = 0; i < M; ++i) {
			cin >> S >> E >> T;
			Edges[S].push_back({ E, T });
			Edges[E].push_back({ S, T });
		}

		// 웜홀에 대한 input
		for (int i = 0; i < W; ++i) {
			cin >> S >> E >> T;
			Edges[S].push_back({ E, -T });
		}

		bool flag = true;
		for (int i = 1; i <= N; ++i) {
			if (Bellman_Ford(i, N, Edges) == -1) {
				flag = false;
				break;
			}
		}

		if (!flag) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}
