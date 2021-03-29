#include <iostream>
#include <queue>
#define FOR(x, n) for(int x=0; x<(n); ++x)
using namespace std;

int w, h, i, j, n, cnt;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool grid[52][52];

typedef struct Point {
	int x;
	int y;
}Point;

queue <Point> domain;

bool cntIsland(int x, int y) {
	if (x < 0 || y < 0 || x >= w || y >= h) return false;
	if (!grid[x][y]) return false;
	grid[x][y] = false;

	FOR(i, 8) {
		cntIsland(x + dx[i], y + dy[i]);
	}
	return true;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true) {

		cin >> w >> h; cnt = 0;
		if (w == 0 && h == 0) break;

		FOR(i , h) {
			FOR(j, w) {
				cin >> n;
				if (n == 0) continue;
				else {
					Point tmp = { j, i };
					domain.push(tmp);
					grid[j][i] = true;
				}
			}
		}

		while(1) {
			if (domain.empty()) break;
			if(cntIsland(domain.front().x, domain.front().y)) ++cnt;
			domain.pop();
		}
		
		cout << cnt << '\n';

	}

	return 0;
}
