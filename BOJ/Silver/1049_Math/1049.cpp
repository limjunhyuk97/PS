#include <iostream>
#define FOR(i, n, m) for(int i = n; i < m; ++i)
#define MIN(n, m) (n > m ? m : n)
using namespace std;

int N, M, i;
int pMin= 2000, iMin = 2000, Min = 1234567890;

int main(void) {

	cin >> N >> M;
	FOR(i, 0, M) {
		int ptmp, itmp;
		cin >> ptmp >> itmp;
		pMin = MIN(pMin, ptmp);
		iMin = MIN(iMin, itmp);
	}

	for (i = 0; i * 6 < N; ++i) {
		Min = MIN(Min, (pMin * i + iMin * (N - 6 * i) ) );
	}
	Min = MIN(Min, pMin * i);

	cout << Min << '\n';

	return 0;
}
