# vector (CPP)
 
- 스택 자료구조 (push_back, pop_back)
 
## 벡터 선언 / 초기화
 - vector<type> v : 빈 벡터 생성
 - vector<type> v(c) : 0으로 초기화된 원소 c개로 이루어진 벡터 생성
 - vector<type> v(c, v) : v로 초기화된 원소 c개로 이루어진 벡터 생성
 - vector<type> v1(v2) : 벡터 복사 (깊은 복사가 이뤄짐)
 
## 벡터 요소 추가
 - v.assign(c, v) : 배열에 c개의 v 원소를 할당. 기존에 있던 것 지워짐
 - v.at(idx) : 범위를 체크하여 idx번째 요소 참조
 - v.push_back(n) : 맨 뒤에 요소 n 추가
 - v.insert(iter, v) : iterator로 가리키는 특정 지점에 / v를 넣고 / 나머지 요소들은 뒤로 민다.
 - v.insert(iter, c, v) : iterator로 가리키는 특정 지점에서 부터 / c개 만큼 / v를 넣고 / 나머지 요소들은 뒤로 민다.
    - v = [1,2,3,4,5] 일때
    - v.insert(v.begin()+2, 3, 10) 을 하면 인덱스 2인 지점 부터 10이라는 값이 3개 들어간다.
    - 결과적으로 [1, 2, 10, 10, 10, 3, 4, 5] 가 된다.

## 벡터 요소 검색
 - v.at(idx) : 범위 체크O, idx 번째 요소에 읽기 / 쓰기.
 - v[idx] : 범위 체크X, idx 번째 요소에 읽기 / 쓰기.
 - v.front() : 맨 앞 요소 참조
 - v.back() : 맨 뒤 요소 참조
 - v.begin() : 맨 앞 요소 iterator 반환 (포인터)
 - v.end() : 맨 뒤 요소 iterator 반환 (포인터)
 - v.rbegin() : 거꾸로 맨 처음 요소 = 맨 뒤 요소 iterator 반환 (포인터)
 - v.rend() : 거꾸로 맨 뒤 요소 다음 것 = 맨 앞 이전 iterator 반환 (포인터)
 
## 벡터 요소 삭제
 - v.clear() : 요소 전부 삭제
 - v.pop_back() : 맨 뒤에 요소 제거
 - v.erase(iter) : 특정 iterator(포인터)가 가리키는 요소를 제거한다.
 
## 벡터 공간 확보
 - v.resize(c) : c 사이즈로 벡터 사이즈 변경 / 커지면 0으로 인자 초기화
 - v.resize(c, v) : c 사이즈로 벡터 사이즈 변경 / 커지면 v로 인자 초기화
 
## 벡터 정보
 - v.size() : 벡터내 원소 수 반환
 - v.empty() : 벡터내 원소 없으면 true, 있으면 false
 
## 벡터 순회
 - for(auto i : v) : 벡터 내 요소들을 읽기 전용으로 순회
 - for(auto iter = v.begin(); iter !=v.end(); ++iter) : 벡터 내 요소들을 iterator로 순회 (포인터 접근)
 - for(auto iter = v.rbegin(); iter != v.rend(); ++iter) : 벡터 내 요소들을 거꾸로 iterator로 순회 (포인터 접근)
 
## 벡터 정렬
 - sort(v.begin(), v.end(), cmp 함수) : v를 cmp 함수의 정의에 따라서 정렬해준다. / cmp 함수는 bool 반환.
    - cmp없는 pair 정렬 : first, second 모두 오름차순으로
    - cmp없는 int 정렬 : 오름차순

```
bool cmp(const p &p1, const p &p2) {
    if(p2.first == p1.second) return p1.second > p2.second;
    else return p1.first > p2.first;
}
 
sort(v.begin(), v.end(), cmp);
```
 
## 벡터 중복 제거
 - algorithm 헤더의 sort, unique + v.erase()를 이용.
 - sort를 사용하여 1차적으로 정렬
 - unique를 사용하면 v를 순회하면서 연속으로 등장하는 놈들을 뒤로 밀어버리고, 뒤로 밀어버린 부분의 첫 부분의 iterator를 반환한다.
 - v.erase() 를 통해서 뒤에를 날려버린다.
 
```
sort(v.begin(), v.end());
v.erase( unique(v.begin(), v.end()), v.end() )
```

## 테스트 공간

```
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> p;

bool cmp(const p &p1, const p &p2) {
    if(p2.first == p1.second) return p1.second > p2.second;
    else return p1.first > p2.first;
}

int main(void) {
     
    vector<p> v1(5, {1, 1});
    vector<p> v2(v1);
    
    v1[2]= {1, 3};
    v1.assign(5, {2,3});
    
    v1.insert(v1.begin() + 2, 4, {10,10});
    v1.insert(v1.begin()+1, {11, 11});
    
    for(auto n : v1) cout << n.first << " " << n.second << endl;
    cout << endl << endl;
    
    sort(v1.begin(), v1.end(), cmp);
    for(auto n : v1) cout << n.first << " " << n.second << endl;
    cout << endl << endl;
    
    auto garbage = unique(v1.begin(), v1.end());
    v1.erase(garbage, v1.end());
    for(auto n : v1) cout << n.first << " " << n.second << endl;
    
    return 0;
}
```
