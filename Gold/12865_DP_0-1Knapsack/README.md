# 0-1 Knapsack Problem

## 01. KnapSack Problem 종류

### 1. Fractional Knapsack : 물건을 쪼갤 수 있다
### 2. 0-1 Knapsack : 물건을 쪼갤 수 없다.


## 02. [0-1 Knapsack Problem](https://gsmesie692.tistory.com/113)

### 1. 최적의 원리가 성립하는가?
  - **입력사례의 최적해가, 입력사례를 분할한 부분사례에 대한 최적해를 항상 포함하고 있는가?**
  - **문제를 동일한 원리의 여러 부분 단계로 분할할 수 있고, 분할된 단계들에 적용된 최적의 해결과정이 궁극적인 해결의 방식과 일치하는가?**

### 2. DP를 사용한다
  - divide and conquer 기능에 기반을 둔다.
  - 이전에 계산된 정보를 다시 사용하는 memoization 기능이 핵심이다.

### 3. 풀이 과정

<img src="https://user-images.githubusercontent.com/59442344/123507000-19278b00-d6a2-11eb-8a9b-10831bd5407b.jpg" height=80% width=80%>
