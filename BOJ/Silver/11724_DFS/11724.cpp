#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool vertices[1001];
int cnt;

bool vCheck(vector<int>* graph, int idx) {

	if (!vertices[idx]) return false;
	else vertices[idx] = false;

	for (int i = 0; i < graph[idx].size(); ++i) {
		vCheck(graph, graph[idx][i]);
	}

	return true;

}

int main(void) {

	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; ++i) vertices[i] = true;
	for (int i = 0; i < M; ++i) {
		int l, m; cin >> l >> m;
		graph[l].push_back(m); 
		graph[m].push_back(l); 
	}

	for (int i = 1; i < 1001; ++i) {
		if (vCheck(graph, i)) ++cnt;
	}

	cout << cnt;

	return 0;
}
