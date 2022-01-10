#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
#define FOR(i, n, m) for(int i=n; i<m; ++i)

int T, N, M, K, C;
bool F = true;

struct index {
	int v;
	int i;
};

index tmp;

bool acmp(const index& a, const index& b) {
	return (a.v < b.v);
}

vector<index> arrs;
deque<index> arr;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	
	FOR(i, 0, T) {

		cin >> N >> M;
		F = true;
		C = 0;

		FOR(j, 0, N) {
			cin >> K;
			arrs.push_back({K, j});
			arr.push_back({K, j});
		}

		sort(arrs.begin(), arrs.end(), acmp);

		while (F) {
			FOR(j, 0, arr.size()) {
				if (arr[0].v == arrs.back().v) {
					++C;
					if (arr[0].i == M) {
						F = false;
						break;
					}
					arrs.pop_back();
					arr.pop_front();
				}
				else {
					tmp = arr.front();
					arr.pop_front();
					arr.push_back(tmp);
				}
			}
		}

		cout << C << '\n';

		arrs.clear();
		arr.clear();
	}

	return 0;
}
