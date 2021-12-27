#include <iostream>
#include <vector>
using namespace std;

int main(void) {

	long long sum = 0;
	vector<int> arr;
	int K; cin >> K;

	for (int i = 0; i < K; ++i) {
		int tmp; cin >> tmp;
		if (tmp == 0) {
			arr.pop_back();
		}
		else
			arr.push_back(tmp);
	}

	if (arr.size() == 0)
		cout << 0;
	else {
		for (int i = 0; i < arr.size(); ++i) {
			sum += arr[i];
		}
		cout << sum;
	}

	return 0;
}
