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

string str;
int len, half_len;
set<char> diff_L, diff_R;

// bound : 불일치의 최소값
int bound(const string &s, int len){
    int diff = 0;
    if(len % 2 == 0){
        for(int i=0; i<len/2; ++i){
            if(s[i] != s[len - 1 - i])
                diff += 1;
        }
    }
    else{
        int ldiff = 0, rdiff = 0, half_len = (int)(len/2);
        for(int i=0; i<half_len; ++i){
            if(s[i] != s[len - 2 - i]) ldiff += 1;
            if(s[len - 1 - i] != s[i + 1]) rdiff += 1;
        }
        diff = min(ldiff, rdiff);
    }
    return diff;
}

// branch and bound 사용
int main(void){
    
    cin >> str;
    
    
    
    return 0;
}
