// 종말 지점이 가장 이를수록 더 좋은 선택을 할 수 있다 = 모든 단계에서 공유되는 보편적인 법칙이다.
// 그렇다면, 종말 지점만이 가장 중요한 선택의 기준이라면, 종말 지점을 기준으로 sorting (종말 지점이 가장 이른 순서 + 시작 지점이 가장 이른 순서)
// 종말 지점을 바탕으로 다음 단계를 고르는데, 시작 지점 또한 정렬되있기 때문에 고르는 데에 문제가 없다.

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool flag = true;
int N, M, m, s, e, i;
pair<int, int> p[100005];

struct firstSecondDesc {
	bool operator()(pair<int, int>p1, pair<int, int>p2) {
		if (p1.second != p2.second)
			return p1.second < p2.second;
		else
			return p1.first < p2.first;
	}
}firstSecondAsc;

int main(void) {

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> s >> e;
		p[i].first = s;
		p[i].second = e;
	}

	sort(&p[0], &p[N], firstSecondAsc);
	
	while(flag) {
		m = p[i].second;
		++M; flag = false;
		for (int j = i + 1; j < N; ++j) {
			if (m <= p[j].first) {
				i = j; flag = true;
				break;
			}
		}
	}

	cout << M << '\n';

	return 0;
}
