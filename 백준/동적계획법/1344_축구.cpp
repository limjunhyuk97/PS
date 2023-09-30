#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;
typedef long double ld;

ll DP[20][20];

ll getCombination(int n, int m) {
    if(m == n) return DP[n][m] = 1;
    if(m == 1) return DP[n][m] = n;
    if(m == 0) return DP[n][m] = 1;
    
    return DP[n][m] = (DP[n][m] == 0 ? getCombination(n-1, m) + getCombination(n-1, m-1) : DP[n][m]);
}

ld getPower(ld n, int k) {
    if(k > 1) return n * getPower(n, k-1);
    else if (k == 1) return n;
    else return 1;
}

int main(void) {
    
    int a, b;
    cin >> a >> b;
    
    ld pa = a/(ld)100;
    ld paMinus1 = 1-pa;
    ld pb = b/(ld)100;
    ld pbMinus1 = 1-pb;
    
    int nonPrimeSet[12] = {0, 1, 4, 6, 8 ,9, 10, 12, 14, 15, 16, 18};
    
    ld antiSetA = 0;
    ld antiSetB = 0;
    
    for(int i=0; i<12; ++i) {
        int cnt = nonPrimeSet[i];
        antiSetA += (ld)getCombination(18, cnt) * getPower(pa, cnt) * getPower(paMinus1, 18-cnt);
        antiSetB += (ld)getCombination(18, cnt) * getPower(pb, cnt) * getPower(pbMinus1, 18-cnt);
    }
    
    cout.precision(10);
    cout << (ld)1 - (antiSetA * antiSetB) <<endl;
    
    return 0;
}
