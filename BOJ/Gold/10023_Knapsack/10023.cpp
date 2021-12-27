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

int N, B, breed[24], field[105],  cow_number, knapsack[100005];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> B;
    for(int i=0; i<B; ++i){
        cin >> breed[i];
    }
    for(int i=0; i<N; ++i){
        cin >> field[i];
    }
    
    // 깎아내는 연산 수행
    int exist = 0;
    for(int i=0; i<N; ++i){
        if(exist > 0) --exist;
        if(field[i] > exist){
            int tmp = exist;
            exist = field[i];
            field[i] -= tmp;
        }
        else{
            field[i] -= exist;
            if(field[i] < 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    // 구해야하는 소 울음 소리 조합만 끄집어 낸다. (moo_sum)
    vector<int> moo_sum;
    for(int i=0; i<N; ++i){
        if(field[i]) moo_sum.push_back(field[i]);
    }
    sort(&breed[0], &breed[B], less<>());
    
    // 각 소 울음소리 조합에 대해서 knapsack 진행
    for(int i=0; i<moo_sum.size(); ++i){
        for(int j=1; j<100005; ++j) knapsack[j] = INT_INF;
        for(int j=0; j< B; ++j){
            for(int k=breed[j]; k<=moo_sum[i]; ++k){
                knapsack[k] = min(knapsack[k - breed[j]] + 1, knapsack[k]);
            }
        }
        if(knapsack[moo_sum[i]] < INT_INF) cow_number += knapsack[moo_sum[i]];
        else{
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << cow_number << '\n';
    
    return 0;
}
