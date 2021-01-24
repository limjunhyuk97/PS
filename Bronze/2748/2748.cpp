#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);

	long long n[91] = {0 , 1, };
	int num;
	cin >> num;

	if (num > 1) {
		for (int i = 2; i <= num; ++i) {
			n[i] = n[i - 1] + n[i - 2];
		}
		cout << n[num];
		return 0;
	}
	else {
		if (num == 1)
			cout << 1;
		return 0;
	}

}
