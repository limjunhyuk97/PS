// 규칙성 : 1 ~ N 사이에 존재하는 2 배수의 갯수는 어떻게 구할 것인가?
// - 1 ~ N까지의 수들에 존재하는 2의 갯수
// - 2배수 갯수 + 4배수 갯수 + 8배수 갯수 + ... (N보다 작은)2^K배수 갯수로 세면 된다.

#include <iostream>
#include <utility>
using namespace std;

int N, M, two, five;

int numberOfDivisor(int dividend, int divisor) {
	if (dividend == 0) return 0;
	return dividend / divisor + numberOfDivisor(dividend / divisor, divisor);
}

int main(void) {

	cin >> N >> M;

	two = numberOfDivisor(N, 2) - numberOfDivisor(N - M, 2) - numberOfDivisor(M, 2);
	five = numberOfDivisor(N, 5) - numberOfDivisor(N - M, 5) - numberOfDivisor(M, 5);

	cout << min(two, five) << "\n";

	return 0;
}
