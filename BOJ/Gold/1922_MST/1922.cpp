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

struct edge{
    int v1;
    int v2;
    int weight;
    
    bool operator<(const edge &other) const{
        return weight > other.weight;
    }
};

int parent[1010], V, E;
priority_queue<edge> edges;
vector<edge> MST;

int Find(int idx){
    if(parent[idx] < 0) return idx;
    
    int root = idx;
    for(; parent[root] >= 0; root=parent[root]);
    
    while(root != idx){
        int tmp = parent[idx];
        parent[idx] = root;
        idx = tmp;
    }
    
    return root;
}

bool Union(int i, int j){
    int iroot = Find(i);
    int jroot = Find(j);
    
    if(iroot == jroot) return false;
    else{
        int tmp = parent[iroot] + parent[jroot];
        if(parent[iroot] > parent[jroot]){
            parent[iroot] = jroot;
            parent[jroot] = tmp;
            return true;
        }
        else{
            parent[jroot] = iroot;
            parent[iroot] = tmp;
            return true;
        }
    }
}

int Kruskal(int n){
    
    int sum = 0;
    
    while( (MST.size() < n-1) && !edges.empty()){
        edge cur = edges.top();
        edges.pop();
        
        if(Find(cur.v1) != Find(cur.v2)){
            MST.push_back(cur);
            Union(cur.v1, cur.v2);
            sum += cur.weight;
        }
        
    }
    
    if(MST.size() == n - 1) return sum;
    else return -1;
    
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<1010; ++i) parent[i] = -1;
    
    cin >> V >> E;
    for(int i=0; i<E; ++i){
        int v1, v2, w; cin >> v1 >> v2 >> w;
        edges.push({v1, v2 , w});
    }
    
    cout << Kruskal(V) << endl;
    
    return 0;
}
