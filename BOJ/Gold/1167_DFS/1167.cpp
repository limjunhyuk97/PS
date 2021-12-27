#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#define FOR(i, n) for(int i=0; i<(n); ++i)

using namespace std;

typedef struct vertice {
	int edge;
	int len;
}vertice;

int srcEdge, destEdge, MaxEdge, len, e, tmpE, l, tmpL;
long long tmpR, R;
bool tree[100005] = {false, true, };
stack<long long> subR;

void DFS(vector<vector<vertice>>& vertices, int src) {
	FOR(i, vertices[src].size()) {
		e = vertices[src][i].edge;
		l = vertices[src][i].len;
		if (tree[e] == true) {
			continue;
		}
		else {
			tree[e] = true;
			tmpR += l;
			subR.push(l);
			DFS(vertices, e);
		}
	}
	if (tmpR > R) {
		R = tmpR;
		MaxEdge = src;
	}
	if (!subR.empty()) {
		tmpR -= subR.top();
		subR.pop();
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	vector<vector<vertice>> vertices(N+2);
	
	FOR(i, N) {
		cin >> srcEdge;
		while (1) {
			cin >> destEdge; 
			if (destEdge == -1) break;
			cin >> len;
			vertice tmp = { destEdge, len };
			vertices[srcEdge].push_back(tmp);
		}
	}

	DFS(vertices, 1);
	memset(tree, false, 100005);
	R = 0; tree[MaxEdge] = true;
	DFS(vertices, MaxEdge);
	cout << R;

	return 0;
}
