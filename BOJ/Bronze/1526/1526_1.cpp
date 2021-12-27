// 5
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define INT_INF 2*1e9
#define LL_INF 9*1e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

string GMS;
string N;

bool makeNumber(int n){
    
    if(n == 0){
        if(stoi(GMS) <= stoi(N)){
            for(int i=0; i<GMS.size(); ++i)
                cout << GMS[i];
            return true;
        }
        else
            return false;
    }
    
    GMS.append("7");
    if(makeNumber(n-1))
        return true;
    GMS.pop_back();
    
    GMS.append("4");
    if(makeNumber(n-1))
        return true;
    GMS.pop_back();
    
    return false;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;

    if(!makeNumber((int)N.size())){
        for(int i=0; i<N.size()-1; ++i)
            cout << 7;
    }
    cout << "\n";

    return 0;
}
