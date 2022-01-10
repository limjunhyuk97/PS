// 1. 규칙성의 발견 -> 불규칙적인 규칙성도 존재. 규칙성 발견 어려움
// 2. 굉장히 큰 수 -> DP로 구하기에도 너무 크다 -> 분할 정복
// 3. 어떻게 분할, 정복 할 것인가?
//		- 분할 : 지수를 2로 나누어 분할
//		- 정복 : 지수를 2로 나누어 구한 값을 다시 제곱시키며 정복
//		- 효과 : 여러번의 재귀적 호출을 극복 가능

#include <iostream>
using namespace std;
typedef long long int ll;

ll A, B, C;

ll remainder(ll a, ll b, ll c) {

	if (b == 0)
		return 1;
	else if (b == 1)
		return a % c;
	else {
		if (b % 2 == 0) {
			ll ret = remainder(a, b / 2, c);
			return ret * ret % c;
		}
		else {
			return a * remainder(a, b-1, c) % c;
		}
	}

}

int main(void) {

	cin >> A >> B >> C;

	cout << remainder(A, B, C) << "\n";

	return 0;
}
