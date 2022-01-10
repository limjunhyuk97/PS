#include <iostream>
#include <utility>
#include <algorithm>
#define FOR(i, n, m) for(int i = n; i < m; ++i)
using namespace std;

int N, ans;
int A[52];
pair<int, int > B[52];

bool compA(int n, int m) {
	return n < m;
}

bool compB(pair<int, int>P1, pair<int, int > P2) {
	return P1.first > P2.first;
}

int main(void) {

	cin >> N;

	int tmp;
	FOR(i, 0, N)
		cin >> A[i];
	
	FOR(i, 0, N) {
		cin >> tmp;
		B[i].first = tmp;
		B[i].second = i;
	}

	sort(&A[0], &A[N], compA);
	sort(&B[0], &B[N], compB);

	FOR(i, 0, N) {
		ans += (A[i] * B[i].first);
	}

	cout << ans << '\n';

	return 0;
}
