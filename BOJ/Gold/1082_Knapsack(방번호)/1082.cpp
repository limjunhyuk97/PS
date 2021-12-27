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
#include <array>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;
typedef pair<int, int> num_price;

string Knapsack[52];
vector<num_price> P;
int N, M;

// s1은 배열 내 원래 수, s2는 배열에 새로 넣으려고 하는 수 : 새로 넣으려는게 더 크면 true
bool compare(const string &s1, const string &s2){
    
    if(s1 == "") return true;
    
    int s1_start = 0, s2_start = 0;
    for(int i=0; i<s1.size(); ++i){
        if(s1[i] != '0')
            break;
        s1_start++;
    }
    for(int i=0; i<s2.size(); ++i){
        if(s2[i] != '0')
            break;
        s2_start++;
    }
    
    if(s1.size() - s1_start > s2.size() - s2_start) return false;
    else if(s1.size() - s1_start < s2.size() - s2_start) return true;
    else{
        int i = s1_start, j = s2_start;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] < s2[j]) return true;
            else if(s1[i] > s2[j]) return false;
            else{
                ++i; ++j;
            }
        }
        return false;
    }
}

bool ascending_price_order(const num_price &n1, const num_price & n2){
    return n1.second < n2.second;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; ++i){
        int price; cin >> price;
        P.push_back({i, price});
    }
    cin >> M;
    
    sort(P.begin(), P.end(), ascending_price_order);
    
    for(int i=0; i<=M; ++i){
        for(int j=0; j<P.size(); ++j){
            if(i - P[j].second < 0) break;
            else{
                if(Knapsack[i] == ""){
                    if(compare(Knapsack[i-1], Knapsack[i - P[j].second] + to_string(P[j].first)))
                        Knapsack[i] = Knapsack[i - P[j].second] + to_string(P[j].first);
                    else
                        Knapsack[i] = Knapsack[i-1];
                }
                else{
                    if(compare(Knapsack[i], Knapsack[i - P[j].second] + to_string(P[j].first)))
                        Knapsack[i] = Knapsack[i - P[j].second] + to_string(P[j].first);
                }
            }
        }
    }
    
    cout << Knapsack[M] << endl;
    
    return 0;
}
