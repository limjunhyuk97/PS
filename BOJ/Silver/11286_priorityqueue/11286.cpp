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
#include <bitset>
#include <cmath>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;
struct comp{
    bool operator()(int n, int m){
        if(abs(n) != abs(m)) return abs(n) > abs(m);
        else return n > m;
    }
};

priority_queue<int, vector<int>, comp> que;
int N;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
        
    cin >> N;
    while(N--){
        int tmp; cin >> tmp;
        if(tmp){
            que.push(tmp);
        }
        else{
            if(que.empty()) cout << 0 << '\n';
            else{
                cout << que.top() << '\n';
                que.pop();
            }
        }
    }
    
    return 0;
}
