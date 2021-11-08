#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef struct edges{
	int next;
	int weight;
};

int N, K, s, e, w;
vector<edges> edge[100005];
bool searched[100005];
set<int> apartment;

bool DFS(int start) {

	bool flag = false;

	searched[start] = true;
	for (int i = 0; i < edge[start].size(); ++i) {
		if (!searched[edge[start][i].next] && DFS(edge[start][i].next)) flag = true;
	}
	searched[start] = false;

	if ((apartment.find(start) != apartment.end()) || flag) {
		w += 1;
		return true;
	}

	else return false;

}

int main(void) {

	cin >> N >> K;
	
	for (int i = 0; i < N - 1; ++i) {
		cin >> s >> e >> w;
		edge[s].push_back({ e, w });
		edge[e].push_back({ s, w });
	}

	for (int i = 0; i < K; ++i) {
		cin >> s;
		apartment.insert(s);
	}

	w = 0;
	DFS(*apartment.begin());

	cout << w << endl;

	return 0;
}
