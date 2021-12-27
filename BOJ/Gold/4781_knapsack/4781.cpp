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

int n, imoney;
int knapsack[10005];
double money;

typedef pair<int, int> treat;

bool compare(const treat& t1, const treat &t2){
    return t1.second < t2.second;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        
        cin >> n >> money;
        if(n == 0 && money == 0) break;
        
        imoney = money * 100 + 0.5;
        
        vector<treat> candy;
        int c; double p;
        for(int i=0; i<n; ++i){
            cin >> c >> p;
            candy.push_back({c, p*100 + 0.5});
        }
        sort(candy.begin(), candy.end(), compare);
        
        for(int i=0; i<10005; ++i){
            knapsack[i] = 0;
        }
        
        for(int i=0; i<candy.size(); ++i){
            for(int j=candy[i].second; j<=imoney; j++){
                knapsack[j] = max(knapsack[j - candy[i].second] + candy[i].first, knapsack[j]);
            }
        }
        
        cout << knapsack[imoney] << '\n';
        
    }
    
    return 0;
}
