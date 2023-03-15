#include <iostream>
#include <cmath>
#define MOD 10007

typedef long long int ll;
using namespace std;

int N;

int main(void) {
    
    scanf("%d", &N);
    
    if(N < 5) printf("%d\n", N);
    
    // 3을 기준으로 쪼갠다. 남은 수는 2 ~ 4이면 된다. 그래서 5이상인 수는 다 3으로 쪼갠다.
    // 2와 3이 소수라는 사실을 생각해보자.
    else {
        ll result = 1;
        while(N > 4) {
            result = result * 3 % MOD;
            N -= 3;
        }
        result = result * N % MOD;
        printf("%lld\n", result);
    }
    
    return 0;
}
