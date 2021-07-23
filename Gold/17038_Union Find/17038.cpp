#include <iostream>
#include <set>
using namespace std;

int N, M, u, v;
int parent[100005];
char grassType;

set<int> pasture;

int Find(int idx) {

	int root = idx;

	for (; parent[root] >= 0; root = parent[root]);

	while (root != idx) {
		int tmp = parent[idx];
		parent[idx] = root;
		idx = tmp;
	}

	return root;
}

void Union(int i, int j) {

	int iroot = Find(i);
	int jroot = Find(j);
	int tmp = parent[iroot] + parent[jroot];

	if (iroot != jroot) {
		if (parent[iroot] > parent[jroot]) {
			parent[iroot] = jroot;
			parent[jroot] = tmp;
		}
		else {
			parent[jroot] = iroot;
			parent[iroot] = tmp;
		}
	}

	return;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10005; ++i) {
		parent[i] = -1;
	}

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		cin >> grassType >> u >> v;
		Union(u, v);
	}

	for (int i = 1; i <= N; ++i){
		pasture.insert(Find(i));
	}

	for (int i = 0; i < pasture.size(); ++i) {
		if (i == 0) cout << "1";
		else cout << "0";
	}
	cout << "0\n";

	return 0;
}
