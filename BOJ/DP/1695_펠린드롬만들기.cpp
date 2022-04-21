// 펠린드롬과 DP
// DP[n][m]에서의 펠린드롬 여부 체크
// DP[n-1][m+1]에서의 펠린드롬 여부 체크로 그대로 가져간다.

#include <iostream>
#include <string>
using namespace std;

int N, pal[5005];
int cnt;

// DP Logic : s와 t를 추가로 고려해야 한다는 뜻
void checkPAL(int s, int t, bool odd) {

    
    
}

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%d", &pal[i]);
    
    if(N>2 && N%2 == 0) checkPAL(N/2-1, N/2, false);
    if(N>2 && N%2 == 1) checkPAL(N/2-1, N/2+1, true);
    if(N==2 && pal[0] != pal[1]) cnt = 1;
    
    printf("%d\n", cnt);
    
    return 0;
}
