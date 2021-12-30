#include <iostream>
#include <functional>
#include <queue>
#define FOR(i , n) for(int i=0; i < (n); ++i)
using namespace std;

int T, I;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue< int, vector<int>, less<int> > pq;

	cin >> T;
	FOR(i, T) {
		cin >> I;
		if (I > 0)
			pq.push(I);
		else
			if (pq.empty())
				cout << '0' << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
	}

	return 0;
}
