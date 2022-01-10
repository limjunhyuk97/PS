#include <iostream>
#include <cstring>
#include <vector>
#define FOR(i, m, n) for(int i=m; i <(n); ++i)
#define ll long long
using namespace std;

// 소수의 제곱수들
vector<ll>IExponent(2, 4);
bool BExponent[1000002] = { true, };

void calcIBExp() {
	IExponent[1] = 9;
	FOR(i, 3, 1000001) {
		if (i % 2 != 0 && i % 3 != 0)
			IExponent.push_back((ll)i * i);
	}
}

ll MIN, MAX, GAP, initPos, tmp, cnt;

int main(void) {

	calcIBExp();
	memset(BExponent, false, 1000002);

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> MIN >> MAX;
	GAP = MAX - MIN;
	
	FOR(i, 0, IExponent.size()) {
		if (IExponent[i] > MAX) break;

		if (MIN % IExponent[i] != 0)
			initPos = 1 + (IExponent[i] - MIN % IExponent[i]);
		else
			initPos = 1;
		FOR(j, 0, GAP / IExponent[i] + 1) {
			tmp = initPos + IExponent[i] * j;
			if (tmp <= 1000001)
				BExponent[tmp] = true;
		}
	}

	FOR(i, 1, 2 + GAP)
		if (!BExponent[i])
			++cnt;

	cout << cnt << '\n';

	return 0;
}
