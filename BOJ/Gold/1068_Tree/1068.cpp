#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#define INF 1234567891
using namespace std;
typedef long long int ll;

int N, cnt, root;
int parent[52], target;
vector<int> child[52];
bool remain[52];

void traverse(int n) {
	if (!remain[n]) return;
	if (child[n].size() == 0) {
		++cnt;
		return;
	}
	for (int i = 0; i < child[n].size(); ++i)
		traverse(child[n][i]);
}

void deleteTraverse(int n) {
	while (!child[n].empty()) {
		deleteTraverse(child[n].back());
		remain[child[n].back()] = false;
		child[n].pop_back();
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> parent[i];
		if (parent[i] == -1) root = i;
		remain[i] = true;
	}
	cin >> target;

	for (int i = 0; i < N; ++i) {
		if (parent[i] == -1) continue;
		child[parent[i]].push_back(i);
	}

	deleteTraverse(target);
	remain[target] = false;
	if (target != root) {
		for (auto iter = child[parent[target]].begin(); iter != child[parent[target]].end(); ++iter) {
			if (*iter == target) {
				child[parent[target]].erase(iter);
				break;
			}
		}
	}

	traverse(root);
	cout << cnt << endl;

	return 0;
}
