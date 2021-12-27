#include <iostream>
using namespace std;

int main(void) {

	int N, M; cin >> N >> M;
	int min = N >= M ? M : N;
	int GCD = 0;

	int cnt = 0;
	while (cnt <= N && GCD <=N) {
		++cnt;
		if ((N % cnt == 0) && (M % cnt == 0)) {
			GCD = cnt;
		}
	}
	cout << GCD << '\n';
	cout << (N / GCD) * M;

	return 0;
}
