#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <array>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD1 1000000007
#define MOD2 9100000000000000000
using namespace std;

typedef long long int ll;

ll DP[1000][1000];

ll binomial(int i, int j){
    if(j == 0) return DP[i][j] = 1;
    if(i == j) return DP[i][j] = 1;
    if(DP[i][j] != -1) return DP[i][j];
    return DP[i][j] = (binomial(i-1, j) + binomial(i-1, j-1)) % MOD2;
}

int main(void){
    
    ll n, k;
    scanf("%lld %lld", &n, &k);
    
    for(int i=1; i<1000; ++i){
        for(int j=1; j<1000; ++j){
            DP[i][j] = -1;
        }
    }
    
    // nCk = n-1Ck + n-1Ck-1
    printf("%lld\n", binomial(n,k));
    
    
}
