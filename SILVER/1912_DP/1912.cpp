#include <iostream>
#include <algorithm>
using namespace std;

int NM[100004], MAX = -1005;
int DP[100004][3], N, T;
bool F = false;

int main(void) {

	DP[0][2] = MAX;

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> NM[i];
		MAX = max(MAX, NM[i]);
		if (!F && NM[i] > 0)
			F = true;
	}

	if (F) {
		for (int i = 1; i <= N; ++i) {

			T = NM[i];

			// DP 0 (양수 시작 DP)
			if (T < 0)
				DP[i][0] = 0;
			else
				DP[i][0] = DP[i - 1][0] + T;

			// DP 1 (지속 DP)
			DP[i][1] = DP[i - 1][1] + T;

			// DP 2 (max 결과 유지)
			DP[i][2] = max(max(DP[i][0], DP[i][1]), DP[i - 1][2]);
			if (DP[i][1] < DP[i][0])
				DP[i][1] = DP[i][0];

		}

		cout << DP[N][2] << '\n';
	}

	else
		cout << MAX << '\n';

	return 0;
}
