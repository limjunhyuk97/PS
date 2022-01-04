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

int C, N;
vector<pair<int, int> > cost;
int DP[1500], min_val= INT_INF;

// knapsack에 눌러담아주기 전에 무게가 무거운 순으로 정렬한다.
// 여기서 무게는 사람의 수이다. (구할 목표가 비용이므로!)
bool comp(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

int main(void){
    
    scanf("%d %d", &C, &N);
    for(int i=0; i<N; ++i){
        int c, p; scanf("%d %d", &c, &p);
        cost.push_back({c, p});
    }
    
    for(int i=1; i<1500; ++i) DP[i] = INT_INF;
    
    sort(cost.begin(), cost.end(), comp);
    
    for(int i=0; i<N; ++i){
        for(int j=cost[i].second; j-cost[i].second<= C; ++j){
            DP[j] = min(DP[j-cost[i].second] + cost[i].first, DP[j]);
        }
    }
    
    for(int i=C; i<1500; ++i)
        min_val = min(DP[i], min_val);
    
    printf("%d\n", min_val);
    
    return 0;
}
