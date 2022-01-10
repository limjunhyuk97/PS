#include <iostream>
#include <vector>
#include <utility>
#define FOR2(i, n) for(int i = 0; i < (n); ++i)
#define FOR3(i, n, m) for(int i = n; i < (m); ++i)
using namespace std;

int grid[9][9], tmp, zVSize;
vector<pair<int, int> >zVPair;

bool check(int x, int y, int num) {
	FOR2(i, 9) {
		if (grid[x][i] == num || grid[i][y] == num)
			return false;
	}
	
	FOR3(i, 3* (x/3), 3*(x/3) + 3) {
		FOR3(j, 3*(y/3), 3*(y/3) + 3) {
			if (grid[i][j] == num) return false;
		}
	}
	return true;
}

bool DFS(int n) {
	if (n >= zVSize)return true;
	FOR3(i, 1, 10) {
		if (check(zVPair[n].first, zVPair[n].second, i)) {
			grid[zVPair[n].first][zVPair[n].second] = i;
			if (DFS(n + 1)) return true;
			grid[zVPair[n].first][zVPair[n].second] = 0;
		}
	}
	return false;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	FOR2(i, 9) {
		FOR2(j, 9) {
			cin >> tmp; 
			grid[i][j] = tmp;
			if (tmp == 0) zVPair.push_back(make_pair(i, j));
		}
	}
	zVSize = zVPair.size();

	DFS(0);

	FOR2(i, 9) {
		FOR2(j, 9) {
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
