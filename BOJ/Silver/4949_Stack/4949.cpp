#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {

		string str; stack <char> bracket;
		getline(cin, str);
		if (str[0] == '.')
			break;

		for (int i = 0; i < str.size(); ++i) {
			if (bracket.empty() && (str[i] == '(' || str[i] == '[' || str[i] == ']' || str[i] == ')')) {
				bracket.push(str[i]);
			}
			else if (!bracket.empty() && (str[i] == '(' || str[i] == '[' || str[i] == ']' || str[i] == ')')) {
				if (bracket.top() == '[' && str[i] == ']') bracket.pop();
				else if (bracket.top() == '(' && str[i] == ')') bracket.pop();
				else bracket.push(str[i]);
			}
			else {}
		}

		if (bracket.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';

	}


	return 0;
}
