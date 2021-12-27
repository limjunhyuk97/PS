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

int N, M, T, cnt;
bool truth[55];
int parent[55];
vector<vector<int> >partySet;

int Find(int n) {
	int root = n;
	for (; parent[root] >= 0; root = parent[root]);

	while (parent[n] >= 0) {
		int tmp = parent[n];
		parent[n] = root;
		n = tmp;
	}
	return root;
}

void Union(int n, int m) {
	int nroot = Find(n);
	int mroot = Find(m);

	if (nroot != mroot) {
		int sum = parent[nroot] + parent[mroot];
		if (parent[nroot] > parent[mroot]) {
			parent[nroot] = mroot;
			parent[mroot] = sum;
		}
		else {
			parent[mroot] = nroot;
			parent[nroot] = sum;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		parent[i] = -1;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		int tmp; cin >> tmp;
		truth[tmp] = true;
	}

	// 같은 집합에 속해있는 root끼리 union 완료
	for (int i = 0; i < M; ++i) {
		int num; cin >> num;

		vector<int> party;
		for (int j = 0; j < num; ++j) {
			int person; cin >> person;
			party.push_back(person);
		}
		partySet.push_back(party);

		for (int j = 0; j < num; ++j) {
			Union(party[0], party[j]);
		}
	}

	// 묶인 집합 단위의 root를 truth로 설정한다.
	for (int i = 1; i <= N; ++i) {
		if (truth[i]) {
			truth[Find(i)] = true;
		}
	}

	// 묶인 집합 단위를 truth 설정한다.
	for (int i = 1; i <= N; ++i) {
		if (truth[Find(i)])
			truth[i] = true;
	}

	// 집합 단위로 검사한다.
	for (int i = 0; i < M; ++i) {
		if (!truth[partySet[i][0]])
			++cnt;
	}
	
	cout << cnt << endl;
	
	return 0;
}
