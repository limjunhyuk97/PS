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
string input;
vector<string> v;
///

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ///
    getline(cin, input);
    unsigned long int start = 0, end = input.find("  ", start);
    while(end != string::npos){
        v.push_back(input.substr(start, end-start));
        start = end + 1;
        end = input.find("  ", start);
    }
    v.push_back(input.substr(start));
    ///
    
    for(int i = 0; i<v.size(); ++i)
        cout << v[i] << endl;
    
    return 0;
}
