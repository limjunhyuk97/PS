#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#define MAXEDGE 300005
using namespace std;
typedef long long int ll;

int N, u, v;
ll D, G;
vector<int> edges[MAXEDGE];
vector< pair<int, int> > edgepair;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
		edgepair.push_back({ u, v });
	}

	// G 세기
	for (int i = 1; i < MAXEDGE; ++i) {
		if (edges[i].size() >= 3) {
			ll tmp = edges[i].size();
			G += (tmp * (tmp - 1) * (tmp - 2) / 3 / 2);
		}
	}
	
	// D 세기
	for (int i = 0; i < N - 1; ++i) {
		D += ((ll)(edges[edgepair[i].first].size() - 1) * (ll)(edges[edgepair[i].second].size() - 1));
	}

	if (D > 3 * G) cout << "D\n";
	else if (D < 3 * G) cout << "G\n";
	else cout << "DUDUDUNGA\n";

	return 0;
}
