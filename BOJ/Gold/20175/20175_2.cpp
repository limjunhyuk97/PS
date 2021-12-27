#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <limits>
using namespace std;
 
typedef long long int ll;
 
ll n, d, min1 = 9e18, min2 = 9e18, max1 = -9e18, max2 = -9e18;
ll arr[1000005];

int main(void) {
    
    scanf("%lld %lld", &n, &d);
    for (int i = 0; i < n; ++i) scanf("%lld", arr + i);
    
    for(int i=0; i<n; ++i){
        ll t1 = arr[i] - i * d, t2 = arr[i] + i * d;
        if(t1 < min1) min1 = t1;
        if(t2 < min2) min2 = t2;
        if(max1 < t1) max1 = t1;
        if(max2 < t2) max2 = t2;
    }
    
    n = min(max1 - min1, max2 - min2);
    
    if(n % 2 == 0) printf("%lld.0\n", n >> 1);
    else printf("%lld.5\n", n >> 1);
    
    return 0;
}


