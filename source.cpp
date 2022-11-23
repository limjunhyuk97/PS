// 가상의 노드 만들기

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MAXLEN 305
using namespace std;

struct Edge {
    int a, b, cost;
    bool operator<(const Edge &other) const {
        return cost < other.cost;
    }
};

int N;
int parent[MAXLEN];
vector<Edge> edges;

int find_parent(int n) {
    if(parent[n] != n) {
        parent[n] = find_parent(parent[n]);
    }
    return parent[n];
}

void union_parent(int n, int m) {
    int n_parent = find_parent(n);
    int m_parent = find_parent(m);
    
    if(n_parent < m_parent) {
        parent[m_parent] = n_parent;
    } else {
        parent[n_parent] = m_parent;
    }
}

int kruskal() {
    for(int i=0; i<MAXLEN; ++i){
        parent[i] = i;
    }
    sort(edges.begin(), edges.end());
    
    int cost = 0;
    for(int i=0; i<(int)edges.size(); ++i) {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].cost;
        if(find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            cost += w;
        }
    }
    
    return cost;
}

int main(void) {
    
    scanf("%d", &N);
    
    for(int i=1; i<=N; ++i) {
        int weight; scanf("%d", &weight);
        edges.push_back({0, i, weight});
    }
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            int weight; scanf("%d", &weight);
            if(i < j) {
                edges.push_back({i, j, weight});
            }
        }
    }
    
    cout << kruskal() << endl;
    
    return 0;
}
