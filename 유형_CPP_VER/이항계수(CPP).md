# 이항계수

## DP

- 가장 기본적인 풀이
- **nCm = n-1Cm-1 + n-1Cm** 을 이용한다

```cpp
#define M 1003
#define N 1003

int DP[M][N];

int solve(int M, int N) {
    int *ret = &DP[M][N];
    
    if(*ret != 0) return DP[M][N];
    if(M == N || N == 0) return 1;
    *ret = (solve(M-1, N-1) + solve(M-1, N));
    return *ret;
}

```

## 분할정복 / 페르마 정리 / 합동 정리

- DP 풀이에서 수의 범위가 커지는 경우 도입 가능 (mod 연산이 적용되는 경우.)
    - **nCm의 n과 m 값이 DP를 사용할 수 없을 정도로 크다면?**
- **nCm = n!/(n-m)!m! (mod P)** 을 이용한다.

### 페르마 정리 / 합동 정리

- 페르마 정리
    - 정수 a, 소수 p 에 대해서 a^p = a (mod p)
    - **정수 a, 소수 p 에 대해서 a와 p가 서로소라면 a^(p-1) = 1 (mod p)**
- 합동 정리
    - a = b (mod p) 일 때 ac = bc (mod p).
    - a = b (mod p) 일 때 a+c = b+c (mod p).
    - a = b (mod p) 일 때 a/c = b/c (mod d). d는 gcd(p, c)
- n!/(n-m)!m! 를 연산하기 위해서 필요하다.
    - n!/(n-m)!m! = n! * {(n-m)!m!}^(-1) = n! * {(n-m)!m!}^(P-2) (mod P)

### 분할 정복

- n^k 의 연산에서 적용할 수 있다.
    - k가 2로 나눠지면 : n^k = n^(k/2) * n^(k/2)
    - k가 2로 나눠지지 않으면 : n^k = n^(k/2) * n^(k/2) * n
- 즉, **k가 너무 크다면, k를 분할하여 연산 수를 1/2 혹은 1/3, 1/4로 줄일 수 있다.** (중복되는 연산을 줄인다.)

```cpp
#include <iostream>
#define MAXLEN 4000005
#define MOD 1000000007
using namespace std;

typedef long long int ll;

// 팩토리얼 연산 bottom-up 저장
ll permutationCongruence[MAXLEN];
void setPermutationCongruence() {
    permutationCongruence[0] = 1;
    for(ll i=1; i<MAXLEN; ++i) {
        permutationCongruence[i] = permutationCongruence[i-1] * i % MOD;
    }
}

// 거듭제곱 분할 정복 : num^n = (num^(n/2))^2 * num or (num^(n/2))^2
ll moduloCongruence(ll num, ll n) {
    if(n == 1) return num % MOD;
    else if(n == 2) return num * num % MOD;
    ll temp = moduloCongruence(num, (ll)n/2);
    temp = temp * temp % MOD;
    return n % 2 == 0 ? temp : temp * num % MOD;
}

int main(void) {
    
    ll M = 0, N = 0, K = 0;
    cin >> M;
    
    setPermutationCongruence();
    
    for(int i=0; i<M; ++i) {
        scanf("%lld %lld", &N, &K);
        ll NFactorial = permutationCongruence[N];
        ll KFactorial = permutationCongruence[K];
        ll N_KFactorial = permutationCongruence[N-K];
        printf("%lld\n", NFactorial * moduloCongruence(KFactorial * N_KFactorial % MOD, MOD-2) % MOD);
    }
    
    return 0;
}

```

## 뤼카 정리

- 분할정복, 페르마 정리, 합동정리로도 감당할 수 없는 수의 범위일 때 사용할 수 있다.
    - 위의 방법들은 n!이 기본적으로 감당할 때 사용할 수 있다.
    - 만약 **n!이 감당할 수 없게 크다면 어떻게 할 것인가?**
    - **mod P일 경우, P로 n과 k를 진법변환 한 뒤, nCk를 작은 조합들의 곱으로 바꾼다.**
- **NCK에서 N과 K를 p 진법으로 진법 변환한다.**
    - N = Nm \* p^(m) + Nm-1 \* p^(m-1) + Nm-2 \* p^(m-2) + ...
    - K = Km \* p^(m) + Km-1 \* p^(m-1) + Km-2 \* p^(m-2) + ...
- 이 때, **NCK = NmCKm \* Nm-1CKm-1 \* Nm-2CKm-2 \* ... (mod P)**와 같다.


```cpp
#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

typedef long long int ll;

ll N, K, M;

// 진법 변환
void conversion(deque<int> & dq, ll num, ll dest) {
    while(num) {
        dq.push_front((int)(num % dest));
        num /= dest;
    }
}

// 이항계수
int DP[2005][2005];
int solve(int N, int K, int M) {
    int *ret = &DP[N][K];
    if(*ret) return *ret;
    if(N==K || K==0) return 1;
    if(N==0) return 0;
    *ret = (solve(N-1, K-1, M) +solve(N-1, K, M)) % M;
    return *ret;
}

int main(void) {
    
    scanf("%lld %lld %lld", &N, &K, &M);
    
    deque<int> NtoM, KtoM;
    conversion(NtoM, N, M);
    conversion(KtoM, K, M);
    
    // 앞자리 0 맞추기
    int gap = (int)(NtoM.size()-KtoM.size());
    for(int i=0; i<gap; ++i) KtoM.push_front(0);
    
    // 뤼카 정리 사용한 계산
    int res = 1;
    for(int i=0; i<NtoM.size(); ++i) {
        res *= solve(NtoM[i], KtoM[i], (int)M);
        res %= M;
    }
    
    printf("%d\n", res);
    
    return 0;
}

```
