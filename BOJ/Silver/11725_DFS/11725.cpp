#include <iostream>
#include <vector>
#include <queue>
#define FOR(i, n) for(int i=0; i<(n); ++i)
using namespace std;

int N, n1, n2;
bool visit[100005] = {false, true, };

void DFS(vector<vector<int>> &Tree, int parent[], int src) {
	FOR(i, Tree[src].size()) {
		int k; k = Tree[src][i];
		if (visit[k] == true) continue;
		else {
			visit[k] = true;
			parent[k] = src;
			DFS(Tree, parent, k);
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<vector <int>> Tree(N+2);
	int* parent = new int[N + 2];

	FOR(i, N-1) {
		cin >> n1 >> n2;
		Tree[n1].push_back(n2);
		Tree[n2].push_back(n1);
	}
	
	DFS(Tree, parent, 1);

	FOR(i, N+1) {
		if (i == 0 || i == 1) continue;
		cout << parent[i] << '\n';
	}

	delete[] parent;

	return 0;
}
