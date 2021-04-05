#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i = 0; i< (n); ++i)
using namespace std;

int N, P, A;
vector<pair<int ,int>> Pair;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N; int* out = new int[N];
	FOR(i, N) {
		cin >> A; P = i;
		Pair.push_back(make_pair(A, P));
	}

	sort(Pair.begin(), Pair.end());
	
	FOR(i, N) {
		out[Pair[i].second] = i;
	}

	FOR(i, N) cout << out[i] << " ";

	delete[] out;
	return 0;
}
