## 해결 방법
  - X -> Y로 연결하는 선분들이 서로 겹치지 않게 하는 방법 : **DP를 이용하여 longest Increasing Subsequence를 구하는 것**

## 까먹지 말자 제발

### 1. pair
  - typedef 선언 이용하기
  - make_pair로 간결한 pair 생성
  - 연산자 오버로딩 이용한, pair의 sorting 연산

```java
// 1. typedef를 이용한 간결한 사용
typedef pair<int, int> P1;

// 2. pair 생성 - make_pair( , ) 사용하는 방식
P1 p1 = make_Pair(2, 3);
P1 p2 = pair<int, int>(2, 3);

// 3. 연산자 오버로딩과 pair sorting 연산
// ( , ) 연산에서 비교연산이 일어나도록, pair에 대한 연산자 오버로딩을 구현하여 sort 함수에 넣어준다.
struct Comp{
  bool operator()(pair<int, int> n, pair<int, int> m){
    return n.first < m.first; // 오름 차순
    // return n.first > m.first; // 내림 
  }
}
```
