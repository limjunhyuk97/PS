#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> SD;

int N, D, DP[10005];
vector<SD> ST[10005];

int main(void){
    
    scanf("%d %d", &N, &D);
    for(int i=0; i<N; ++i){
        int s, t, dist; scanf("%d %d %d", &s, &t, &dist);
        ST[t].push_back(make_pair(s, dist));
    }
    
    D += 1;
    for(int i=1; i<D; ++i){
        DP[i] = DP[i-1] + 1;
        if(ST[i].size() != 0) {
            int shortcuts = (int)ST[i].size();
            for(int j=0; j<shortcuts; ++j) {
                DP[i] = min(DP[i], ST[i][j].second + DP[ST[i][j].first]);
            }
        }
    }
    
    printf("%d\n", DP[D-1]);
    
    return 0;
}
