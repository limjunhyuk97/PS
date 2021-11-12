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

// edges : edge들 저장. F :
int weight[10][10];
vector< pair<int, int> > F;

void Prim(int n){
    
    // initialization
    int dist[10];
    int nearest[10];
    int minval = 0, vnear = 0, cnt = n - 1;
    
    
    for(int i=2; i<=n; ++i) {
        nearest[i] = 1;
        dist[i] = weight[1][i];
    }
    
    while(cnt--){
        minval = INT_INF;
        for(int i=2; i<=n; ++i){
            if(dist[i] > 0 && dist[i] < minval){
                minval = dist[i];
                vnear = i;
            }
        }
        F.push_back({nearest[vnear], vnear});
        for(int i=2; i<=n; ++i){
            if(weight[vnear][i] < dist[i]){
                dist[i] = weight[vnear][i];
                nearest[i] = vnear;
            }
        }
        dist[vnear] = -1;
    }
    
}

int E, V;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j)
            weight[i][j] = INT_INF;
    }
    
    cin >> E >> V;
    for(int i=0;i <E; ++i){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        weight[v1][v2] = w; weight[v2][v1] = w;
    }
    
    Prim(V);
            
    for(int i=0; i<F.size(); ++i){
        cout << F[i].first << " " << F[i].second << endl;
    }
    
    return 0;
}
