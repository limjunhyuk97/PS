#  분할 정복

## 풀이법

- 가장 기본적으로 **분할 -> 정복 -> 병합**의 과정으로 문제를 해결한다.

### 1. 분할

- **n 단계를 n-1 단계로 나타내는 방법을 관찰**한다. (어떤 반복되는 절차가 나타나는가?)
- 예시
    - [프로그래머스] 유사 칸토어 비트열 : **문자열 f(n) = f(n-1)f(n-1){0...0}f(n-1)f(n-1) 의 구조**를 갖는다.
        - f(n-1)이 반복적으로 등장한다
    - [백준] a^b 구하기 : **f(n)을 a^n 연산이라 할 때, f(n) = f(n/2) \* f(n/2) \* A의 구조**를 갖는다.
        - f(n/2)가 반복적으로 등장한다
    - [백준] 별 찍기 - 10 : **애스터리스크(\*)가 그려지는 패턴이 다음과 같은 구조**를 갖는다.
        - f(n-1)이 반복적으로 등장한다
  
      ```c++
      // f(n) 은 다음의 구조를 갖는다.
      
      f(n-1)f(n-1)f(n-1)
      f(n-1)      f(n-1)
      f(n-1)f(n-1)f(n-1)
      
      // 예시
      ***     *********
      * *  -> * ** ** *
      ***     *********
              ***   ***
              * *   * *
              ***   ***
              *********
              * ** ** *
              *********
      ```
  
### 2. 정복

- **n-1 단계에서 분절된 여러 조각들을 정복하는 방법을 추출**한다.
- 예시
    - [프로그래머스] 유사 칸토어 비트열 : l ~ r 구간을 몇개의 f(n-1) 구간들로 분할할 수 있는가?
    - [백준] a^b 구하기 : a^(n/2) 연산을 한번 구해두고 계속 사용한다

### 3. 병합

- **해결된 n-1 단계의 조각들을 이어 붙혀서 n단계를 해결한다**

## 예시

### 1. Merge sort
  - 시간 복잡도는 O(nlogn)이지만, 다른 정렬방식에 비해 메모리를 더 사용한다.

```cpp
// 오름차순 정렬
void merge_array(int* origin, int* arrL, int* arrR, int left, int mid, int right) {
    int l = 0, r = 0, k = left;
    while (l < (mid - left) && r < (right - mid)) {
        if (arrL[l] <= arrR[r]) origin[k++] = arrL[l++];
        else origin[k++] = arrR[r++];
    }
    if (l == mid - left) for (; r < right - mid; ++r) origin[k++] = arrR[r];
    else for (; l < mid - left; ++l) origin[k++] = arrL[l];
}

void merge_sort(int* arr, int size) {

    // 종료 조건
    if (size == 1) return;

    // divide
    int half = size >> 1;
    int* arrL = (int*)malloc(sizeof(int) * (half));
    int* arrR = (int*)malloc(sizeof(int) * (size - half));
    copy_array(arr, arrL, 0, half);
    copy_array(arr, arrR, half, size);

    // conquer
    merge_sort(arrL, half);
    merge_sort(arrR, size - half);

    // combine
    merge_array(arr, arrL, arrR, 0, half, size);

}
```

### 2. a^b 구하기
  - O(b)의 시간복잡도를 O(logb)의 시간복잡도로 단축시킬 수 있다.

```cpp
int powAB(int a, int b) {
    if (b == 0) return 1;
    else if (b == 1) return a;
    else if (b % 2 == 0) {
        int t = powAB(a, b / 2);
        return t * t;
    }
    else {
        return a * powAB(a, b - 1);
    }
}
```

### 3. 대수 연산과 분할 정복
  - **거듭 제곱 연산에 대한 mod 연산** : 분할 정복의 방법 (O(logN)의 복잡도로 구현 가능)
  - **곱셈 연산에 대한 mod 연산** : (a * b) % n == ( (a % n) * (b % n) ) % n
  - **나눗셈 연산에 대한 mod 연산** : 페르마의 소정리를 통한 연산 구현


