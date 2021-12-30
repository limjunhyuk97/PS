#include <iostream>
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int arr[10001] = {0, };
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}
	for (int i = 1; i <= 10000; ++i) {
		if (arr[i] == 0)
			continue;
		else {
			for (int j = arr[i]; j > 0; --j)
				cout << i<<"\n";
		}
	}

	return 0;
}
