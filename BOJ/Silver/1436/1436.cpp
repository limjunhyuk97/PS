#include <iostream>
#include <string>
using namespace std;

int main(void) {

	int n, num = 666, cnt = 0;
	cin >> n;

	while (1) {

		string str;
		str = to_string(num);

		for (int i = 0; i <= str.length() - 3; ++i) {
			if (str.substr(i, 3) == "666") {
				++cnt;
				break;
			}
			else continue;
		}

		if (cnt == n) break;
		else ++num;
	}

	cout << num;

	return 0;
}
