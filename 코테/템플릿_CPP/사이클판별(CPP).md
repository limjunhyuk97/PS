# 그래프에서의 사이클 확인

## 무향 그래프

### 분리 집합(유니온 파인드)으로 판별

- parent 배열 초기화
    - 각 노드가 루트 노드인 forest를 형성
- 유니온 파인드를 사용하여 **엣지로 연결된 노드를 하나의 공통 조상으로 묶는다.**
    - 이때, "작은노드번호 <- 큰노드번호"의 규칙으로 "부모<-자식" 관계를 맺는다.
- 엣지들을 바탕으로 공통 조상으로 묶다보면, **이미 해당 조상으로 묶여진 경우가 생기는데, 이 경우 사이클**이다.
    - 사이클인 경우 해당 사이클의 조상을 -1로 설정한다.
- 예
    - (1, 2) : "1 <- 2"
    - (2, 3) : "1 <- 2 <- 3"
    - (3, 1) : 이미 3의 조상이 1이었으므로 사이클! : "-1 <- 1 <- 2 <- 3"

```cpp
// find : cycle인 경우(-1)와 아닌 경우 구분(0보다 큰 정수)
int find_parent(int a) {
    if(parent[a] == -1) return -1;
    if(parent[a] != a) {
        parent[a] = find_parent(parent[a]);
    }
    return parent[a];
}

// union
void union_parent(int a, int b) {
    int a_parent = find_parent(a);
    int b_parent = find_parent(b);
    if(a_parent < b_parent) {
        parent[b_parent] = a_parent;
    } else {
        parent[a_parent] = b_parent;
    }
}

// cycle 판별
int a_parent = find_parent(a);
int b_parent = find_parent(b);

if(a_parent == b_parent) {          // cycle인 경우
    if(a_parent != -1) {
        parent[a_parent] = -1;
    }
}
else {                              // cycle 아닌 경우
    union_parent(a, b);
}
```

## 유향 그래프

### DFS 로 판별

- DFS를 재귀적으로 
