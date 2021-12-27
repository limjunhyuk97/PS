#include <iostream>
#include <map>
#include <string>
using namespace std;

int T, N, A;
map<string, int>::iterator iter;

int main(void) {
	
	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> N;

		map<string, int> wardrobe;
		for (int j = 0; j < N; ++j) {
			string name; cin >> name >> name;
			wardrobe[name]++;
		}

		A = 1;
		for (iter = wardrobe.begin(); iter != wardrobe.end(); ++iter) {
			A *= iter->second + 1;
		}

		cout << A - 1 << "\n";

	}

	return 0;
}
