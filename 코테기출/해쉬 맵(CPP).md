# map (CPP)
 
## map 구조
 - key-value 쌍으로 이루어진 트리
 - 검색 / 삽입 / 삭제에 소요되는 시간이 O(logN) 인 레드블랙 트리로 구성되어 있다.
 - {first, second} 값을 저장할 수 있는 pair 형태로 값을 저장한다.

## map 선언
 - map<key, value> 식별자명;

## map 초기 정렬
 - key를 기준으로 기본적으로 오름차순으로 정렬한다.
 - map<key, value, greater> 이면 내림차순으로 정렬한다.
 
## map 나중 정렬
 - map의 값들을 먼저 vector<type> v(map.begin(), map.end())를 통해 전달해야 한다.
 - sort 함수, 함수에 전달할 비교를 위한 함수를 전달한다.
 - sort(v.begin(), v.end(), cmp)
    - 오름차순
        bool ascending(const pair<int, int> &p1, const pair<int, int> &p2) {
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second < p2.second;
        }
    - 내림차순
        bool descending(const pair<int, int> &p1, const pair<int, int> &p2) {
            if(p1.second == p2.second) return p1.first > p2.first;
            return p1.second > p2.second;
        }

## map 인자 추가
 - m.insert({key, value}) : key, value 쌍을 map에 집어 넣는다.

## map value 접근
 - m[key] : key값을 통해서 value 값을 가져온다.
    - m[key]를 통해 value로 접근하려 시도할 때 key값이 map에 없다면 {key, 임의의 값} 쌍이 map에 들어가게 되므로 조심!
    - 때문에 반복자를 통한 접근이 제일 안전하다.
 
## map key-value 접근
 - m.find(key)->first : key값을 통해서 반복자를 가져온뒤->key 값을 가져온다. (포인터로 접근하는 방식)
 - m.find(key)->second : key값을 통해서 반복자를 가져온뒤->value 값을 가져온다. (포인터로 접근하는 방식)
 - m.lower_bound(key) : key 요소 있다면 해당 위치의 반복자 가져온다.
 - m.upper_bound(key) : key 요소 있다면 해당 위치 다음 위치의 반복자 가져온다.

## map key-value 존재 유무
 - m.find('key') != m.end() : [참] key-value 쌍이 존재 / [거짓] key-value 쌍이 없음
 
## map 순회
 - for(auto iter = m.begin(); iter !=m.end() ; ++iter) : 반복자(포인터)를 통한 map 정방향 순회
 - for(auto iter = m.rbegin(); iter != m.rend(); ++iter) : 반복자(포인터)를 통한 map 역방향 순회
 - for(auto iter : m) : 변수를 통한 map 순회
 
## map 인자 제거
 - m.erase(key) : key 값으로 요소 삭제
 - m.erase(m.begin() + 3) : 시작하는 위치에서부터 3번째 떨어진 곳의 요소 삭제
 - m.erase(m.begin(), m.end()) : 모든 요소 삭제
 - m.clear() : 모든 요소 삭제
 
## map 인자 값 변경
 - m[key] = other : 값 변경



```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;

typedef pair<int, int> p;
map<int, int> map01;

bool ascending (const p &p1, const p &p2) {
    if(p1.second == p2.second) return p1.first < p2.first;
    else return p1.second < p2.second;
}

bool descending (const p &p1, const p &p2) {
    if(p1.second == p2.second) return p1.first > p2.first;
    else return p1.second > p2.second;
}

int main(void) {
    
    // 값 insert
    map01.insert({1, 3});
    map01.insert({1, 4});
    map01.insert({2, 4});
    map01.insert({3, 10});
    map01.insert({10, 1});
    
    
    
    
    // 출력 예시 : map의 key에 대한 오름차순 정렬
    for(auto iter : map01) {
        printf("%d %d\n", iter.first, iter.second);
    }
    
    printf("\n");
    for(auto iter = map01.begin(); iter != map01.end(); ++iter) {
        printf("%d %d\n", iter->first, iter->second);
    }
    
    
    
    
    // map -> vector : value 오름차순
    vector<p> v(map01.begin(), map01.end());
    sort(v.begin(), v.end(), ascending);
    
    printf("\n");
    for(auto iter : v) {
        printf("%d %d\n", iter.first, iter.second);
    }
    
    printf("\n");
    for(auto iter = v.begin(); iter != v.end(); ++iter) {
        printf("%d %d\n", iter->first, iter->second);
    }
    
    
    
    
    // map -> vector : value 내림차순
    vector<p> v2(map01.begin(), map01.end());
    sort(v2.begin(), v2.end(), descending);
    
    printf("\n");
    for(auto iter : v2) {
        printf("%d %d\n", iter.first, iter.second);
    }
    
    printf("\n");
    for(auto iter = v2.begin(); iter != v2.end(); ++iter) {
        printf("%d %d\n", iter->first, iter->second);
    }
    
    return 0;
}
```
