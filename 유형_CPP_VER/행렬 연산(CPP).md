# 행렬 연산

## 행렬 정의

```cpp
#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<vector<ll> > matrix; 
```

## 행렬 덧셈

```cpp
matrix operator+ (const matrix &a, const matrix &b) {
    int size = (int)a.size();
    matrix ret(size, vector<ll>(size, 0));
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size; ++j) {
            ret[i][j] = (a[i][j] + b[i][j]) % MOD;
        }
    }
    return ret;
}
```

## 행렬 곱셈

```cpp
matrix operator* (const matrix &a, const matrix &b) {
    int row = (int)a.size();
    int col = (int)b[0].size();
    matrix ret(row, vector<ll>(col, 0));
    for(int i=0; i<row; ++i) {
        for(int j=0; j<col; ++j) {
            for(int k=0; k<(int)a[0].size(); ++k) {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return ret;
}
```

## 행렬의 거듭제곱 분할정복

- 거듭제곱 자체에 대해서 중복된 연산들을 분할 정복 가능하다. 

```cpp
matrix pow(const matrix & a, ll n) {
    int size = (int)a.size();
    matrix ret(size, vector<ll>(size, 0));
    
    // E 단위 행렬 설정 -> n이 0인 경우 반환
    for(int i=0; i<size; ++i) {
        ret[i][i] = 1;
    }
    
    // 0 제곱이면 E 반환
    if(n == 0) return ret;
    
    // 홀수 지수
    if(n % 2) return a * pow(a, n-1);
    
    // 짝수 지수
    ret = pow(a, n/2);
    return ret * ret;
}
```

## 행렬의 거듭제곱합 분할정복

- 거듭제곱의 합에서 '추출 가능한 중복된 연산들'도 분할 정복 가능하다. 

```cpp
// Sn = A^1 + A^2 + ... + A^n 의 형태라면
// Sn (n == 1) = A
// Sn (n 짝수) = (Sn/2) * (I + A^(n/2))
// Sn (n 홀수) = (Sn/2) * (I + A^(n/2)) + A^n
matrix Sn(const matrix &A, ll n) {
    int size = (int) A.size();
    // 단위 행렬
    matrix I(size, vector<ll>(size, 0));
    for(int i=0; i<size; ++i)
        I[i][i] = 1;
    if(n == 1) return A * I;
    // 분할 정복
    matrix An_2 = pow(A, n/2);
    // 연산
    matrix ret = Sn(A, n/2) * (I + An_2);
    return n % 2 == 0 ? ret : ret + pow(A, n);
}
```
