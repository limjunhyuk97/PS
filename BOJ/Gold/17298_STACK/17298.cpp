#include <iostream>
#include <stack>
#include <utility>
#define FOR(i, s, e) for(int i=(s); i<=(e); ++i)
using namespace std;

int N, tmp;
int arr[1000005];
stack<pair<int, int>> sArr;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	FOR(i, 1, N) {
		cin >> tmp;
		arr[i] = -1;
		
		if (i == 1) {
			sArr.push(make_pair(tmp, i));
			continue;
		}

		while (!sArr.empty()) {
			if (tmp > sArr.top().first) {
				arr[sArr.top().second] = tmp;
				sArr.pop();
			}
			else
				break;
		}
		sArr.push(make_pair(tmp, i));

	}

	FOR(i, 1, N)
		cout << arr[i] << ' ';
	cout << '\n';


	return 0;
}
