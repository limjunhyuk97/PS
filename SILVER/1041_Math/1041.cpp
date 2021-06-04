#include <iostream>
#define FOR(i, n, m) for(int i=n; i<m; ++i)
#define MINGRID(n, m) (n > m ? m : n)
#define MAXGRID(n, m) (n < m ? m : n)
typedef long long int ll;
using namespace std;

ll N;
ll dice[6];
ll max1, min1 = 150, min2 = 160, min3 = 160;
ll ans;

enum grid { A, B, C, D, E, F };
int min2ArrX[12] = { A, A, A, A, B, B, B, C, C, D, D, E };
int min2ArrY[12] = { B, C, D, E, C, D, F, E, F, E, F, F };
int min3ArrX[8] = { A, A, A, A, F, F, F, F };
int min3ArrY[8] = { B, D, B, C, B, D, B, C };
int min3ArrZ[8] = { D, E, C, E, D, E, C, E };

int main(void) {

	cin >> N;
	
	FOR(i, 0, 6) {
		cin >> dice[i];
		min1 = MINGRID(dice[i], min1);
	}

	FOR(i, 0, 12) {
		min2 = MINGRID((dice[min2ArrX[i]] + dice[min2ArrY[i]]), min2);
	}

	FOR(i, 0, 8) {
		min3 = MINGRID((dice[min3ArrX[i]] + dice[min3ArrY[i]] + dice[min3ArrZ[i]]), min3);
	}

	if (N == 1) {
		FOR(i, 0, 6) {
			max1 = MAXGRID(max1, dice[i]);
			ans += dice[i];
		}
		cout << ans - max1 << '\n';
	}
	else {
		ans += (N - 2) * (N * 5 - 6) * min1;
		ans += (N * 2 - 3) * 4 * min2;
		ans += min3 * 4;
		cout << ans << '\n';
	}

	return 0;
}
