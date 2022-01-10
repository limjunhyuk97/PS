#include <iostream>
#include <deque>
#define MAX(n, m) (n > m ? n : m)
using namespace std;

int T, N, K, W;

typedef struct Graph {
	int edgeNum;
	int vertexNum;
	int vertexValue[1004];
	int ET[1004];
	int predecessor[1005];
	deque<int> edge[1005];
	deque<int> reverseEdge[1005];
};

int main(void) {

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> N >> K;

		// index deque
		deque<int> index;

		// 그래프 구성
		Graph *graph = new Graph;
		graph->edgeNum = N;
		graph->vertexNum = K;

		for (int j = 1; j <= N; ++j) {
			cin >> graph->vertexValue[j];
		}

		for (int j = 1; j <= N; ++j) {
			graph->ET[j] = 0;
			graph->predecessor[j] = 0;
		}

		for (int j = 1; j <= K; ++j) {
			int s, e; cin >> s >> e;
			graph->edge[s].push_back(e);
			graph->reverseEdge[e].push_back(s);
			++(graph->predecessor[e]);
		}
		cin >> W;

		// Finding source
		for (int j = 1; j <= N; ++j) {
			if (graph->predecessor[j] == 0) {
				index.push_back(j);
				graph->ET[j] = graph->vertexValue[j];
			}
		}

		// Topological sorting
		for (int j = 2; j <= N; ++j) {

			int top = index.front();
			index.pop_front();

			while (!graph->edge[top].empty()) {

				int peek = graph->edge[top].front();
				graph->edge[top].pop_front();

				--(graph->predecessor[peek]);
				graph->ET[peek] = MAX(graph->ET[peek], (graph->ET[top] + graph->vertexValue[peek]));

				if (graph->predecessor[peek] == 0)
					index.push_back(peek);
			}

			if (graph->predecessor[W] == 0)
				break;
		}

		cout << graph->ET[W] << '\n';

		delete graph;
	}
	
	return 0;
}
