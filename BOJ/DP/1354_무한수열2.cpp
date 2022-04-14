#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long int ll;

ll N, P, Q, X, Y;
unordered_map<ll, ll> mp;

ll TD(ll num) {
    if(num <= 0) return 1;
    if(mp.find(num) == mp.end()) {
        mp[num] = TD(num/P-X) + TD(num/Q-Y);
        return mp[num];
    }
    return mp[num];
}

int main(void){
    
    scanf("%lld %lld %lld %lld %lld", &N, &P, &Q, &X, &Y);
    
    mp[0] = 1;
    if(N == 0) printf("1\n");
    else printf("%lld\n", TD(N/P-X) + TD(N/Q-Y));
    
    return 0;
}
