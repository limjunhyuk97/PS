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

int N, M;
deque<int> input, output;

bool out2in(int n){
    
    if(n == M) return true;
    if(n == 0){
        input.push_back(output.back());
        output.pop_back();
        if(out2in(n+1)) return true;
        output.push_back(input.back());
        input.pop_back();
        
        input.push_front(output.front());
        output.pop_front();
        if(out2in(n+1)) return true;
    }
    else{
        if(input.back() > output.front()){
            input.push_front(output.front());
            output.pop_front();
            if(out2in(n+1)) return true;
            output.push_front(input.front());
            input.pop_front();
        }
        if(input.front() > output.back()){
            input.push_back(output.back());
            output.pop_back();
            if(out2in(n+1)) return true;
            output.push_back(input.back());
            input.pop_back();
        }
    }
    
    return false;
    
}

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        scanf("%d", &M);
        input.clear(); output.clear();
        
        // output을 들여온다.
        for(int j=0; j<M; ++j){
            int tmp; scanf("%d", &tmp);
            output.push_back(tmp);
        }
        
        if(out2in(0)){
            for(int j=0; j<input.size(); ++j){
                printf("%d ", input[j]);
            }
            printf("\n");
        }
        else printf("-1\n");
    }
    
    return 0;
}
