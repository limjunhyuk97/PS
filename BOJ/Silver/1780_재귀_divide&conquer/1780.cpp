#include <iostream>
using namespace std;

int N, arr[2200][2200];
int Cnt;

int dx[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
int dy[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };

int dn[3];

int gridTest(int x, int y, int len) {

	int dz[9];

	if (len == 1) {
		dn[arr[x][y] + 1]++;
		return arr[x][y];
	}

	int cnt = 0;
	for (int i = 0; i < 9; ++i) {
		dz[cnt++] = gridTest(x + (len/3) * dx[i], y + (len/3) * dy[i], len/3);
	}

	cnt = dz[0];
	for (int i = 0; i < 9; ++i) {
		if (dz[0] != dz[i])
			return 2;
	}

	if(cnt != 2)
		dn[cnt + 1] -= 8;

	return cnt;

}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];
	}

	gridTest(0, 0, N);

	for (int i = 0; i < 3; ++i)
		cout << dn[i] << "\n";

	return 0;
}
