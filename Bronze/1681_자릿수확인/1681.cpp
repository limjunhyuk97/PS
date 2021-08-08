// 1


#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

int N, L;

bool CheckNumber(ll n){
    
    while(n){
        int tmp = n % 10;
        if(tmp == L) return false;
        n /= 10;
    }
    
    return true;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> L;
    
    ll num = 1;
    
    while(true){
        if(N == 0) break;
        
        if(!CheckNumber(num)){
            ++num;
            continue;
        }
        else{
            N--;
            if(N == 0) break;
            ++num;
        }
    }
    
    cout << num << "\n";
    
    return 0;
}
