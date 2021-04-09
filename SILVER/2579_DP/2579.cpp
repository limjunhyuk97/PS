#include <iostream>
#define MAX(n , m) n > m ? n : m
#define FOR(i, n) for(int i=0; i< (n); ++i)
using namespace std;

int nArr[300], DP[300], N, tmp;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	FOR(i, N)
		cin >> nArr[i];

	DP[0] = nArr[0];
	DP[1] = nArr[0] + nArr[1];
	DP[2] = MAX(nArr[0] + nArr[2], nArr[1] + nArr[2]);

	FOR(i, N)
		DP[i] = MAX(DP[i - 2] + nArr[i], DP[i - 3] + nArr[i - 1] + nArr[i]);

	cout << DP[N - 1] << '\n';

	return 0;
}
