#include <iostream>
#include <cstdio>
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

int t, n, tmp;
int checked[59];

int main(void){
    
    scanf("%d", &t);
    while(t--){
        for(int i=0; i<59; ++i) {
            checked[i] = 0;
        }
        scanf("%d", &n);
        for(int i=0; i<n; ++i){
            scanf("%d", &tmp);
            for(; tmp >0; tmp=tmp/2){
                if(tmp <= n)
                    checked[tmp] += 1;
            }
        }
        
        bool flag = true;
        for(int i=n; i>=1; --i){
            bool one_cnt = false;
            if(checked[i] == 0){
                printf("NO\n");
                flag = false;
                break;
            }
            for(int j=i; j>=1; j=j/2){
                if(checked[j] == 1) {
                    if(!one_cnt) one_cnt = true;
                    else{
                        printf("NO\n");
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        
        if(flag) printf("YES\n");
    }
    
    
    return 0;
}
