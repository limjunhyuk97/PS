#include <iostream>
#define FOR(i, n) for(int i=0; i< (n); ++i)
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;
	long long K;
	cin >> T;

	FOR(i, T) {
		K = 1;
		cin >> N >> M;
		if (M - N < N) N = M - N;
		for (int j = M; j > M - N; --j)
			K *= j;
		for (int j = 2; j <= N; ++j)
			K /= j;	

		cout << K << '\n';
	}

	return 0;
}
