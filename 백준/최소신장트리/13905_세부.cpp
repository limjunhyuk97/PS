// Kruskal : Edge를 기준으로 union-find하여 연결성 확인
#include <iostream>
#include <vector>
#include <queue>
#define MINW -10
#define MAXW 2000000000
#define MAXNODES 100005
#define MAXEDGES 300005
using namespace std;

struct edge {
    int start;
    int end;
    int weight;
    
    bool operator<(const edge & other) const {
        if(weight != other.weight) return weight < other.weight;
        else return start < other.start;
    }
};

int N, M;
int s, e;
int minW = MAXW, maxW = MINW, answer;

priority_queue<edge> edges;

int findParent(int n, int* parent) {
    if(*(parent + n) != n) {
        *(parent + n) = findParent(*(parent + n), parent);
    }
    return *(parent + n);
}

void joinParent(int n, int m, int *parent) {
    int nParent = findParent(n, parent);
    int mParent = findParent(m, parent);
    
    if(nParent < mParent) *(parent+mParent) = nParent;
    else *(parent+nParent) = mParent;
}

bool kruskal(int maxWeight, priority_queue<edge> edges) {
    
    int parent[MAXNODES];
    
    for(int i=0; i<MAXNODES; ++i) parent[i] = i;
    
    while(!edges.empty()) {
        edge cur = edges.top();
        edges.pop();
        
        if(cur.weight < maxWeight) break;
        
        int startParent = findParent(cur.start, parent);
        int endParent = findParent(cur.end, parent);
        
        if(startParent != endParent) joinParent(startParent, endParent, parent);
    }
    
    int sParent = findParent(s, parent);
    int eParent = findParent(e, parent);
    
    return sParent == eParent;
}

int main(void) {
    
    cin >> N >> M;
    cin >> s >> e;
    
    for(int i=0; i<M; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        
        edges.push({start, end, weight});
        
        minW = minW < weight ? minW : weight;
        maxW = maxW < weight ? weight : maxW;
    }
    
    int mid = (minW + maxW) >> 1;
    
    while(maxW >= minW) {
        mid = (minW + maxW) >> 1;
        if(kruskal(mid, edges)) minW = mid + 1;q
        else maxW = mid - 1;
    }
    
    cout << maxW << endl;
    
    return 0;
}
