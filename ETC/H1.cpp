#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

int N;
ll DP[105];

// DP
// DP[n] = max(DP[1] * DP[n-1], DP[2] * DP[n-2], ... )

int main(void){
    
    scanf("%d", &N);
    DP[1]=1;
    DP[2]=1;
    
    if(N > 2) {
        for(ll i=3; i<=N; ++i) {
            for(ll j=1; j<=i/2; ++j) {
                DP[i] = max( max(DP[i-j], i-j) * max(DP[j], j) , DP[i]);
            }
        }
    }
    
    printf("%lld\n", DP[N]);
    
    return 0;
}

// DP[1] * DP[1] = DP[2] = 1 : DP[2] 까지 완료
// DP[1] * DP[2] = DP[3] =  : DP[3] 까지 완료
// DP[1] * DP[3]
