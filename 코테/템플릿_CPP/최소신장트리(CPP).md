# 최소 신장 트리

## 크루스칼

- edge weight 크기 기준으로 오름차순으로 정렬한다.
- 작은 weight를 갖는 edge부터 뽑아낸다.
- 이때 cycle을 만들어내지 않는 것으로 뽑아낸다. -> union / find 사용

```cpp
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
    // forest 생성
    for(int i=0; i<MAXLEN; ++i){
        parent[i] = i;
    }
    
    // edge 정렬
    sort(edges.begin(), edges.end());
    
    // 모든 edge에 대해서 선택 실시
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
```

## 여러 테크닉

### 물대기 (BOJ 1368) : 가상의 노드

- edge와 node 모두에 cost가 존재한다.
- graph가 주어졌을 때, edge, node를 적절히 골라서 cost가 가장 작은 forest를 구성하라.
- 여러 방식이 있겠지만, **node에 주어진 cost도 마치 edge의 cost처럼 바꿔버리는 편리한 방식**을 사용할 수 있다.
    - dijkstra 알고리즘에서도 첫 순회를 시작할 때의 설정을 위해 사용되는 테크닉이다.
    - 모든 node와 연결된 가상의 노드 하나를 설정하고, "가상노드 - 각노드"를 연결하는 edge cost를 각 노드에 부여된 cost로 생각한다.
- 그림은 해당 블로그 참고 : [https://conkjh032.tistory.com/386](https://conkjh032.tistory.com/386)

<img width="461" alt="image" src="https://user-images.githubusercontent.com/59442344/203467585-80f2a240-2bca-4a52-9888-6f991df3f13b.png">

<img width="487" alt="image" src="https://user-images.githubusercontent.com/59442344/203467622-65489e26-f162-4c0c-8975-e00c341519b9.png">
