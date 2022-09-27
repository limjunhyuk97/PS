// Recurence relation을 작성
// Look-up table을 만든다
// Solve - store - extract

#include <iostream>
#define DIVIDER 9901
using namespace std;

int N;
int DP[100005][3];

int main(void){
    
    scanf("%d", &N);
    
    DP[1][0] = 1; DP[1][1] = 1; DP[1][2] = 1;
    
    // recurrence relaton
    for(int i=2; i<N+1; ++i){
        DP[i][0] = (DP[i-1][1] + DP[i-1][2])%DIVIDER;
        DP[i][1] = (DP[i-1][0] + DP[i-1][2])%DIVIDER;
        DP[i][2] = (DP[i-1][0] + DP[i-1][1] + DP[i-1][2])%DIVIDER;
    }
    
    printf("%d\n", (DP[N][0]+DP[N][1]+DP[N][2])%DIVIDER);

    return 0;
}
