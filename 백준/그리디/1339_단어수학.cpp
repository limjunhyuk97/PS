#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

int N, alphabets[30];
ll sum;

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        string str; cin >> str;
        int carry = 1;
        for(int j=(int)str.size()-1; j>=0; --j){
            alphabets[str[j]-'A'] += carry;
            carry *= 10;
        }
    }
    
    sort(&alphabets[0], &alphabets[30], greater<int>());
    
    ll num = 9;
    for(int i=0; i<30; ++i) sum += (ll)alphabets[i] * (num--);
    
    printf("%lld\n", sum);
    
    return 0;
}
