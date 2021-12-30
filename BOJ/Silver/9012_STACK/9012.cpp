#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {

	int T; cin >> T;
	vector<char> arr;

	for (int i = 0; i < T; ++i) {

		string str; cin >> str;

		for (int i = 0; i < str.size(); ++i) {
			if(arr.empty())
				arr.push_back(str[i]);
			else {
				if ((arr.back() == '(') && (str[i] == ')'))
					arr.pop_back();
				else
					arr.push_back(str[i]);
			}
		}

		if (!arr.empty())
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
		
		cin.get();
		arr.clear();
	}

	return 0;
}
