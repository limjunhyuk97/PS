#include <iostream>
using namespace std;

int arr[11] = { 0, 1, 2, 4, };

int Func(int n) {

	if (n == 1 || n == 2 || n == 3)
		return arr[n];
	else {
		for (int i = 4; i <= n; ++i) {
			if (arr[i] == 0)
				arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
			else
				continue;
		}
	}
	return arr[n];
}

int main(void) {

	ios::sync_with_stdio(false);
	int T , n;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> n;
		cout << Func(n) << "\n";
	}

	return 0;
}
