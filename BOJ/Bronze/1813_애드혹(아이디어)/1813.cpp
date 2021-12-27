// 6

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

int N;
int arr[100005];
priority_queue<int> ans;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; ++i){
        int index; cin >> index;
        arr[index]++;
    }
    
    for(int i=0; i<=100000; ++i){
        if(arr[i] == i)
            ans.push(i);
    }
    
    if(ans.empty()) cout << -1 << "\n";
    else cout << ans.top() << "\n";
    
    return 0;
}

