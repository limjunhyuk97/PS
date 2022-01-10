#include <iostream>
#define FOR(i , e) for(int i=0; i<e; ++i)
using namespace std;

int N;
int cnt0, cnt1;
int grid[128][128];

void count(int lowerX, int upperX, int lowerY, int upperY) {
	int len = upperX - lowerX;
	int flag = grid[lowerX][lowerY];
	
	if (len == 1) {
		if (grid[lowerX][lowerY] == 0) ++cnt0;
		else ++cnt1;
		return;
	}

	for (int i = lowerX; i < upperX; ++i) {
		for (int j = lowerY; j < upperY; ++j) {
			if (flag != grid[i][j]) {
				count(lowerX, upperX - len / 2, lowerY, upperY - len / 2);
				count(lowerX + len / 2, upperX, lowerY, upperY - len / 2);
				count(lowerX, upperX - len / 2, lowerY + len / 2, upperY);
				count(lowerX + len / 2, upperX, lowerY + len / 2, upperY);
				return;
			}
		}
	}

	if (flag == 0) ++cnt0;
	else ++cnt1;
	return;
}

int main(void) {

	int gridNum;

	cin >> N;

	FOR(i,N){
		FOR(j, N) {
			cin >> gridNum;
			grid[i][j] = gridNum;
		}
	}

	count(0, N, 0, N);

	cout << cnt0 << '\n';
	cout << cnt1 << '\n';

	return 0;
}
