#include <iostream>
#include <vector>
using namespace std;

int N, s;
long long int T;
vector<long long int> oilFee;
vector<long long int> roadDistance;

int main(void) {

	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		cin >> T;
		roadDistance.push_back(T);
	}
	for (int i = 0; i < N; ++i) {
		cin >> T;
		oilFee.push_back(T);
	}

	T = 0;
	for (int i = 0; i < N - 1; ++i) {
		s = i;
		for (int j = i; j < N - 1; ++j) {
      // oilFee[s]를 oilFee[i]라 한다면, i가 계속 바뀌기 때문에 문제가 생길 수 있다.
			if (oilFee[s] <= oilFee[j]) {
				i = j;
				continue;
			}
			else
				break;
		}
		for (int j = s; j <= i; ++j) {
			T += (roadDistance[j] * oilFee[s]);
		}
	}

	cout << T << '\n';

	return 0;
}
