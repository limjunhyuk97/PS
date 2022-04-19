// 3개의 구슬이 서로 다른 색깔이어야 하므로, 연속된 3개를 따져야 하기에
// 이전 - 2개전 에서의 구슬의 상태만이 중요하다.
// DP[1전 구슬 종류][2전 구슬 종류][구슬1 남은갯수][구슬2 남은갯수][구슬3 남은갯수][구슬4 남은갯수][구슬5 남은갯수]

// Recurrence Relation을 어떻게 잡을 것인가?
// DP 배열 n번째 공간이 무엇을 의미할 것인가? - DP 배열 속의 값이 무엇을 나타낼 것인가?
// Top-Down으로 갈 것인가 - Bottom-Up으로 갈 것인가

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

int N;
int marbles[5];

// Fill Template
template<typename A, size_t N, typename T>
void Fill(A (&array) [N], const T &val) {
    std::fill((T*)array, (T*)(array+N), val);
}

// 0 1 2 3 4 : 최대 구슬 종류의 수
ll DP[7][7][11][11][11][11][11], cnt;

ll Top_Down(int prev, int pprev, int m1, int m2, int m3, int m4, int m5) {
    ll ret = 0;
    if(m1 == 0 && m2 == 0 && m3 == 0 && m4 ==0 && m5 == 0) return 1;
    if(DP[prev][pprev][m1][m2][m3][m4][m5] != -1) return DP[prev][pprev][m1][m2][m3][m4][m5];
    if(prev != 4 && pprev != 4 && m5 > 0) ret += Top_Down(4, prev, m1, m2, m3, m4, m5-1);
    if(prev != 3 && pprev != 3 && m4 > 0) ret += Top_Down(3, prev, m1, m2, m3, m4-1, m5);
    if(prev != 2 && pprev != 2 && m3 > 0) ret += Top_Down(2, prev, m1, m2, m3-1, m4, m5);
    if(prev != 1 && pprev != 1 && m2 > 0) ret += Top_Down(1, prev, m1, m2-1, m3, m4, m5);
    if(prev != 0 && pprev != 0 && m1 > 0) ret += Top_Down(0, prev, m1-1, m2, m3, m4, m5);
    DP[prev][pprev][m1][m2][m3][m4][m5] = ret;
    return ret;
}

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d", &marbles[i]);
    }
    
    Fill(DP, -1);
    
    // 6, 5부터 내려오면서 커버 가능
    printf("%lld\n", Top_Down(6, 5, marbles[0], marbles[1], marbles[2], marbles[3], marbles[4]));
    
    return 0;
}

