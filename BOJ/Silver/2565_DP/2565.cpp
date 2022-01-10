#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define FOR(i, n, m) for(int i=n; i<m; ++i)
#define MAXNUM(n, m) (n > m ? n : m)
using namespace std;

int N, M, l1, l2, arr[502];
vector< pair<int, int> > L;

struct Compare {
	bool operator()(pair<int, int> n, pair<int, int> m) {
		return m.first > n.first;
	}
};

Compare comp;

int main(void) {

	cin >> N;
	FOR(i, 0, N) {
		cin >> l1 >> l2;
		L.push_back(pair<int, int>(l1, l2));
	}

	sort(L.begin(), L.end(), comp);

	FOR(i, 0, L.size()) {
		FOR(j, 0, i) {
			if (L[i].second > L[j].second)
				arr[L[i].second] = MAXNUM(arr[L[i].second], arr[L[j].second] + 1);
		}
		M = MAXNUM(arr[L[i].second], M);
	}

	cout << N - M - 1 << '\n';

	return 0;
}
