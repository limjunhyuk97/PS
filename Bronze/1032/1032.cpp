#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {

	int N; cin >> N;
	int min_len = 100, max_len = 0;
	bool flag = false;
	string* str = new string[N];
	vector<int> idxArr;

	for (int i = 0; i < N; ++i) {
		cin >> str[i];
		if (str[i].size() < min_len)
			min_len = str[i].size();
		if (str[i].size() > max_len)
			max_len = str[i].size();
	}

	for (int j = 0; j < min_len; ++j) {
		char tmp = str[0][j];
		flag = true;
		for (int i = 0; i < N; ++i) {
			if (tmp != str[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			idxArr.push_back(j);
		}
	}

	for (int i = 0; i < max_len; ++i) {
		if (idxArr.size() == 0)
			cout << '?' ;
		else {
			if (i >= idxArr[0] && i <= idxArr.back())
				cout << str[0][i];
			else
				cout << '?';
		}
	}

	delete[]str;

	return 0;
}
