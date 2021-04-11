#include <iostream>
#include <stack>
#include <utility>
#define FOR(i, n, m) for(int i = n; i < m; ++i)
using namespace std;

int N, cnt, flag;
bool grid[15][15];

int fillGrid(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= N)
		return 0;
	else {
		if (grid[row][col])
			return -1;
		else
			grid[row][col] = true;
		return 1;
	}
}

void NQueen(int col) {
	if (col == N - 1) {
		FOR(i, 0, N)
			if (!grid[i][col]) {
				++cnt;
				break;
			}
		return;
	}

	stack<pair<int, int> > s;

	FOR(i, 0, N) {
		if (grid[i][col])
			continue;
		
		// i 가 row
		grid[i][col] = true;
		FOR(n, 1, N) {
			flag = fillGrid(i - n, col + n);
			if (flag == 0)
				break;
			else if (flag < 0)
				continue;
			else
				s.push(make_pair(i - n, col + n));
		}
		FOR(n, 1, N) {
			flag = fillGrid(i, col + n);
			if (flag == 0)
				break;
			else if (flag < 0)
				continue;
			else
				s.push(make_pair(i, col + n));
		}
		FOR(n, 1, N) {
			flag = fillGrid(i + n, col + n);
			if (flag == 0)
				break;
			else if (flag < 0)
				continue;
			else
				s.push(make_pair(i + n, col + n));
		}

		NQueen(col + 1);

		grid[i][col] = false;
		int len = s.size();
		FOR(i, 0, len) {
			grid[s.top().first][s.top().second] = false;
			s.pop();
		}

	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	NQueen(0);
	cout << cnt << '\n';

	return 0;
}
