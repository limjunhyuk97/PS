#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[8] = {0, 1, 2 ,3, 4, 5, 6, 7};

// start, end는 1 ~ n
void Sequence(int start, int end, int num) {
	if (num == M+1) {
		for (int i = 1; i <= M; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	else {
		for (int i = start; i <= end; ++i) {
			arr[num] = i;
			Sequence(start, end, num + 1);
		}
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;
	Sequence(1, N, 1);

	return 0;
}
