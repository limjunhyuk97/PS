#include <iostream>
#include <algorithm>
using namespace std;

int N;
int DP[1005];
int arr[1005];

int main(void) {
    
    scanf("%d", &N);
    
    int MAXDP = 1;
    for(int i=0; i<N; ++i) {
        int tmp; scanf("%d", &tmp);
        
        DP[tmp] = 1;
        arr[i] = tmp;
        
        for(int j=0; j<i; ++j) {
            if(tmp > arr[j]) DP[tmp] = max(DP[tmp], DP[arr[j]] + 1 );
        }
        
        MAXDP = max(MAXDP, DP[tmp]);
    }
    
    printf("%d\n", MAXDP);
    
    return 0;
}
