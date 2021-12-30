#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;
int arr[1003];

int main(void) {

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(&arr[0], &arr[N], less<int>());

	for (int i = 0; i < N; ++i) {
		M += (arr[i] * (N - i));
	}

	cout << M << '\n';

	return 0;
}
