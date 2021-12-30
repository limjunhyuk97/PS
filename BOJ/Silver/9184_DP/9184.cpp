#include <iostream>
using namespace std;

int w[21][21][21];

int wFunc(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w[20][20][20];
	if (a < b && b < c)
		return w[a][b][c - 1] + w[a][b - 1][c - 1] - w[a][b - 1][c];
	else
		return w[a - 1][b][c] + w[a - 1][b - 1][c] + w[a - 1][b][c - 1] - w[a - 1][b - 1][c - 1];

}

int main(void) {

	ios::sync_with_stdio(false);
	
	int a, b, c;

	for (int i = 0; i < 21; ++i) {
		for (int j = 0; j < 21; ++j) {
			for (int k = 0; k < 21; ++k) {
				w[i][j][k] = wFunc(i, j, k);
			}
		}
	}

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << wFunc(a, b, c) << '\n';
	}



	return 0;
}
