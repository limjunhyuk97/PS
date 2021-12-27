#include <iostream>
using namespace std;

int arr[1000001] = { 1, 1, };

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	if (N == 1) {}
	else {
		for (int i = 2; i <= N; ++i) {
			arr[i] = arr[i - 1] + arr[i - 2];
			if (arr[i] >= 15746)
				arr[i] %= 15746;
		}
	}
	cout << arr[N];

	return 0;
}

// 문제 분석 후, 규칙성 발견 시에 점화식 형태의 존재가능성을 염두해 두자!
