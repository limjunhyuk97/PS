#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAXLEN 55
using namespace std;

struct Edges {
    int a, b, cost;
    bool operator<(const Edges &other) const {
        return cost < other.cost;
    }
};

int N;
int parent[MAXLEN];
vector<Edges> edges;

void init_parent() {
    for(int i=1; i<MAXLEN; ++i) {
        parent[i] = i;
    }
}

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

int toLength(const char alpthabet) {
    if('a' <= alpthabet && alpthabet <= 'z') return alpthabet - 'a' + 1;
    else return alpthabet - 'A' + 27;
}

int kruskal() {
    init_parent();
    
    sort(edges.begin(), edges.end());
    
    int cost = 0;
    int edges_selected = 0;
    
    for(int i=0; i<(int)edges.size(); ++i) {
        if(edges_selected == N-1) {
            break;
        }
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].cost;
        if(find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            edges_selected += 1;
            cost += w;
        }
    }
    
    if(edges_selected != N-1) return -1;
    else {
        int total_cost = 0;
        for(auto edge : edges) {
            total_cost += edge.cost;
        }
        return total_cost - cost;
    }
    
}

int main(void) {
    
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) {
        string tmp; cin >> tmp;
        for(int j=1; j<=N; ++j) {
            if(tmp[j-1] == '0') continue;
            edges.push_back({i, j, toLength(tmp[j-1])});
        }
    }
    
    printf("%d\n", kruskal());
    
    return 0;
}
