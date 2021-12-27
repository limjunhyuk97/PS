#include <iostream>
#define div 1000000007
using namespace std;

typedef long long int ll;

ll n, c;
ll fibo[2][2] = {1, 1, 1, 0}, T0[2][2], T1[2][2];

void multiplyMatrix(ll A[][2], ll B[][2]) {
	if (c++ % 2 == 0) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				T1[i][j] = 0;
				for (int k = 0; k < 2; ++k) {
					T1[i][j] += (A[i][k] * B[k][j]);
				}
				T1[i][j] %= div;
			}
		}
	}
	else {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				T0[i][j] = 0;
				for (int k = 0; k < 2; ++k) {
					T0[i][j] += (A[i][k] * B[k][j]);
				}
				T0[i][j] %= div;
			}
		}
	}
}

void fiboN(ll N) {

	if (N == 1)
		return;
	else if (N == 2) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				T1[i][j] = 0;
				for (int k = 0; k < 2; ++k) {
					T1[i][j] += (fibo[i][k] * fibo[k][j]);
				}
				T1[i][j] %= div;
			}
		}
		++c;
		return;
	}
	
	if (N % 2 == 0) {
		fiboN(N / 2);
		if (c % 2 == 0)multiplyMatrix(T0, T0);
		else multiplyMatrix(T1, T1);
		return;
	}
	else {
		fiboN(N - 1);
		if (c % 2 == 0)multiplyMatrix(T0, fibo);
		else multiplyMatrix(T1, fibo);
		return;
	}

}

int main(void) {

	cin >> n;

	if (n == 1) cout << 1 << "\n";
	else if (n == 2) cout << 1 << "\n";
	else if (n == 3) cout << 2 << "\n";
	else {
		fiboN(n - 2);
		if (c % 2 == 0)cout << (T0[0][0] + T0[0][1]) % div << "\n";
		else cout << (T1[0][0] + T1[0][1]) % div << "\n";
	}

	return 0;
}
