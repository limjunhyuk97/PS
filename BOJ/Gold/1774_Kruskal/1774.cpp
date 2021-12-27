#include <iostream>
#include <cmath>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> coordinate;

struct edge{
    int start;
    int end;
    double weight;
    bool operator<(const edge &other) const{
        return weight > other.weight;
    }
};

int N, M, a, b, preC1, preC2;
int parent[100005];
vector<coordinate> loc;
priority_queue<edge> Edges;

int Find(int a){
    
    int root = a;
    for(; parent[root] >= 0; root = parent[root]);
    
    while(root != a){
        int tmp = parent[a];
        parent[a] = root;
        a = tmp;
    }
    
    return root;
}

void Union(int a, int b){
    int aroot = Find(a);
    int broot = Find(b);
    int tmp = parent[aroot] + parent[broot];
    
    if(aroot != broot){
        if(parent[aroot] < parent[broot]){
            parent[aroot] = broot;
            parent[broot] = tmp;
        }
        else{
            parent[broot] = aroot;
            parent[aroot] = tmp;
        }
    }
}

double Kruskal(){
    
    double ret= 0;
    
    while(!Edges.empty()){
        
        edge e = Edges.top(); Edges.pop();
        
        int v1 = e.start;
        int v2 = e.end;
        
        if(Find(v1) != Find(v2)){
            Union(v1, v2);
            ret += e.weight;
        }
        
    }
    
    return ret;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<100005; ++i){
        parent[i] = -1;
    }
    
    for(int i=0; i<N; ++i){
        cin >> a >> b;
        loc.push_back({a, b});
    }
    
    for(int i=0; i<M; ++i){
        cin >> a >> b;
        Union(a - 1, b - 1);
    }
 
    for(int i = 0; i < loc.size(); ++i){
        for(int j= i+1; j<loc.size(); ++j){
            Edges.push({i, j, (double)sqrt( (double)pow((double)(loc[i].first - loc[j].first), (double)2) + (double)pow((double)(loc[i].second - loc[j].second), (double)2) ) });
        }
    }
    
    cout<< fixed;
    cout.precision(2);
    cout << Kruskal()<< "\n";
    
    return 0;
}
