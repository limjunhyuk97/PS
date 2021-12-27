// 시간 범위를 모두 배열로 포용하는 것이 불가능하다.

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool BT[100005];
int N, S, E, T, M;
pair<int, bool> p[100005];

int main(void) {

	cin >> N;
	
	for (int i = 0; i < 100005; ++i)
		p[i].first = -1;

	// p 배열에 값 넣기
	for (int i = 0; i < N; ++i) {
		cin >> S >> E;
		if (p[S].first != -1 && p[S].first < S)
			continue;
		else {
			p[S].first = E;
			p[S].second = true;
		}
		T = max(T, S);
	}

	// p 배열 세팅 완료
	for (int i = T-1; i >= 0; --i) {
		if (p[i].first != -1) {
			T = p[i].first;
			continue;
		}
		else {
			p[i].first = T;
		}
	}

	for (int i = 0; i < 100005; ++i) {
		if (!p[i].second)
			continue;
		T = 0;
		for (int j = i; p[j].first != -1; j = p[j].first) {
			++T;
			p[j].second = false;
		}
		M = max(M, T);
	}

	cout << M << '\n';

	return 0;
}
