// 수의 거듭제곱에 대한 분할 정복은 지수에 대해서..
// 행렬의 거듭제곱 꼴에 대한 분할 정복은 어떻게.. : 지수를 분할하여 정복

#include <iostream>
using namespace std;

typedef long long int ll;
int N;
ll B, c;
ll M[7][7], T0[7][7], T1[7][7];

void multiplyMatrix(ll A[][7], ll B[][7]) {

	if (c++ % 2 == 1) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				T0[i][j] = 0;
				for (int k = 0; k < N; ++k) {
					T0[i][j] += (A[i][k] * B[k][j]);
				}
				T0[i][j] %= 1000;
			}
		}
		return;
	}
	else {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				T1[i][j] = 0;
				for (int k = 0; k < N; ++k) {
					T1[i][j] += (A[i][k] * B[k][j]);
				}
				T1[i][j] %= 1000;
			}
		}
		return;
	}
}

void powMatrix(ll n) {

	if (n == 1)
		return;

	else if (n == 2) {
		
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < N; ++k) {
					T1[i][j] += (M[i][k] * M[k][j]);
				}
				T1[i][j] %= 1000;
			}
		}
		++c;
		return;
	}

	if (n % 2 == 0) {
		powMatrix(n / 2);
		if (c % 2 == 1)multiplyMatrix(T1, T1);
		else multiplyMatrix(T0, T0);
		return;
	}
	else {
		powMatrix(n - 1);
		if (c % 2 == 1)multiplyMatrix(M, T1);
		else multiplyMatrix(M, T0);
		return;
	}

}

int main(void) {

	cin >> N >> B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> M[i][j];
		}
	}

	powMatrix(B);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (B == 1)
				// 이 부분에서 1000으로 나눠주지 않아서 한참 고민 했다..
				cout << M[i][j] % 1000 << " ";
			else {
				if (c % 2 == 0)
					cout << T0[i][j] << " ";
				else
					cout << T1[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}
