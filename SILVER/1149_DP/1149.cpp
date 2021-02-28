#include <iostream>
using namespace std;

int RGB[1001][3];

int main(void) {

	int N; cin >> N;
	for (int i = 1; i <= N; ++i) {
		int R, G, B; cin >> R >> G >> B;
		RGB[i][0] = (RGB[i - 1][1] >= RGB[i - 1][2] ? RGB[i - 1][2] : RGB[i - 1][1]) + R;
		RGB[i][1] = (RGB[i - 1][0] >= RGB[i - 1][2] ? RGB[i - 1][2] : RGB[i - 1][0]) + G;
		RGB[i][2] = (RGB[i - 1][1] >= RGB[i - 1][0] ? RGB[i - 1][0] : RGB[i - 1][1]) + B;
	}

	int min;
	min = RGB[N][0] >= RGB[N][1] ? RGB[N][1] : RGB[N][0];
	min = min >= RGB[N][2] ? RGB[N][2] : min;
	cout << min;

	return 0;
}
