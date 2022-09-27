#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

///
vector<string> v;
string input;
///

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ///
    getline(cin, input);
    istringstream ss(input);
    
    string tmp;
    while(getline(ss, tmp , ' ')){
        v.push_back(tmp);    }
    ///
    
    
    return 0;
}
