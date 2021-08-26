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
typedef pair<set<int>, int> bundle;

string str;
vector<bundle> z_count[52];
int filtered_z_count[52];
int N, M, K, max1 = -1;

// max_element를 위한 정렬에서는 < 의 결과를 return 해주어야 한다.
bool compare(const bundle & b1, const bundle & b2){
    return b1.second < b2.second;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> str;
        set<int> idx;
        for(int j=0; j<M; ++j)
            if(str[j] == '0')
                idx.insert(j);
        bool flag = false;
        for(int i=0; i< z_count[idx.size()].size(); ++i)
            if(z_count[idx.size()][i].first == idx){
                z_count[idx.size()][i].second++;
                flag = true; break;
            }
        if(!flag) z_count[idx.size()].push_back({idx, 1});
    }
    cin >> K;
    
    for(int i=0; i<52; ++i){
        for(int j=0; j<z_count[i].size(); ++j){
            filtered_z_count[i] = (*max_element(z_count[i].begin(), z_count[i].end(), compare)).second;
        }
    }
    
    for(int i=K; i>=0; i-=2){
        if(i>50) continue;
        max1 = max(max1, filtered_z_count[i]);
    }
    
    cout << max1 << endl;
    
    return 0;
}
