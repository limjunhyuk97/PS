#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

// Union-Find를 위한 Forest Set, Struct 정의
struct Set {

	ll* parent;
	ll number;
	
	Set(ll number) : number(number + 5){
		parent = new ll[this->number];
		for (int i = 0; i < this->number; ++i)
			parent[i] = -1;
	}

	// iterative way, collapsing find
	ll Find(ll i) {

		ll r = i;
		for (; parent[r] >= 0; r = parent[r]);

		while (i != r) {
			ll tmp = parent[i];
			parent[i] = r;
			i = tmp;
		}

		return r;
	}

	// weighted union
	void Union(ll i, ll j) {

		ll iroot = Find(i);
		ll jroot = Find(j);
		ll tmp = parent[iroot] + parent[jroot];

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

ll N, M;
ll operation, idx1, idx2;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	Set forest(N + 1);

	for (int i = 0; i < M; ++i) {
		cin >> operation >> idx1 >> idx2;
		// 같은 set에 포함되어 있는지 확인
		if (operation) {
			if (forest.Find(idx1) == forest.Find(idx2) )
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		// Union 연산
		else {
			forest.Union(idx1, idx2);
		}
	}

	return 0;
}
