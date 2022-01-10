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

int t, a, b, c;

int main(void){
    
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d %d", &a, &b, &c);
        // already AP
        if(2*b == a + c) {
            printf("YES\n");
            continue;
        }
        // middle multiply
        if(2*b < a + c){
            if((a+c)%2 == 0){
                if(((a+c)/2)%b == 0){
                    printf("YES\n");
                    continue;
                }
                else{
                    printf("NO\n");
                    continue;
                }
            }
            else{
                printf("NO\n");
                continue;
            }
        }
        else{
            if(2*b - c > 0){
                if((2*b-c)%a == 0){
                    printf("YES\n");
                    continue;
                }
            }
            if(2*b - a > 0){
                if((2*b-a)%c == 0){
                    printf("YES\n");
                    continue;
                }
                else{
                    printf("NO\n");
                    continue;
                }
            }
        }
    }
    
    return 0;
}
