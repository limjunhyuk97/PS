#include <iostream>
#include <set>
using namespace std;

int N, S, M, max_vol = -1;
int volumes[55];
set<int> phases[55];

int main(void){
    
    scanf("%d %d %d", &N, &S, &M);
    N += 1;
    
    for(int i=1; i<N; ++i){
        scanf("%d", &volumes[i]);
    }
    
    phases[0].insert(S);
    for(int i=0; i<N; ++i) {
        for(auto iter=phases[i].begin(); iter != phases.end(); ++iter) {
            if(phases[i+1].find(*iter + volumes[i]) == phases[i+1].end() && *iter + volumes[i] < M) phases[i+1].insert(*iter + volumes[i]);
            if(phases[i+1].find(*iter - volumes[i]) == phases[i+1].end() && *iter - volumes[i] > 0) phases[i+1].insert(*iter - volumes[i]);
        }
    }
    
    N -=1 ;
    for(auto iter = phases[N].begin(); iter != phases[N].end(); ++iter) {
        if (max_vol < *iter) max_vol = *iter;
    }
    
    printf("%d\n", max_vol);
    
    return 0;
}
