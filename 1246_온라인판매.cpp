#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[1005], maxprofit = 0, maxprice = 0;

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; ++i) scanf("%d", &(arr[i]));
    
    sort(&arr[0], &arr[1005], greater<int>());
    
    for(int i=0; i<N; ++i){
        if(maxprofit < arr[i] * (i+1)){
            maxprofit = arr[i] * (i+1);
            maxprice = arr[i];
        }
    }
    
    printf("%d %d\n", maxprice, maxprofit);
    
    return 0;
}
