// algorithm -> sort 컴파일 에러..

#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <string>
using namespace std;

typedef long long int ll;
typedef pair<int ,ll> loc;

int N, location_zero = -1;
loc alphabet[15];
set<int> first_alphabets;
ll ans;

bool compare(const loc &l1, const loc &l2){
    return l1.second > l2.second;
}

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        string tmp; cin >> tmp;
        first_alphabets.insert(tmp[0]-'A');
        int tmp_len = (int)tmp.size();
        ll ordinal = 1;
        for(int j=tmp_len-1; j>=0; --j){
            alphabet[tmp[j]-'A'].second += ordinal;
            ordinal *= 10;
        }
    }
    for(int i=0; i<15; ++i) alphabet[i].first = i;
    sort(&alphabet[0], &alphabet[13], compare);
    
    if(alphabet[9].second != 0){
        for(int i=9; i>=0; --i){
            if(first_alphabets.find(alphabet[i].first) == first_alphabets.end()){
                location_zero = i;
                break;
            }
        }
    }
    
    ll ordinal = 9;
    for(int i=0; i<15; ++i){
        if(i != location_zero) {
            ans += alphabet[i].second * ordinal;
            ordinal -= 1;
        }
        else continue;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
