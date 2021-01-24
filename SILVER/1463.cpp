#include <iostream>
using namespace std;

int arr[1000001] = { 0, 1, 1, 1, };
int XOP(int n) {
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else if (n == 3)
		return 1;
	else {
		for (int i = 4; i <= n; ++i) {
			arr[i] = arr[i - 1] + 1;
			if ((arr[i]>arr[i/3]+1) && (i % 3 == 0)) {
				arr[i] = (arr[i / 3] + 1);
			}
			else if ((arr[i] > arr[i / 2] + 1) && (i % 2 == 0)) {
				arr[i] = (arr[i / 2] + 1);
			}
		}
		return arr[n];
	}
}

int main(void) {
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cout << XOP(N);

	return 0;
}
