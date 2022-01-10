#include <iostream>
#include <utility>
#define FOR(i, n, m) for(int i=n; i<m; ++i)
#define MAXNUM(n, m) (n > m ? n : m)
using namespace std;

int N, T, LM, RM, M;
pair<int, int> tmpPair;
pair<int, int> LBitonic[1005];
pair<int, int> RBitonic[1005];

int main(void) {

	cin >> N;
	FOR(i, 0, N) {
		cin >> T;
		tmpPair = pair<int, int>(T, 0);
		LBitonic[i] = tmpPair;
		RBitonic[i] = tmpPair;
	}

	FOR(i, 0, N) {
		FOR(j, 0, i) {
			if (LBitonic[j].first < LBitonic[i].first) {
				LBitonic[i].second = MAXNUM(LBitonic[j].second + 1, LBitonic[i].second);
			}
		}
	}

	for (int i = N - 1; i >= 0; --i) {
		for (int j = i + 1; j < N; ++j) {
			if (RBitonic[j].first < RBitonic[i].first) {
				RBitonic[i].second = MAXNUM(RBitonic[j].second + 1, RBitonic[i].second);
			}
		}
	}

	FOR(i, 0, N) {
		M = MAXNUM(LBitonic[i].second + RBitonic[i].second, M);
	}

	cout << M + 1 << '\n';

	return 0;
}
