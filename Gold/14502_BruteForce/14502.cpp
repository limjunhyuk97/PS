#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int grid[9][9];
int N, M, maxCnt = 0;

int zeroCnt;
vector<pair<int, int> > v0;
vector<pair<int, int> > v2;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void spreadVirus() {

	vector<pair<int, int> > viral;

	for (int i = 0; i < v2.size(); ++i) {
		viral.push_back(v2[i]);
	}

	for (int i = 0; i < viral.size(); ++i) {
		for (int j = 0; j < 4; ++j) {
			if (((0 <= viral[i].first + dx[j]) && (viral[i].first + dx[j] < N)) && ((0 <= viral[i].second + dy[j]) && (viral[i].second + dy[j] < M)) && ((grid[viral[i].first + dx[j]][viral[i].second + dy[j]]) == 0)) {
				grid[viral[i].first + dx[j]][viral[i].second + dy[j]] = 2;
				viral.push_back(make_pair(viral[i].first + dx[j], viral[i].second + dy[j]));
				--zeroCnt;
			}
		}

	}

	maxCnt = max(maxCnt, zeroCnt);

	for (int i = v2.size(); i < viral.size(); ++i) {
		grid[viral[i].first][viral[i].second] = 0;
	}
}

int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 0)
				v0.push_back(make_pair(i, j));
			else if (grid[i][j] == 2)
				v2.push_back(make_pair(i, j));
		}
	}

	zeroCnt = v0.size();
	for (int i = 0; i < zeroCnt; ++i) {
		for (int j = i + 1; j < zeroCnt; ++j) {
			for (int k = j + 1; k < zeroCnt; ++k) {
				grid[v0[i].first][v0[i].second] = 1;
				grid[v0[j].first][v0[j].second] = 1;
				grid[v0[k].first][v0[k].second] = 1;
				zeroCnt -= 3;
				spreadVirus();
				zeroCnt = v0.size();
				grid[v0[i].first][v0[i].second] = 0;
				grid[v0[j].first][v0[j].second] = 0;
				grid[v0[k].first][v0[k].second] = 0;
			}
		}
	}

	cout << maxCnt << "\n";

	return 0;
}
