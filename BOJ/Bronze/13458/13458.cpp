#include <iostream>
using namespace std;

int arr[1000001];

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;	cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int B, C; cin >> B >> C;
	long long sum = 0;
	
	for (int i = 1; i <= 1000000; ++i) {
		if ((i - B) <= 0)
			arr[i] = 1;
		else {
			if ((i - B) % C == 0)
				arr[i] = 1 + (i - B) / C;
			else
				arr[i] = 2 + (i - B) / C;
		}
	}
	for (int i = 0; i < N; ++i) {
		sum += arr[A[i]];
	}
	cout << sum;

	delete[]A;

	return 0;

}
