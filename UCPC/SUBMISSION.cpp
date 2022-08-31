#include <iostream>
#include <cstdio>
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

int N;
ll arr[500005], sorted_arr[500005];
vector<int> need_to_sort;

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        scanf("%lld", &arr[i]);
    }
    

    // 제곱수들을 다 나눠줌 (thin down)
    for(int i=0; i<N; ++i) {
        for(int j=0; j<primes.size(); ++j) {
            ll tmp = primes[j]*primes[j];
            if(arr[i]<tmp) break;
            while(arr[i] / tmp == 0) arr[i] /= tmp;
        }
    }
    
    // 정렬
    sort(&sorted_arr[0], &sorted_arr[N]);
    
    // 정렬과 비교
    for(int i=0; i<N; ++i){
        if(arr[i] != sorted_arr[i]){
            need_to_sort.push_back(i);
        }
    }
    
    // 제곱수 만들수 있는지 찾음
    
    
    
    // 모두 소각되면 YES , 아니면 NO
    
    
    
    return 0;
}
