# Bitmask인줄 알았는데 Brute Force

## 1. max_element를 뽑아내기 위한 compare 정의
```cpp
typedef pair<set<int>, int> bundle;

// max_element를 위한 정렬에서는 < 의 결과를 return 해주어야 한다.
bool compare(const bundle & b1, const bundle & b2){
    return b1.second < b2.second;
}
```

## 2. 가장 많은 정수 집합의 수를 구해내기 위해서 사용한 방법
```cpp
typedef pair<set<int>, int> bundle;

// map을 사용할 수 없으면 set을 사용해보자.
```



