// cpp string parsing 사용됨

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int T, vsize, rcnt;
size_t previous = 0, current = 0;
bool flag;
string command, arr;
deque<int> v;

int main(void) {

	cin >> T;

	while (T--) {

		v.clear();
		cin >> command >> vsize >> arr;

		if (vsize != 0) {
			previous = 1; current = arr.find(',');
			while (current != string::npos) {
				v.push_back(stoi(arr.substr(previous, current - previous)));
				previous = current + 1;
				current = arr.find(',', previous);
			}
			v.push_back(stoi(arr.substr(previous, current - previous)));
		}

		flag = true; rcnt = 0;
		for(int i=0;i<command.size();++i){
			if (command[i] == 'R') {
				++rcnt;
			}
			else {
				if (v.empty()) {
					flag = false;
					cout << "error" << "\n";
					break;
				}
				if (rcnt % 2 == 1) {
					v.pop_back();
				}
				else {
					v.pop_front();
				}
			}
		}

		if (flag) {
			if (!v.empty()) {
				if (rcnt % 2 == 0) {
					cout << '[' << v[0];
					for (int i = 1; i < v.size(); ++i)
						cout << ',' << v[i];
					cout << ']' << '\n';
				}
				else {
					cout << '[' << v[v.size() - 1];
					for (int i = v.size() - 2; i >= 0; --i)
						cout << ',' << v[i];
					cout << ']' << '\n';
				}
			}
			else cout << "[]" << "\n";
		}

	}

	return 0;
}
