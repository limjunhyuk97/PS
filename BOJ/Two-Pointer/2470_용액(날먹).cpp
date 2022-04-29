// 투 포인터로 해결
//  - p0, p1의 움직임에 따라서 현재 cur_sum과 next_sum을 비교한다.
//      - 개선(합을 0에 가까이) 계속 가능하면 p1을 왼쪽으로 땡긴다
//      - 개선(합을 0에 가까이) 더이상 불가능하면 p0을 오른쪽을 땡긴다
//      - 개선 여부에 관계없이 cur_sum은 계속 갱신한다.
//  - 답을 결정짓는 fin_sum은 next_sum보다 나아졌는가를 바탕으로 갱신한다.

#include <iostream>
#include <cstdlib>
#include <algorithm>
#define INF 2000000007
#define BUFLEN 100005
using namespace std;

int N, arr[BUFLEN];
int p0, p1, sol0, sol1, fin_sum = INF, cur_sum = INF;

int main(void) {
    
    // initialize
    for(int i=0; i<BUFLEN; ++i) arr[i] = INF;
    
    // input
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d", &arr[i]);
    }
    
    // sort
    sort(&arr[0], &arr[N]);
    
    p0 = 0; p1 = N-1; sol0 = arr[p0]; sol1 = arr[p1];
    fin_sum = abs(arr[p0] + arr[p1]);
    cur_sum = abs(arr[p0] + arr[p1]);

    // p0, p1
    while(p0 < p1-1) {
        int next_sum = abs(arr[p0] + arr[p1-1]);
        if(cur_sum >= next_sum) {
            p1 -= 1;
            if(fin_sum > next_sum) {
                sol0 = arr[p0];
                sol1 = arr[p1];
                fin_sum = next_sum;
            }
        }
        else {
            next_sum = abs(arr[p0+1] + arr[p1]);
            p0 += 1;
            if(fin_sum > next_sum) {
                sol0 = arr[p0];
                sol1 = arr[p1];
                fin_sum = next_sum;
            }
        }
        cur_sum = next_sum;
    }
    
    printf("%d %d\n", sol0, sol1);
    
    return 0;
}
