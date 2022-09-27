#include <iostream>
#include <algorithm>
#define INF 2000000000
using namespace std;

int N, DP[1000005];

int main(void){
    
    scanf("%d", &N);
    
    N += 1;
    for(int i=2; i<N; ++i){
        int n1=INF, n2=INF, n3=INF;
        if(i % 2 == 0) n1 = DP[i/2] + 1;
        if(i % 3 == 0) n2 = DP[i/3] + 1;
        n3 = DP[i-1] + 1;
        DP[i] = min(min(n1, n2), n3);
    }
    
    printf("%d\n", DP[N-1]);
    
    return 0;
}
