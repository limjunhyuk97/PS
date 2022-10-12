#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

typedef long long int ll;

ll N, K, M;

// 진법 변환
void conversion(deque<int> & dq, ll num, ll dest) {
    while(num) {
        dq.push_front((int)(num % dest));
        num /= dest;
    }
}

// 이항계수
int DP[2005][2005];
int solve(int N, int K, int M) {
    int *ret = &DP[N][K];
    if(*ret) return *ret;
    if(N==K || K==0) return 1;
    if(N==0) return 0;
    *ret = (solve(N-1, K-1, M) +solve(N-1, K, M)) % M;
    return *ret;
}

int main(void) {
    
    scanf("%lld %lld %lld", &N, &K, &M);
    
    deque<int> NtoM, KtoM;
    conversion(NtoM, N, M);
    conversion(KtoM, K, M);
    
    // 앞자리 0 맞추기
    int gap = (int)(NtoM.size()-KtoM.size());
    for(int i=0; i<gap; ++i) KtoM.push_front(0);
    
    // 뤼카 정리 사용한 계산
    int res = 1;
    for(int i=0; i<NtoM.size(); ++i) {
        res *= solve(NtoM[i], KtoM[i], (int)M);
        res %= M;
    }
    
    printf("%d\n", res);
    
    return 0;
}
