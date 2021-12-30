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
int DP[1005];

int main(void){
    
    scanf("%d %d", &C, &N);
    for(int i=0; i<N; ++i){
        int c, p; scanf("%d %d", &c, &p);
        cost.push_back({c, p});
    }
    
    for(int i=0; i<cost.size(); ++i){
        for(int j=cost[i].second; j<=C; j++){
            if(DP[j] == 0){
                if(j-cost[i].second != 0 && DP[j-cost[i].second] == 0) continue;
                else DP[j] = DP[j-cost[i].second] + cost[i].first;
            }
            else{
                DP[j] = min(DP[j], DP[j-cost[i].second] + cost[i].first);
            }
        }
    }
    
    printf("%d\n", DP[C]);
    
    return 0;
}
