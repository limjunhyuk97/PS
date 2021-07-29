#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge{
    int start;
    int end;
    int weight;
    bool operator<(const edge &other) const{
        return weight > other.weight;
    }
};

int V, E, A, B, C;
int parent[100005];
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
    int weight = parent[aroot] + parent[broot];
    
    if(aroot != broot){
        if(parent[aroot] < parent[broot]){
            parent[aroot] = broot;
            parent[broot] = weight;
        }
        else{
            parent[broot] = aroot;
            parent[aroot] = weight;
        }
    }
}

int Kruskal(){
    
    int ret= 0;
    
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
    
    cin >> V >> E;
    
    for(int i=0; i<100005; ++i){
        parent[i] = -1;
    }
    
    for(int i=0; i<E; ++i){
        cin >> A >> B >> C;
        Edges.push({A, B, C});
    }
    
    cout << Kruskal()<< "\n";
    
    return 0;
}
