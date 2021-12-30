#include <iostream>
using namespace std;

int DP[500][500];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tmp, MAX = 0; cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			cin >> DP[i][j];
			if (i == 0) break;
			else {
				if (j == 0) {
					DP[i][j] = DP[i - 1][j] + DP[i][j];
				}
				else if (j == i) {
					DP[i][j] = DP[i - 1][j - 1] + DP[i][j];
				}
				else {
					DP[i][j] = (DP[i - 1][j - 1] >= DP[i - 1][j] ? DP[i - 1][j - 1] : DP[i - 1][j]) + DP[i][j];
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		if (MAX <= DP[N - 1][i])
			MAX = DP[N - 1][i];
	}
	cout << MAX;

	return 0;
}
