#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
ll N, M;
ll arr[1000005];

int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(&arr[0], &arr[N]);

	ll left = 0, right = arr[N - 1], mid;
	ll chop = 0;

	while (left <= right) {
		chop = 0; mid = left + right >> 1;

		for (int i = 0; i < N; ++i) {
			if (arr[i] > mid)
				chop += arr[i] - mid;
		}
		
		if (chop < M) right = mid - 1;
		else left = mid + 1;

	}

	cout << right << "\n";

	return 0;
}
