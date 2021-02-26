#include <iostream>
using namespace std;

int main(void) {

	int N; cin >> N;
	int* arr = new int[N];
	int* arrC = new int[N];

	for (int i = 0; i < N; ++i) {
		int min = 1001;
		for (int j = 0; j < 3; ++j) {
			int tmp;
			cin >> tmp;
			if (i == 0) {
				if (min > tmp) {
					min = tmp;
					arr[i] = min;
					arrC[i] = j;
				}
			}
			else {
				for (int k = 0; k < i; ++k) {
					if ((tmp < min) && (arrC[k] != j)) {
						min = tmp;
						arr[i] = min;
						arrC[i] = j;
					}
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += arr[i];
	}
	cout << sum;

	delete[]arr; delete[]arrC;

	return 0;
}
