#include <iostream>
#include <cmath>
#define FOR(i, n) for(int i = 0; i< (n); ++i)
using namespace std;

int cnt;
int T, n, xpos, ypos, r;
double d1, d2;

typedef struct Point {
	int x; int y;
}Point;

Point p1, p2;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> T;
	FOR(i, T) {
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		cin >> n;
		FOR(j, n) {
			cin >> xpos >> ypos >> r;
			d1 = sqrt((double)((p1.x - xpos) * (p1.x - xpos) + (p1.y - ypos) * (p1.y - ypos)));
			d2 = sqrt((double)((p2.x - xpos) * (p2.x - xpos) + (p2.y - ypos) * (p2.y - ypos)));
			if (d1 < (double)r && d2 < (double)r)
				continue;
			if (d1 < (double)r)
				++cnt;
			if (d2 < (double)r)
				++cnt;
		}
		cout << cnt << '\n';
		cnt = 0;
	}


	return 0;
}
