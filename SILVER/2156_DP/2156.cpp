#include <iostream>
#define FOR(i, n, m) for(int i=n; i<m; ++i)
#define MAX(n, m) (n > m ? n : m)
using namespace std;

int N, M;
int arr[10004];
int DP[10004][3];

int main(void) {

	cin >> N;

	FOR(i, 1, N+1) {
		cin >> arr[i];
	}

	FOR(i, 1, N + 1) {
		// 2전 수와의 관계
		if (i - 3 > 0)
			DP[i][0] = arr[i] + DP[i - 3][2];
		else
			DP[i][0] = 0;
		M = MAX(DP[i][0], M);

		// 1전 수 연속X와의 관계
		if (i - 2 > 0)
			DP[i][1] = MAX((DP[i - 2][1] + arr[i]), (DP[i - 2][2] + arr[i]));
		else
			DP[i][1] = arr[i];
		M = MAX(DP[i][1], M);

		// 1전 수 연속O와의 관계
		if (i - 1 > 0)
			DP[i][2] = MAX((DP[i - 1][0] + arr[i]), (DP[i - 1][1] + arr[i]));
		else
			DP[i][2] = arr[i];
		M = MAX(DP[i][2], M);
	}

	cout << M << '\n';

	return 0;
}
