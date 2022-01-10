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

int T, N;
int parent[200005];
int ordinal[200005];
int pc_dist[200005];

int main(void){
    
    scanf("%d", &T);
    for(int i=0; i<T; ++i){
        scanf("%d", &N);
        for(int j=1;j<=N;++j) {
            scanf("%d", parent + j);
        }
        for(int j=0;j<N;++j) {
            scanf("%d", ordinal + j);
        }
        
        int root = ordinal[0], max_dist = 1; bool flag = true;
        fill(pc_dist, pc_dist + N, 0);
        
        if(parent[ordinal[0]] != ordinal[0]){
            printf("-1\n"); continue;
        }
        
        for(int j=1; j<N; ++j){
            int p = parent[ordinal[j]], c = ordinal[j];
            if(p != root && pc_dist[p] == 0){
                printf("-1\n"); flag = false;
                break;
            }
            max_dist += 1;
            pc_dist[c] = max_dist;
        }
        
        if(flag){
            for(int j=1; j<=N; ++j) printf("%d ", pc_dist[j] - pc_dist[parent[j]]);
            printf("\n");
        }
    }
    
    return 0;
}
