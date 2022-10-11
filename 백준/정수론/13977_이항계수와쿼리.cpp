// nCk = n! (k!(n-k)!)^(M-1) (mod M)

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

