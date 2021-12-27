#include <iostream>
#include <algorithm>
using namespace std;

struct Set {
	int number;
	int* parent;

	Set(int number) :number(number + 2) {
		parent = new int[this->number];
		fill(parent, parent + number, -1);
	}

	int Find(int i) {

		int r = i;
		for (; parent[r] >= 0; r = parent[r]);

		while (r != i) {
			int tmp = parent[i];
			parent[i] = r;
			i = tmp;
		}

		return r;

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

	}

	~Set() {
		delete[] parent;
	}
};

int N, M, connected;

int city, trip[2];
bool flag;

int main(void) {

	cin >> N >> M;
	Set set(N);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> connected;
			if (connected) {
				set.Union(i, j);
			}
		}
	}

	for (int i = 0; i < M; ++i) {
		cin >> city;		
		if (i == 0) {
			trip[1] = set.Find(city);
			continue;
		}
		else {
			trip[0] = trip[1];
			trip[1] = set.Find(city);
			if (trip[0] != trip[1]) {
				flag = true;
				break;
			}
		}
	}

	if (flag) cout << "NO" << "\n";
	else cout << "YES" << "\n";

	return 0;
}
