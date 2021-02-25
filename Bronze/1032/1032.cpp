#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {

	int N; cin >> N;
	int len;
	bool flag = false;
	string* str = new string[N];
	vector<int> idxArr;

	for (int i = 0; i < N; ++i) {
		cin >> str[i];
	}

	len = str[0].size();

	for (int j = 0; j < len; ++j) {
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

	for (int i = 0; i < len; ++i) {
		if (idxArr.size() == 0)
			cout << '?' ;
		else {
			flag = true;
			for (int j = 0; j < idxArr.size(); ++j) {
				if (idxArr[j] == i) {
					flag = false;
					cout << str[0][i];
					break;
				}
			}
			if(flag)
				cout << '?';
		}
	}

	delete[]str;

	return 0;
}
