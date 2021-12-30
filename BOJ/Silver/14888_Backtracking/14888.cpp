#include <iostream>
#define FOR(i, n, m) for(int i=n; i<m; ++i)
#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)
using namespace std;

int arr[12], operation[4], opSpace[12], opResult[12], N;
long minA = 1000000001, maxA = -1000000001;
bool bopSpace[12];

void Permutation(int k) {
	if (k == N-1) {
		minA = MIN(minA, opResult[N - 1]);
		maxA = MAX(maxA, opResult[N - 1]);
	}

	if (k == 0) opResult[0] = arr[0];

	FOR(i, 0, N - 1) {

		if (bopSpace[i]) continue;
		else bopSpace[i] = true;

		switch (opSpace[i]) {
		case 0:
			opResult[k+1] = opResult[k] + arr[k + 1];
			break;
		case 1:
			opResult[k+1] = opResult[k] - arr[k + 1];
			break;
		case 2:
			opResult[k+1] = opResult[k] * arr[k + 1];
			break;
		case 3:
			opResult[k+1] = opResult[k] / arr[k + 1];
			break;
		}

		Permutation(k + 1);

		bopSpace[i] = false;
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i, 0, N) {
		cin >> arr[i];
	}

	// + - * /
	cin >> operation[0] >> operation[1] >> operation[2] >> operation[3];

	int cnt = 0;
	FOR(i, 0, 4) {
		FOR(j, 0, operation[i]) {
			opSpace[cnt++] = i;
		}
	}

	Permutation(0);

	cout << maxA << '\n' << minA << '\n';

	return 0;
}
