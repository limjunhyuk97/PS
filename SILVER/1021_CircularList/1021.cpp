#include <iostream>
#include <cmath>
#define FOR(i, n, m) for(int i = n; i < m; ++i)
#define MAX(n, m) n > m ? n : m
#define MIN(n, m) n < m ? n : m
using namespace std;

int N, M, bloc = 1, aloc, cnt;
int arr[52];

int shortDist(int loc1, int loc2) {
	int d1 = (MAX(loc1, loc2)) - (MIN(loc1, loc2));
	int d2 = N - d1;
	return MIN(d1, d2);
}

int longDist(int loc1, int loc2) {
	int d1 = (MAX(loc1, loc2)) - (MIN(loc1, loc2));
	int d2 = N - d1;
	return MAX(d1, d2);
}

void move() {
	int tmp = arr[1];
	FOR(i, 2, N + 1)
		arr[i - 1] = arr[i];
	arr[N] = tmp;
}

void pop() {
	FOR(i, 2, N + 1)
		arr[i - 1] = arr[i];
	--N;
}

int findLoc(int num) {
	FOR(i, 1, N + 1)
		if (arr[i] == num)
			return i;
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	FOR(i, 1, N + 1)
		arr[i] = i;

	FOR(i, 0, M) {
		cin >> aloc;
		aloc = findLoc(aloc);
		int min = shortDist(bloc, aloc);
		cnt += min;

		if (i == M - 1) break;

		if (aloc - bloc == min) {
			FOR(i, 0, min)
				move();
			pop();
		}
		else {
			FOR(i, 0, longDist(bloc, aloc))	
				move();
			pop();
		}
	}

	cout << cnt << '\n';

	return 0;
}
