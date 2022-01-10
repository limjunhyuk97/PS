// 시간 초과 (모든 회의 조합을 시간 내에 고려하는 것은 불가능)

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

struct node {
	int first;
	int second;
	bool check;
};

struct comp {
	bool operator()(node &p1, node &p2) {
		if (p1.first != p2.first)
			return p1.first < p2.first;
		else {
			return p1.second < p2.second;
		}
	}
}comp;

node p[100005];
bool F;
int N, S, E, MS, M, T;

void pick(int startIdx) {

	if (T == 0) {
		if(p[startIdx].check)
			return;
	}

	p[startIdx].check = true;
	for (int i = startIdx; i <N; ++i) {
		if (p[i].first >= p[startIdx].second) {
			++T;
			pick(i);
			--T;
		}
	}
	M = max(M, T + 1);
	return;
}

int main(void) {

	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		cin >> S >> E;
		p[i].first = S;
		p[i].second = E;
		MS = max(MS, S);
	}

	sort(&p[0], &p[N], comp);

	for (int i = 0; i < N; ++i)
		pick(i);
	
	cout << M << '\n';

	return 0;
}
