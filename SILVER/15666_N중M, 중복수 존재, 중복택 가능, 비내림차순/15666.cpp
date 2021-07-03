#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int N, M, tmp;
// numberSet에 insert 되는 key 값이 연속되지 않으면, 떨어진 부분들에는 valuerk 0인 key들이 채워진다.
map<int, int> numberSet;
vector<int> s;

void pick(int cnt) {

	if (cnt == 0) {
		for (int i = 0; i < s.size(); ++i)
			cout << s[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = 0; i < numberSet.size(); ++i) {
		if (s.empty() && numberSet[i] != 0) {
			s.push_back(i);
			pick(cnt - 1);
			s.pop_back();
		}
		else {
			if (numberSet[i] != 0 && s[s.size() - 1] <= i) {
				s.push_back(i);
				pick(cnt - 1);
				s.pop_back();
			}
		}
	}

}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		numberSet[tmp]++;
	}

	pick(M);

	return 0;
}
