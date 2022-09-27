// 투 포인터
// - 구간에 대해서 살펴볼 때, 선형 시간복잡도로 연산할 수 있음
// - 로직 : p0를 기준으로 잡고 p1을 움직여가면서 가능한 maximum-distance를 찾는다.
//   - p0에서 p1을 늘려가면서 거리가 최대가 되는 구간에서 p1을 멈춘다.
//   - p0를 하나 늘려서 그때 p1값에 대해서 또 찾는다.
//   - 위와 같은 행위를 p1을 더 이상 움직일 수 없을때까지 진행한다.
//   - 만약 절반 값이 나오면 바로 출력한다..!

#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[50005], max_dist=-1, tot_dist;
int p0, p1=1, c0, c1;

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d", &arr[i]);
        tot_dist += arr[i];
    }
    
    c0=arr[0]; c1=tot_dist-arr[0];
    
    while(p1<=N) {
        if(c0<c1) {
            max_dist = max(c0, max_dist);
            c0 += arr[p1];
            c1 -= arr[p1];
            p1 += 1;
        }
        else if(c0 == c1) {
            max_dist = c0;
            break;
        }
        else {
            c0 -= arr[p0];
            c1 += arr[p0];
            p0 += 1;
        }
    }
    
    printf("%d\n", max_dist);
    
    return 0;
}


// 누적합 + 이분탐색
