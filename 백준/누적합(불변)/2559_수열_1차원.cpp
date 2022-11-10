// 미리 누적합 DP
#include <iostream>
#define MAXLEN 100005
#define INF 2000000000
using namespace std;

int N, K;
int arr[MAXLEN];
int maxT = -INF;

int main(void) {
    
    scanf("%d %d", &N, &K);
    
    // 배열 받기 + 누적합 구하기
    for(int i=1; i<=N; ++i) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i-1];
    }
    
    // K 연속에 대해서 구하기
    K -= 1;
    for(int i=1; i+K<=N; ++i) {
        maxT = maxT < arr[i+K]-arr[i-1] ? arr[i+K]-arr[i-1] : maxT;
    }
    
    printf("%d\n", maxT);
    
    return 0;
}
