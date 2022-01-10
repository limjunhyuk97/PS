#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define MAX(m, n) m > n ? m : n
using namespace std;

int N, maxP, cnt = 5;
int T[25];
int P[25];
int X[25];

int main(void) {

	cin >> N;

	FOR(i, N)
		cin >> T[i] >> P[i];

	FOR(i, N) {
		FOR(j, 5) {
			if (i - j < 0)
				break;
			X[i] = (MAX(X[i], X[i - j]));
		}
		X[T[i] + i] = (MAX(P[i] + X[i], X[T[i] + i]));
	}

	while (N >= 0 && cnt!=0) {
		maxP = ( MAX(X[N], maxP) );
		N -= 1;
		--cnt;
	}

	cout << maxP;

	return 0;
}
