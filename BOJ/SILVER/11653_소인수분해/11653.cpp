#include <iostream>
#include <vector>
using namespace std;
vector <int> arr;

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, cnt = 2;
	cin >> N;

	while (N != 1) {
		if (N % cnt == 0) {
			arr.push_back(cnt);
			N /= cnt;
			continue;
		}
		else
			++cnt;

	}

	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << '\n';
	}

	return 0;

}
