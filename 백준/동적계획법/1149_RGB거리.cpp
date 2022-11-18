#include <iostream>
#include <algorithm>
using namespace std;

int N;
int RGB[1005][3];
int DP[1005][3];

int main(void) {
    
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) {
        scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
    }
    
    // DP연산
    for(int i=1; i<=N; ++i) {
        DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + RGB[i][0];
        DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + RGB[i][1];
        DP[i][2] = min(DP[i-1][1], DP[i-1][0]) + RGB[i][2];
    }
    
    cout << min(min(DP[N][0], DP[N][1]), DP[N][2]) << endl;
    
    return 0;
}
