#include <iostream>
#include <vector>
#include <utility>
#define FOR(i, n) for(int i=0; i <(n); ++i)
using namespace std;

int N, K, cnt, j;
vector<pair<int, bool>> arr;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	FOR(i, N)
		arr.push_back(make_pair(i+1, false));

	cout << '<';
	FOR(i, N) {
		if (i != 0)
			cout << ", ";

		while (true) {
			if (!arr[j].second)
				++cnt;
			if (cnt == K) {
				arr[j].second = true;
				break;
			}
			++j;
			if (j == N)
				j = 0;
		}
		cout << arr[j].first;
		cnt = 0;
	}
	cout << '>'<<'\n';

	return 0;
}
