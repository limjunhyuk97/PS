// 2^50의 모든 경우를 고려하는 것이 아니라
// 가능한 수의 경우로 경우를 강제하는 방법

#include <iostream>
#include <set>
using namespace std;

int N, S, M, max_vol = -1;
int volumes[55];
bool flag = false;
set<int> phases[55];

int main(void){
    
    scanf("%d %d %d", &N, &S, &M);
    N += 1;
    
    for(int i=1; i<N; ++i){
        scanf("%d", &volumes[i]);
    }
    
    phases[0].insert(S);
    for(int i=0; i<N; ++i) {
        if(phases[i].empty()) {
            flag = true;
            break;
        }
        for(auto iter=phases[i].begin(); iter != phases[i].end(); ++iter) {
            if(phases[i+1].find(*iter + volumes[i+1]) == phases[i+1].end() && *iter + volumes[i+1] <= M) phases[i+1].insert(*iter + volumes[i+1]);
            if(phases[i+1].find(*iter - volumes[i+1]) == phases[i+1].end() && *iter - volumes[i+1] >= 0) phases[i+1].insert(*iter - volumes[i+1]);
        }
    }
    
    if(flag){
        printf("%d\n", max_vol);
        return 0;
    }
    
    N -=1 ;
    for(auto iter = phases[N].begin(); iter != phases[N].end(); ++iter) {
        if (max_vol < *iter) max_vol = *iter;
    }
    
    printf("%d\n", max_vol);
    
    return 0;
}
