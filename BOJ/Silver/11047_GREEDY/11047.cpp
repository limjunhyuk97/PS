#include <iostream>
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K; cin >> N >> K;
	int cnt = N - 1, ans = 0;
	int* arr = new int[N];

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	while (K != 0) {
		if (K - arr[cnt] >= 0) {
			K -= arr[cnt];
			++ans;
			continue;
		}
		--cnt;
	}

	cout << ans;

	delete[]arr;

	return 0;
}
