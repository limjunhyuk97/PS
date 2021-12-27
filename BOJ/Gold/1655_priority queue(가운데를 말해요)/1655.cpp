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

int N;

priority_queue<int, vector<int>, less<>> maxheap;
priority_queue<int, vector<int>, greater<>> minheap;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    int tmp; cin >> tmp;
    minheap.push(tmp);
    cout << minheap.top() << '\n';
    
    for(int i=0; i<N-1; ++i){
        cin >> tmp;
        if(minheap.top() > tmp){
            if(minheap.size() >= maxheap.size()) maxheap.push(tmp);
            else{
                if(tmp > maxheap.top()) minheap.push(tmp);
                else{
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(tmp);
                }
            }
        }
        else{
            if(minheap.size() < maxheap.size()) minheap.push(tmp);
            else{
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(tmp);
            }
        }
        
        cout << maxheap.top() << '\n';
    }
    
    return 0;
}
