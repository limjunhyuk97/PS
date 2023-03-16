#include <iostream>
#include <algorithm>
#define MAX_COINS 105
#define MAX_K 10005
using namespace std;

int n, k;
int coins[MAX_COINS];
int DP[MAX_K];

// 첫 스타트 코인 얹고
// DP[K] = DP[K] + DP[K-C];
// 여기서 K는 금액, C는 코인 값
int main(void) {
    
    scanf("%d %d", &n, &k);
    
    // 코인 정보
    for(int i=0; i<n; ++i) scanf("%d", &coins[i]);
    
    sort(&coins[0], &coins[n]);
    
    for(int i=0; i<n; ++i) {
        int coin = coins[i];
        if(coin > MAX_K) break;
        DP[coin] += 1;
        for(int j=0; j<=k; ++j) {
            DP[j] += j-coin >= 0 ? DP[j-coin] : 0;
        }
    }
    
    printf("%d\n", DP[k]);
    
    return 0;
}
