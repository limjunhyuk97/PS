#include <iostream>
#include <utility>
using namespace std;

int N;
int arr[503][2];

int main(void) {

	cin >> N;

	arr[2][0] = 1; arr[5][1] = 1;
	for (int i = 6; i <= 500; ++i) {
		if (i % 2 == 0)arr[i][0] = arr[i / 2][0] + 1;
		if (i % 5 == 0) arr[i][1] = arr[i / 5][1] + 1;
	}

	for (int i = 0; i <= N; ++i) {
		arr[501][0] += arr[i][0];
		arr[501][1] += arr[i][1];
	}

	cout << min(arr[501][0], arr[501][1]) << "\n";

	return 0;
}
