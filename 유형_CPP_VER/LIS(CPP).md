#  LIS (최장 증가 부분 수열)

## DP를 사용한 해결법

- N^2의 시간이 소요된다.
- A1, A2, A3, ... 수열에서, DP[An] 은 n으로 끝나는 가장 긴 LIS의 길이라고 정의한다.
- 이때 DP[An]의 값은 : **DP[An] = max(DP[1], DP[2], ... , DP[An-1]) + 1** 이다.

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int DP[1005];
int arr[1005];

int main(void) {
    
    scanf("%d", &N);
    
    int MAXDP = 1;
    for(int i=0; i<N; ++i) {
        int tmp; scanf("%d", &tmp);
        
        DP[tmp] = 1;
        arr[i] = tmp;
        
        for(int j=0; j<i; ++j) {
            if(tmp > arr[j]) DP[tmp] = max(DP[tmp], DP[arr[j]] + 1 );
        }
        
        MAXDP = max(MAXDP, DP[tmp]);
    }
    
    printf("%d\n", MAXDP);
    
    return 0;
}

```



## 이분탐색을 활용한 해결법

- N\*logN의 시간이 소요된다.
- A1, A2, A3 .. 수열에서, 숫자를 하나씩 읽어들이며 오름차순 LIS를 만들어나간다.
    - 기존 LIS 배열이 비어있거나, LIS 배열 끝에 있는 수보다 큰 수가 들어오면 맨 뒤에 붙힌다.
    - 위의 경우가 아니라면, 새로들어온 수의 lower\_bound 인덱스를 찾아서 해당 LIS 배열 내 값을 대체해준다.
        - lower\_bound는 처음으로 등장하는 n 이상의 수를 찾는데 사용하며
        - upper\_bound는 처음으로 등장하는 n 초과의 수를 찾는데 사용한다.
- 이때, LIS 정보를 담고 있는 LIS vector는 실제 LIS 원소를 담고 있지 않을 수 있다는 것에 주의해야 한다. 

### LIS 길이 구하기

```
// LIS (이분 탐색)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> LIS;

int main(void) {
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        int cur; scanf("%d", &cur);
        
        if(LIS.empty()) LIS.push_back(cur);
        else {
            if(LIS.back() < cur) LIS.push_back(cur);
            else {
                int pos = (int)(lower_bound(LIS.begin(), LIS.end(), cur) - LIS.begin());
                LIS[pos] = cur;
            }
        }
    }
    
    printf("%d\n", (int)LIS.size());

    return 0;
}

```

### LIS 원소 모두 출력하기

- A1, A2, A3 .. 로 이뤄진 수열을 읽어가며 LIS를 조합하는 위 과정에서 각 원소들의 LIS 상에서의 위치를 P 배열에 저장해주어야 한다.
- 그리고 P배열을 뒤에서부터 읽어주며 가장 뒤 인덱스 부터 0 인덱스까지 원소를 원본 배열에서 읽어나간다.

예시

-기존 배열-
3 2 5 2 3 1 4

-LIS 생성 과정 / P 배열에 들어가는 값-
원소값(인덱스)

LIS             | P
3(0)            | 1 0 0 0 0 0 0
2(1)            | 1 1 0 0 0 0 0
2(1) 5(2)       | 1 1 2 0 0 0 0
2(3) 5(2)       | 1 1 2 1 0 0 0
2(3) 3(4)       | 1 1 2 1 2 0 0
1(5) 3(4)       | 1 1 2 1 2 1 0
1(5) 3(4) 4(6)  | 1 1 2 1 2 1 3

-P배열에서 원소 찾기-
P
1 1 2 1 2 1 3

뒤에서 읽어가면서
3(인덱스 6 : 기존 배열 값 4) -> 2(인덱스 4 : 기존 배열 값 3) -> 1(인덱스 3 : 기본 배열 값 2)

때문에 요소는
2 3 4



