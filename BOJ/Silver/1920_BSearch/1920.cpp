#include <iostream>
#include <algorithm>
#define FOR(i, n) for(int i=0; i<(n); ++i)
using namespace std;

int NArr[100000];
int MArr[100000];

int N, M, s, e, flag, pivot;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i, N) cin >> NArr[i];

	cin >> M;
	FOR(i, M) cin >> MArr[i];

	sort(NArr, NArr + N);

	FOR(i, M) {
		flag = 0; s = 0; e = N - 1;
		while (s <= e) {
			pivot = (s + e) / 2;
			if (NArr[pivot] == MArr[i]) {
				flag = 1;
				break;
			}
			else if (NArr[pivot] > MArr[i]) {
				e = pivot - 1; continue;
			}
			else {
				s = pivot + 1; continue;
			}
		}
		cout << flag << '\n';
	}

	return 0;
}
