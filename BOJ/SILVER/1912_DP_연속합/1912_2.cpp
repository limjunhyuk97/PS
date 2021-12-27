#include <iostream>
using namespace std;

int DP[100004][2];
int N, M = -1005;

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> DP[i][0];

	for (int i = 1; i <= N; ++i) {
		
		if (DP[i - 1][1] + DP[i][0] < DP[i][0])
			DP[i][1] = DP[i][0];
		else
			DP[i][1] = DP[i - 1][1] + DP[i][0];

		if (DP[i][1] >= M)
			M = DP[i][1];
	}

	cout << M;

	return 0;
}
