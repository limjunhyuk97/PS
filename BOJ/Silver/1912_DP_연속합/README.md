# 수열에서의 최대 연속 합

```cpp
#include <iostream>
using namespace std;

int DP[100004][2];
int N, M = -1005;

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> DP[i][0];

	for (int i = 1; i <= N; ++i) {
		
    // -n m 값 순서대로 연속합 연산을 진행할 때, (... 연산들) -n +m < +m 이라면 아예 연산을 다시 해라!
		if (DP[i - 1][1] + DP[i][0] < DP[i][0])
			DP[i][1] = DP[i][0];
    
    // 그런 상황이 아니라면 계속 더해나가라!
		else
			DP[i][1] = DP[i - 1][1] + DP[i][0];
    
    // Max 값 갱신
		if (DP[i][1] >= M)
			M = DP[i][1];
	}

	cout << M;

	return 0;
}

```
