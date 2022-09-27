// 이것도 마찬가지로 굉장히 티피컬한 투 포인터 문제
// 가능할때 까지 p1 늘려가면서 더하고
// 불가능하면 p0 앞으로 땡기고
// S 이상이라는 부분에서 실수함..

#include <iostream>
#include <algorithm>
#define INF 1000000
using namespace std;

int N, S;
int arr[100005];
int p0, p1, C, dist = INF;

int main(void) {
    
    scanf("%d %d", &N, &S);
    for(int i=0; i<N; ++i){
        scanf("%d", &arr[i]);
    }
    
    C = arr[p0];
    while(p0<=p1 && p1<N) {
        if(C < S) {
            p1 += 1;
            C += arr[p1];
        }
        else {
            dist = min(dist, p1 - p0 + 1);
            if(p0 == p1) {
                C -= arr[p0];
                p0 += 1;
                p1 += 1;
                C += arr[p1];
            }
            else {
                C -= arr[p0];
                p0 += 1;
            }
        }
    }
    
    if(dist == INF) printf("0\n");
    else printf("%d\n", dist);
    
    return 0;
}
