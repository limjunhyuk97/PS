#include <iostream>
#include <map>
using namespace std;

typedef long long int ll;

ll N, P, Q;
map<ll, ll> mp;

ll TD(ll num) {
    if(mp.find(num) == mp.end()) {
        mp[num] = TD(ll(num/P)) + TD(ll(num/Q));
        return mp[num];
    }
    return mp[num];
}

int main(void){
    
    scanf("%lld %lld %lld", &N, &P, &Q);
    
    mp[0] = 1;
    if(N == 0) printf("1\n");
    else printf("%lld\n", TD(ll(N/P)) + TD(ll(N/Q)));
    
    return 0;
}
