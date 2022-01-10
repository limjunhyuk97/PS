// Divide and conquer 할 수 있는가? : 문제를 반복되는 작은 단위들로 나눌 수 있는가? 

#include <iostream>
using namespace std;

int N, K;
int arr[1002][1002];

int main(void) {

	cin >> N >> K;

	arr[0][0] = 1;
	arr[1][0] = 1; arr[1][1] = 1;

	for (int n = 2; n <= 1000; ++n) {
		for (int k = 0; k <= n; ++k) {
			if (k == 0 || k == n)
				arr[n][k] = 1;
			else
				arr[n][k] = (arr[n - 1][k - 1] + arr[n - 1][k]) % 10007;
		}
	}

	cout << arr[N][K] << "\n";

	return 0;
}
