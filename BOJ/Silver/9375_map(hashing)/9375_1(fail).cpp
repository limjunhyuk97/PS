// 시간초과

#include <iostream>
#include <string>
using namespace std;

string type[32], n, t;
bool flag, check[32];
int countType[32], N, T;
int c;

int ans;

int Combination(int n, int start) {
	if (n == 0)
		return 1;

	int ret = 0;

	for (int i = start; i < c; ++i) {
		ret += countType[i] * Combination(n - 1, i + 1);
	}

	return ret;
}

int main(void) {

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> N;

		for (int j = 0; j < c; ++j)
			countType[j] = 0;
		c = 0;

		for (int j = 0; j < N; ++j) {
			cin >> n >> t;
			flag = false;
			for (int k = 0; k < c; ++k) {
				if (type[k] == t) {
					flag = true;
					countType[k]++;
					break;
				}
			}
			if (!flag) {
				type[c] = t;
				countType[c]++;
				++c;
			}
		}

		ans = 0;
		for (int j = 0; j < c; ++j) {
			ans += countType[j];
		}
		for (int j = 2; j <= c; ++j) {
			ans += Combination(j, 0);
		}

		cout << ans << "\n";

	}

	return 0;
}
