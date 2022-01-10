#include <iostream>
#include <string>
using namespace std;

string str1, str2, ans;

int main(void) {

	cin >> str1 >> str2;
	int len;
	
	// str2 > str1
	if (str1.size() < str2.size()) {
		int tmp = str1.size();
		len = str2.size();
		int end = len;
		str1.resize(len);
		while (tmp != 0) {
			str1[--end] = str1[--tmp];
		}
		for (int i = 0; i < end; ++i)
			str1[i] = '0';

	}

	// str1 > str2
	else if (str1.size() > str2.size()) {
		int tmp = str2.size();
		len = str1.size();
		int end = len;
		str2.resize(len);
		while (tmp != 0) {
			str2[--end] = str2[--tmp];
		}
		for (int i = 0; i < end; ++i)
			str2[i] = '0';
	}
	else {
		len = str1.size();
	}
	ans.resize(len + 1, '0');

	for (int i = len; i >= 1; --i) {
		int tmp = (ans[i] - 48) + (str1[i - 1] - 48) + (str2[i - 1] - 48);
		if (tmp >= 10) {
			ans[i] = tmp + 38;
			ans[i - 1] = 49;
		}
		else {
			ans[i] = tmp + 48;
		}
	}

	if (ans[0] == '0')
		cout << ans.substr(1);
	else
		cout << ans;

	return 0;
}
