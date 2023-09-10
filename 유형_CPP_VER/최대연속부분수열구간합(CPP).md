# 연속 부분 수열의 최대 구간합 구하기

## 카데인 알고리즘

### [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/161988) 연속 펄스 부분 수열의 합

- 카데인 알고리즘 활용 (O(n))
- 원소 하나씩 고려하면서 (0번째 인덱스 ~ n번째 인덱스) 구간의 구간합을 구하기 시작
- 만약 중도에 (0번째 인덱스 ~ n번째 인덱스) 구간합이 음수로 떨어지면 누적합 0으로 바꾸고, 해당 인덱스부터 구간합 다시 구하기 시작
- 누적합 구해질때마다 최대 연속 부분 수열 구간합 값 갱신

```cpp
// 카데인 알고리즘
#include <string>
#include <vector>

using namespace std;

typedef long long int ll;

long long solution(vector<int> sequence) {
    long long answer = 0;

    int size = (int)sequence.size();

    ll accSumForPulse1 = 0, accSumForPulse2 = 0;
    for(int i=0; i<size; ++i) {
        ll valueForPulse1 = sequence[i] * (i % 2 == 0 ? 1 : -1);
        ll valueForPulse2 = sequence[i] * (i % 2 == 0 ? -1 : 1);

        accSumForPulse1 += valueForPulse1;
        accSumForPulse2 += valueForPulse2;

        if(accSumForPulse1 < 0) accSumForPulse1 = 0;
        if(accSumForPulse2 < 0) accSumForPulse2 = 0;

        answer = answer < accSumForPulse1 ? accSumForPulse1 : answer;
        answer = answer < accSumForPulse2 ? accSumForPulse2 : answer;
    }

    return answer;
}
```
