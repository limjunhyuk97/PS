#include <iostream>
#include <string>
#include <stack>
using namespace std;

int subtractPlate[30], A, cnt;
string str;
string tmp;
stack<int> addPlate;

int main(void) {

	cin >> str;

	for (int i = 0; i < str.size(); ++i) {
		for (int j = i; j < i + 5 && j<str.size(); ++j) {
			// addPlate에 있던 것들 압축해서 subtractPlate으로 옮기기
			if(str[j] == '-'){
				addPlate.push(stoi(tmp));
				tmp.clear();
				while (!addPlate.empty()) {
					subtractPlate[cnt] += addPlate.top();
					addPlate.pop();
				}
				cnt++;
				i = j;
				break;
			}
			// addPlate에 문자를 수로 바꾸어 push 시키기
			else if (str[j] == '+') {
				addPlate.push(stoi(tmp));
				tmp.clear();
				i = j;
				break;
			}
			else {
				tmp += str[j];
				i = j;
			}
		}
	}

	// 마지막 수에 대한 압축과정과 subtractPlate으로 옮기는 과정
	addPlate.push(stoi(tmp));
	while (!addPlate.empty()) {
		subtractPlate[cnt] += addPlate.top();
		addPlate.pop();
	}
	cnt++;

	A = subtractPlate[0];
	for (int i = 1; i < cnt; ++i) {
		A -= subtractPlate[i];
	}

	cout << A << '\n';

	return 0;
}
