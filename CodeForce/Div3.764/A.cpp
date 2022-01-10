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

int t, n, M=-1,m=2000000000, cnt = 0;
int arr[53];

int main(void){
    
    scanf("%d", &t);
    while(t--){
        for(int i=0; i<53; ++i) arr[i] = 0;
        M=-1; m=2000000000;
        scanf("%d", &n);
        for(int i=0; i<n; ++i) {
            scanf("%d", &arr[i]);
            if(M < arr[i]) M = arr[i];
            if(m > arr[i]) m = arr[i];
        }
    
        printf("%d\n", M-m);
        
    }
    
    
    return 0;
}
