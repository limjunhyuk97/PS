#include <iostream>
#include <algorithm>
#define MOD 10007
using namespace std;

int N;
int DP[1005];

int main(void) {
    
    scanf("%d", &N);
    
    // DP연산
    DP[0] = 1;
    DP[1] = 1;
    for(int i=2; i<=N; ++i) {
        DP[i] = (DP[i-1] + DP[i-2]) % MOD;
    }
    
    cout << DP[N]<< endl;
    
    return 0;
}
