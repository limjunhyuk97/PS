# 유니온 파인드

## 부모 찾기 (find)

```cpp
int find_parent(int n) {
    if(n != parent[n]) {
        parent[n] = find_parent(parent[n]);
    }
    return parent[n];
}
```

## 합치기 (union)

```cpp
void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if(a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}
```
