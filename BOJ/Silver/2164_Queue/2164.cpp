#include <iostream>
#include <queue>
#define FOR(i, n, m) for(int i = n ; i < m; ++i)
using namespace std;

int N, ret;
queue<int> que;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	FOR(i, 1, N+1)
		que.push(i);

	while (true) {
		ret = que.front();
		que.pop();
		if (que.empty())
			break;

		ret = que.front();
		que.pop();
		que.push(ret);
	}

	cout << ret<<'\n';


	return 0;
}
