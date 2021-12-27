#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str1, str2;
int DP[1001][1001];

// str2를 기준으로 str1과 비교한다.
// (str2 문자, str1 문자)에 대해서 DP 최대값을 유지해 준다.
// n 번째 str2 문자 == m 번째 str1 문자일 경우 : n-1, m-1 의 DP수 + 1
// n 번째 str2 문자 != m 번째 str1 문자일 경우 : (n, m-1의 DP수) , (n-1, m의 DP수) 중 MAX
// 먹은 문자를 최대한 앞당기는 방법..!
int main(void) {

	cin >> str1 >> str2;

	for (int i = 1; i <= str2.size(); ++i) {
		for (int j = 1; j <= str1.size(); ++j) {
			if (str2[i-1] == str1[j-1]) DP[i][j] = DP[i - 1][j - 1] + 1;
			else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	cout << DP[str2.size()][str1.size()] << '\n';

	return 0;
}
