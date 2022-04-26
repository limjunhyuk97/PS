// 투 포인터
// - 구간에 대해서 살펴볼 때, 선형 시간복잡도로 연산할 수 있음
// - 로직
//   - p0에서 p1을 늘려가면서 거리가 최대가 되는 구간에서 p1을 멈춘다.
//   - p0를 하나 늘려서 그때 p1값에 대해서 또 찾는다.
//   - 위와 같은 행위를 p1을 더이상 움직일 수 없을때까지 진행한다.

#include <iostream>
#include <algorithm>
using namespace std;

int N, dist[50005], total_dist, max_dist = -1;
int p0=0, p1=1, c0, c1;

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d", &dist[i]);
        total_dist += dist[i];
    }
    
    c0 = dist[0]; c1 = total_dist - c0; max_dist = min(c0, c1);
    while(p1<N) {
        
    }
    
    return 0;
}

// 누적합 + 이분탐색
