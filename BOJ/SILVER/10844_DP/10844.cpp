#include <iostream>
#define FOR(i, n, m) for(int i=n; i<m; ++i)
using namespace std;

int N;
long long arr[101][10];
long long const DIVIDEND = 1000000000;

void DP(int n) {

	long long ans = 0;

	FOR(i, 2, n + 1) {
		FOR(j, 0, 10) {
			if (j == 0) arr[i][0] = arr[i - 1][1];
			else if (j == 9) arr[i][9] = arr[i - 1][8];
			else arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % DIVIDEND;

		}
	}

	FOR(i, 1, 10) {
		ans += arr[n][i];
	}

	cout << ans % DIVIDEND <<'\n';
}

int main(void) {

	cin >> N;

	FOR(i, 0, 10)
		arr[1][i] = 1;
	
	DP(N);

	return 0;
}
