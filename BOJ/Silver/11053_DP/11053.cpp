#include <iostream>
#include <vector>
#define FOR(i, n, m) for(int i = n; i < m; ++i)
#define MAXNUM(n, m) (n > m ? n : m)
using namespace std;

int arr[1005];
int N, T, M;
vector <int> insert;

int main(void) {

	cin >> N;
	FOR(i, 1, N + 1) {
		cin >> T;
		FOR(j, 0, insert.size()) {
			if (T > insert[j])
				arr[T] = MAXNUM(arr[T], arr[insert[j]] + 1);
		}
		insert.push_back(T);
		M = MAXNUM(M, arr[T]);
	}

	cout << M + 1;

	return 0;
}
