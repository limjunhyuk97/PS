#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int N;
int cnt = 0;
bool grid[26][26];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

typedef struct point {
	int x;
	int y;
}point;

vector<point> pArr;
vector<int> cntArr;

bool housing(int x, int y) {
	if (grid[x][y] == false) return false;
	if (x < 0 || y < 0 || x >= N || y >= N) return false;
	grid[x][y] = false;
	++cnt;
	FOR(i, 4) housing(x + dx[i], y + dy[i]);
	return true;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string row;
	cin >> N;
	FOR(i, N) {
		cin >> row;
		FOR(j, N) {
			if (row[j]-48 == 0) continue;
			grid[i][j] = true;
			point tmp = { i, j };
			pArr.push_back(tmp);
		}
	}

	FOR(i, pArr.size()) {
		cnt = 0;
		housing(pArr[i].x, pArr[i].y);
		if (cnt != 0) cntArr.push_back(cnt);
	}

	sort(cntArr.begin(), cntArr.end());
	cout << cntArr.size() << '\n';
	FOR(i, cntArr.size()) cout << cntArr[i] << '\n';

	return 0;
}
