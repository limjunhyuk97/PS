#include <iostream>
using namespace std;

int arr_0[41] = { 1, 0 };
int arr_1[41] = { 0 ,1 };

void Fibo(int n) {
	if (n == 0) {
		cout << arr_0[0] << " " << arr_1[0] << '\n';
		return;
	}
	else if (n == 1) {
		cout << arr_0[1] << " " << arr_1[1] << '\n';
		return;
	}
	else {
		for (int i = 2; i <= n; ++i) {
			if (arr_0[i] == 0 && arr_1[i] == 0) {
				arr_0[i] = arr_0[i - 1] + arr_0[i - 2];
				arr_1[i] = arr_1[i - 1] + arr_1[i - 2];
			}
			else
				continue;
		}
		cout << arr_0[n] << " " << arr_1[n] << '\n';
		return;
	}
}

int main(void) {

	ios::sync_with_stdio(false);

	int T, N;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> N;
		Fibo(N);
	}

	return 0;
}
