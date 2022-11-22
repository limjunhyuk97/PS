#include <iostream>
#include <algorithm>
#include <set>
#define MAXLEN 505
#define NO_TREE "Case %d: No trees.\n"
#define ONE_TREE "Case %d: There is one tree.\n"
#define MORE_TREES "Case %d: A forest of %d trees.\n"

using namespace std;

int N, M;
int parent[505];

void initParent() {
    for(int i=0; i<MAXLEN; ++i){
        parent[i] = i;
    }
}

int find_parent(int a) {
    if(parent[a] == -1) return -1;
    if(parent[a] != a) {
        parent[a] = find_parent(parent[a]);
    }
    return parent[a];
}

void union_parent(int a, int b) {
    int a_parent = find_parent(a);
    int b_parent = find_parent(b);
    
    if(a_parent > b_parent) {
        parent[a_parent] = b_parent;
    }else {
        parent[b_parent] = a_parent;
    }
}

int main(void) {
    
    int a, b, a_parent, b_parent, case_count = 1;
    set<int> trees;
    
    while(true) {
        scanf("%d %d", &N, &M);
        if(N==0 && M==0) break;
        
        initParent();
        trees.clear();
        
        while(M--) {
            cin >> a >> b;
            a_parent = find_parent(a);
            b_parent = find_parent(b);
            
            if(a_parent == b_parent) {
                if(a_parent != -1) {
                    parent[a_parent] = -1;
                }
            }
            else {
                union_parent(a, b);
            }
        }
        
        for(int i=1; i<=N; ++i) {
            int parent = find_parent(i);
            if(parent != -1) trees.insert(parent);
        }
        
        int cnt = (int)trees.size();
        
        if(cnt == 0) printf(NO_TREE, case_count++);
        else if(cnt == 1) printf(ONE_TREE, case_count++);
        else printf(MORE_TREES, case_count++ , cnt);
    }
    
    return 0;
}
