#include <iostream>
#include <vector>
using namespace std;

bool grid[50][50];

bool Worm(bool grid[50][50], int x, int y, int xMax, int yMax) {
	if (x < 0 || y < 0 || x >= xMax || y >= yMax) return false;
	if (grid[x][y] == false) return false;
	else grid[x][y] = false;

	Worm(grid, x - 1, y, xMax, yMax);
	Worm(grid, x, y - 1, xMax, yMax);
	Worm(grid, x, y + 1, xMax, yMax);
	Worm(grid, x + 1, y, xMax, yMax);
	return true;
}

class Point {
public:
	int x; int y;
	Point() {}
	Point(int x, int y) :x(x), y(y) {}
};

int main(void) {

	int loop; cin >> loop;
	for (int i = 0; i < loop; ++i) {
		int M, N, K, cnt = 0; cin >> M >> N >> K;
		vector<Point> PArr(K);
		for (int j = 0; j < K; ++j) {
			int x, y; cin >> x >> y;
			grid[x][y] = true;
			PArr[j] = Point(x, y);
		}

		for (int j = 0; j < K; ++j) {
			if (Worm(grid, PArr[j].x, PArr[j].y, M, N)) ++cnt;
		}

		cout << cnt << '\n';
	}

	return 0;
}
