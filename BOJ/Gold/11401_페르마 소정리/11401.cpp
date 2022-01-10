// 거듭 제곱 연산에 대한 mod 연산 : 분할 정복의 방법 (O(logN)의 복잡도로 구현 가능)
// 곱셈 연산에 대한 mod 연산 : (a * b) % n == ( (a % n) * (b % n) ) % n
// 나눗셈 연산에 대한 mod 연산 : 페르마의 소정리를 통한 연산 구현
// 조합 연산의 여러가지 방법을 고려

#include <iostream>
#include <utility>
#define MOD 1000000007
using namespace std;

int N, K;
long long int cardinal = 1, ordinal = 1;

int powerAB(long long int a, long long int b) {

	a %= MOD;

	if (b == 0) return 1;
	else if (b == 1) return a;
	else if (b % 2 == 0) {
		long long int tmp = powerAB(a, b/2);
		return tmp * tmp % MOD;
	}
	else return a * powerAB(a, b-1) % MOD;

}

int main(void) {

	cin >> N >> K;
	K = min(K, N - K);

	if (K == 0) cout << 1 << "\n";
	else {
		for (int i = N; i >= N - K + 1; --i) {
			cardinal = cardinal * i % MOD;
		}
		for (int i = 1; i <= K; ++i) {
			ordinal = ordinal * i % MOD;
		}
		ordinal = powerAB(ordinal, MOD-2);
		cout << cardinal * ordinal % MOD << "\n";
	}

	return 0;
}
