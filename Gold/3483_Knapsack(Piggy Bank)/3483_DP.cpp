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
#define AVAILABLE "The minimum amount of money in the piggy-bank is %d.\n"
#define NONAVAILABLE "This is impossible.\n"
using namespace std;

typedef long long int ll;

int T, E, F, W, N;
int minprofit = INT_INF;
int DP[10005];

bool compare(pair<int, int> &n1, pair<int, int> &n2){
    return (n1.first/n1.second) > (n2.first/n2.second);
}

int main(void){
    
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &E, &F);
        W = F - E;
        scanf("%d", &N);
        // value(first) : weight(second)
        vector< pair<int,int> > items;
        for(int i=0; i<N; ++i){
            int v, w; scanf("%d %d", &v, &w);
            items.push_back({v, w});
        }
        // sorting
        sort(items.begin(), items.end(), compare);
        // initialize
        fill(DP, DP+10005, 0);
        for(int i=0; i<items.size(); ++i) DP[items[i].second] = items[i].first;
        // DP
        for(int i=0; i<items.size(); ++i){
            for(int j=items[i].second; j<=W; ++j){
                if (DP[j] == 0 && DP[j - items[i].second] != 0) DP[j] = DP[j-items[i].second] + items[i].first;
                else if(DP[j] != 0 && DP[j - items[i].second] != 0)  DP[j] = min(DP[j-items[i].second]+items[i].first, DP[j]);
            }
        }
        // result
        if(DP[W]) printf(AVAILABLE, DP[W]);
        else printf(NONAVAILABLE);
        
    }
    
    return 0;
}
