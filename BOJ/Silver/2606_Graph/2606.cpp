#include <iostream>
#include <vector>
using namespace std;

vector <int>Node;

void Virus(vector<int>* graph, int src, int dest) {

	for (int i = 0; i < Node.size(); ++i) {
		if (dest == Node[i]) return;
	}
	Node.push_back(dest);

	for (int i = 0; i < graph[dest].size(); ++i) {
		if (graph[dest][i] == src) continue;
		Virus(graph, dest, graph[dest][i]);
	}

}

int main(void) {
	
	int N; cin >> N; 
	vector<int> *graph = new vector<int>[N + 1];

	int E; cin >> E;
	for (int i = 0; i < E; ++i) {
		int l, m; cin >> l >> m;
		graph[l].push_back(m);
		graph[m].push_back(l);
	}

	Virus(graph, 0, 1);
	cout << Node.size() - 1;

	return 0;
}
