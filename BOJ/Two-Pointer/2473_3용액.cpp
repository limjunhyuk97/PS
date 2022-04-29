// 3개의 합이 !에 가까워지게 하는 알고리즘 구하기
//  - 이분탐색(n분탐색)
//  - 투포인터(n포인터)

// 투 포인터(3 포인터)로 해결
//  - p0, p1, p2 포인터를 움직여가며 구한다.

// 조심해야할 부분
//  - 정수형 데이터의 범위에 유의한다..!

#include <iostream>
#include <cstdlib>
#include <algorithm>
#define INF 2000000007
#define BUFLEN 5005
using namespace std;

typedef long long int ll;

ll N, arr[BUFLEN];
ll p0, p1, p2, sol0, sol1, sol2, fin_sum = INF, cur_sum = INF;

int main(void) {
    
    // initialize
    for(int i=0; i<BUFLEN; ++i)
        arr[i] = INF;
    
    // input
    scanf("%lld", &N);
    for(int i=0; i<N; ++i) {
        scanf("%lld", &arr[i]);
    }
    
    // sort
    sort(&arr[0], &arr[N]);
    
    p0 = 0; p1 = 1; p2 = N-1;
    sol0 = arr[p0]; sol1 = arr[p1]; sol2 = arr[p2];
    fin_sum = abs(arr[p0] + arr[p1] + arr[p2]);
    cur_sum = abs(arr[p0] + arr[p1] + arr[p2]);

    // p0, p1
    for(p0=0; p0<N-2; ++p0) {
        p1 = p0 + 1; p2 = N-1;
        cur_sum = abs(arr[p0] + arr[p1] + arr[p2]);
        if(fin_sum > cur_sum) {
            sol0 = arr[p0];
            sol1 = arr[p1];
            sol2 = arr[p2];
            fin_sum = cur_sum;
        }
        while(p1 < p2-1) {
            ll next_sum = abs(arr[p0] + arr[p1] + arr[p2-1]);
            if(cur_sum >= next_sum) {
                p2 -= 1;
                if(fin_sum > next_sum) {
                    sol0 = arr[p0];
                    sol1 = arr[p1];
                    sol2 = arr[p2];
                    fin_sum = next_sum;
                }
            }
            else {
                next_sum = abs(arr[p0] + arr[p1+1] + arr[p2]);
                p1 += 1;
                if(fin_sum > next_sum) {
                    sol0 = arr[p0];
                    sol1 = arr[p1];
                    sol2 = arr[p2];
                    fin_sum = next_sum;
                }
            }
            cur_sum = next_sum;
        }
    }
    
    printf("%lld %lld %lld\n", sol0, sol1, sol2);
    
    return 0;
}

