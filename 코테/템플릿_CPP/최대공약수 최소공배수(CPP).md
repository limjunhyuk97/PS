# 최대 공약수 / 최소 공배수

## 최대 공약수

```cpp
#include <algorithm>

int gcd(int m, int n) {
    if(m < n) swap(m, n);
    if(n == 0) return m;
    return gcd(n, m % n);
}

```

## 최소 공배수

```cpp
#include <algorithm>

int gcd(int m, int n) {
    if(m < n) swap(m, n);
    if(n == 0) return m;
    return gcd(n, m % n);
}

int lcm(int m, int n) {
    return m * n / gcd(m, n);
}
```
