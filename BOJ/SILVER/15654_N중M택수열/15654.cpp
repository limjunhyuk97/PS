#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[10];
bool arrB[10];
vector<int> s;

void pick(int cnt) {

	if (cnt == 0) {

		for (int i = 0; i < M; ++i)
			cout << s[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (!arrB[i]) {
			arrB[i] = true;
			s.push_back(arr[i]);
			pick(cnt - 1);
			s.pop_back();
			arrB[i] = false;
		}
	}

}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	sort(&arr[0], &arr[N]);

	pick(M);

	return 0;
}
