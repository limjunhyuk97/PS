#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N; cin.get();
	queue<int> arr;

	for (int i = 0; i < N; ++i) {
		string str; 
		getline(cin, str);
		if (!str.compare(0, 4, "push")) {
			arr.push(stoi(str.substr(5)));
		}
		else if (!str.compare(0, 3, "pop")) {
			if (arr.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << arr.front() << '\n';
				arr.pop();
			}
		}
		else if (!str.compare(0, 4, "size")) {
			cout << arr.size() << '\n';
		}
		else if (!str.compare(0, 5, "empty")) {
			if (arr.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (!str.compare(0, 5, "front")) {
			if (arr.empty()) {
				cout << -1 << '\n';
			}
			else
				cout << arr.front() << '\n';
		}
		else if (!str.compare(0, 4, "back")) {
			if (arr.empty()) {
				cout << -1 << '\n';
			}
			else
				cout << arr.back() << '\n';
		}
		else {}
	}


	return 0;
}
