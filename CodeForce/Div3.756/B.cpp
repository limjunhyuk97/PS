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

int N;

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        int a, b; scanf("%d %d", &a, &b);
        int team_cnt = (a + b) / 4;
        if(team_cnt > min(a,b)) printf("%d\n", min(a,b));
        else printf("%d\n", team_cnt);
    }
    
    return 0;
}
