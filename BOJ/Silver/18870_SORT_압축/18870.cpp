#include <iostream>
#include <algorithm>
#define FOR(i, n) for(int i=0; i<(n); ++i)
using namespace std;

class Tr {
public:
	int num;
	int bIDX;
	int aIDX;
public:
	Tr() {}
	Tr(int num, int b, int a) :num(num), bIDX(b), aIDX(a) {}

	bool operator<(const Tr& tr) {
		return this->bIDX < tr.bIDX;
	}

	friend bool comp(const Tr& tr1, const Tr& tr2);
};

bool comp(const Tr& tr1, const Tr& tr2) {
	return tr1.num < tr2.num;
}

Tr* pArr;
int T, X, cnt;

int main(void) {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> T;
	pArr = new Tr[T];

	FOR(i, T) {
		cin >> X;
		pArr[i] = Tr(X, i, 0);
	}

	sort(pArr, pArr + T, comp);

	FOR(i, T) {
		if (i == 0) {
			pArr[i].aIDX = cnt;
			continue;
		}

		if (pArr[i].num != pArr[i-1].num) {
			pArr[i].aIDX = ++cnt;
		}
		else {
			pArr[i].aIDX = cnt;
		}
	}

	sort(pArr, pArr + T);

	FOR(i, T) {
		cout << pArr[i].aIDX << ' ';
	}

	delete[] pArr;

	return 0;
}
