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
char number[14];

int main(void){
    
    scanf("%d", &N);
    
    for(int i=0; i<N; ++i){
        scanf("%s", number);
        int even_loc = -1, len = strlen(number);
        if(number[len-1] % 2 == 0){
            printf("0\n"); continue;
        }
        if(number[0] % 2 == 0){
            printf("1\n"); continue;
        }
        for(int j=0; j<len; ++j){
            if(number[j] % 2 == 0){
                even_loc = j;
                break;
            }
        }
        
        if(even_loc == -1) printf("-1\n");
        else printf("2\n");
    }
    
    return 0;
}
