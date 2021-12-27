// 유클리드 호제법 -> 차이들의 최대공약수 구하기.
// 차이들의 최대공약수의 약수 구하기.

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int N, tmp;
int number[102];
vector<int> dv;

// 서로 다른 두 수의 최대공약수를 구하는 방법
// 유클리드 호제법
int GCD(int n, int m) {
	return (m ? GCD(m, n % m) : n);
}

int main(void) {

	cin >> N;

	// 0 ~ N-1 까지 차이 값들이 들어가 있음
	for (int i = 0; i < N; ++i) {
		cin >> number[i];
		if (i == 0) continue;
		else number[i-1] = number[i] > number[i - 1] ? (number[i] - number[i - 1]) : (number[i - 1] - number[i]);
	}

	// N-2에 최종적으로, 전체 수들에 대한 GCD가 걸러진다.
	for (int i = 1; i < N - 1; ++i) {
		number[i] = GCD(number[i], number[i - 1]);
	}

	// GCD의 약수 구하기. (루트한 중간값까지 따지는 방법 사용)
	for (int i = 1; (i * i) <= number[N - 2]; ++i) {
		if (number[N - 2] % i == 0)
			dv.push_back(i);
	}

	int len = dv.size();

	for (int i = len - 1; i >= 0; --i) {
		if (dv[i] * dv[i] == number[N - 2]) continue;
		dv.push_back(number[N - 2] / dv[i]);
	}

	for (int i = 1; i < dv.size(); ++i)
		cout << dv[i] << " ";

	cout << "\n";

	return 0;
}
