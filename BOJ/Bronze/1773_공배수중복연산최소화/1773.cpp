// 5_1

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
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

int N, C, cnt;
bool End[2000002];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> C;
    
    // 어떤 수들의 배수들에 대한 확인에서 중복을 어떻게 제거? (예를 들어, 6, 8, 24, 15, 30 에 대한 배수 체크 연산)
    // "시작이 이미 true라면, 연산할 필요가 없다"로 중복 최소화 가능
    for(int i=0; i<N; ++i){
        int cycle; cin >> cycle;
        if(End[cycle]) continue;
        else{
            for(int j = cycle; j<= C; j += cycle){
                if(!End[j]){
                    End[j] = true;
                    ++cnt;
                }
            }
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}
