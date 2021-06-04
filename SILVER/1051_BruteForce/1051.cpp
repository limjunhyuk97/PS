#include <iostream>
#include <string>
#define FOR(i, n, m) for(int i = n; i < m; ++i)
#define MIN(n, m) (n > m ? m : n)
using namespace std;

string str;
int N, M, Short, D, X = 1;
int arr[52][52];

int main(void) {

	cin >> N >> M;

	FOR(i, 0, N) {
		cin >> str;
		FOR(j, 0, M) {
			arr[i][j] = str[j] - 48;
		}
	}

	Short = MIN(M, N);
		
	FOR(k, 2, Short + 1) {
		D = k - 1;
		FOR(i, 0, N) {
			FOR(j, 0, M) {
				if ((i + D < N) && (j + D < M)) {
					if ((arr[i][j] == arr[i][j + D]) &&(arr[i][j] == arr[i + D][j]) && (arr[i][j] == arr[i + D][j + D]))
						X = D + 1;
				}
			}
		}
	}

	cout << X * X << '\n';

	return 0;
}
