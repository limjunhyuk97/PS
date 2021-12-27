#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
private:
	vector<int> arr;
public:
	void Branch(int n) { 
		for (int i = 0; i < n; ++i) {
			string str;
			getline(cin, str);
			
			if (!str.compare(0, 4, "push")) {
				string substring = str.substr(5);
				this->arr.push_back(stoi(substring));
			}
			else if (!str.compare(0, 3, "pop")) {
				if (this->arr.size() == 0)
					cout << -1 << '\n';
				else {
					cout << this->arr.back() << '\n';
					this->arr.pop_back();
				}
			}
			else if (!str.compare(0, 4, "size")) {
				cout << this->arr.size() << '\n';
			}
			else if (!str.compare(0, 5, "empty")) {
				if (this->arr.size() == 0)
					cout << 1 << '\n';
				else
					cout << 0 << '\n';
			}
			else if (!str.compare(0, 3, "top")) {
				if (this->arr.size() == 0)
					cout << -1 << '\n';
				else
					cout << arr.back() << '\n';
			}
			else {}
		}
	}

};

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N; cin.get();
	Stack stack; stack.Branch(N);

	return 0;
}
