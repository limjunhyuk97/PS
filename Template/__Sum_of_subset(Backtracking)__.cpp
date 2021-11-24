// Backtracking을 이용해서 구현한 sum of subset algorithm(부분집합의 원소 총합이 특정 값이 되도록 하는 알고리즘)
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <array>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

// N : 전체 element 수, total_sum : 전체 합, W : 목표 weight 총합
// include : subset에 포함되었는지 안되었는지, numbers 숫자들 받기(1번째 index부터 받게할거임)
int N, total_sum, W;
bool include[1000];
int numbers[1000];

// promising constraint
// 1. idx까지 가능한 sum 고려한 U + remaining T >= 목표치 W 이면 OK
// 2. idx까지 가능한 sum 고려한 U == 목표치 W 이면 OK
// 3. idx까지 가능한 sum 고려한 U + 다음거 더했을때 numbers[idx+1] >= 목표치 W 이어야 OK
bool promising(int idx, int U, int T){
    return (numbers[idx] + T >= W) && ( (U == W) || (idx == N ? false : (U + numbers[idx+1] <= W)) );
}

void sum_of_subset(int idx, int U, int T){
    // promising check 하고
    if(promising(idx, U, T)){
        // 가능하면 출력
        if(U == W){
            for(int i=1; i<=idx; ++i)
                if(include[i])
                    printf("%d(idx:%d) ", numbers[i], i);
            printf("= sum %d\n", W);
            return;
        }
        // 끝까지 갔으면 종료
        if(idx == N)
            return;
        // 끝까지 가지 않았다면 이진트리 형식의 state space tree를 순회한다.
        else{
            include[idx+1] = true;
            sum_of_subset(idx+1, U + numbers[idx+1], T-numbers[idx+1]);
            include[idx+1] = false;
            sum_of_subset(idx+1, U, T-numbers[idx+1]);
        }
    }
    
}

int main(void){
    
    printf("numbers : "); scanf("%d", &N);
    printf("target sum : "); scanf("%d", &W);
    
    for(int i=1; i<=N; ++i) {
        scanf("%d", numbers + i);
        total_sum += *(numbers + i);
    }
    
    
    // 정렬이 되어있어야 함
    sort(numbers, numbers+N);
    
    // Backtracking 시작
    sum_of_subset(0, 0, total_sum);
    
    return 0;
}
