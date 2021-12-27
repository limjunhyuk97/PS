// 이분 매칭을 이용한 두개씩 짝짓기
// 그래프화 시켜서, 연결된 상태를 일단 전부 구현하고, 이분매칭 알고리즘을 돌린다.

#include <iostream>
#include <sstream>
#include <string>
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

int N, arr[55], A[55], B[55];
bool primes[2020];
bool checked[55];
vector<int> edges[55], res;

void find_prime(){
    for(int i=0; i<2020; ++i) primes[i] = true;
    primes[2] = true; primes[3] = true;
    int cnt = 2;
    for(int i=2; i<=2010; ++i){
        if(primes[i]){
            cnt = 2;
            while(cnt * i <= 2020) {
                primes[cnt * i] = false;
                cnt += 1;
            }
        }
    }
}

bool dfs(int n){
    checked[n] = true;
    for(int m : edges[n]){
        if(B[m] == 0) continue;
        if(B[m] == -1 || (!checked[B[m]] && dfs(B[m]))){
            A[n] = m;
            B[m] = n;
            return true;
        }
    }
    return false;
}

bool compare(int n, int m){
    return arr[n] < arr[m];
}

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d", arr + i);
    
    find_prime();
    
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            if(primes[arr[i]+arr[j]]){
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    
    bool flag = false;
    for(int i=1; i<N; ++i){
        flag = false;
        if(primes[arr[0] + arr[i]]){
            fill(A, A+N, -1);
            fill(B, B+N, -1);
            A[0] = i; B[i] = 0;
            for(int j=1; j<N; ++j){
                if(i == j) continue;
                fill(checked, checked+ N, false);
                if(!dfs(j)) {
                    flag = true;
                    break;
                }
            }
            if(!flag) res.push_back(i);
        }
    }
    
    if(res.empty()) printf("-1\n");
    else{
        sort(res.begin(), res.end(), compare);
        for(int i : res) printf("%d ", arr[i]);
        printf("\n");
    }
    
    return 0;
}
