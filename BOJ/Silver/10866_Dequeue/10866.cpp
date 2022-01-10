#include <iostream>
#include <string>
#define FOR(i, n, m) for(int i=(n); i<=(m); ++i)
using namespace std;

int arr[20015], N, K,s=10005, e=10004;
string str;
// cin>>string : whitespace 단위로 string에게 할당
// str1.compare(str2) str1과 str2 비교 

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	FOR(i, 1, N) {
		cin >> str;
		if (str.compare("push_front") == 0) {
			cin >> K;
			arr[--s] = K;
		}
		else if (str.compare("push_back") == 0) {
			cin >> K;
			arr[++e] = K;
		}
		else if (str.compare("pop_front") == 0) {
			if (e<s)
				cout << -1 << '\n';
			else
				cout << arr[s++] << '\n';
		}
		else if (str.compare("pop_back") == 0) {
			if (e<s)
				cout << -1 << '\n';
			else
				cout << arr[e--] << '\n';
		}
		else if (str.compare("size") == 0) {
			if (e < s)
				cout << 0 << '\n';
			else
				cout << e - s + 1 << '\n';
		}
		else if (str.compare("empty") == 0) {
			if (e < s)
				cout << '1' << '\n';
			else
				cout << '0' << '\n';
		}
		else if (str.compare("front") == 0) {
			if (e < s)
				cout << -1 << '\n';
			else
				cout << arr[s] << '\n';
		}
		else if (str.compare("back") == 0) {
			if (e < s)
				cout << -1 << '\n';
			else
				cout << arr[e] << '\n';
		}
		else {}
	}


	return 0;
}
