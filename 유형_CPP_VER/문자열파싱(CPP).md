# 문자열 파싱 (CPP)

## 문자열 기준 파싱
 - string.find(기준자, 찾아내기 시작할 위치)
 - string.substr(시작위치, 잘라내어 반환할 총 길이)
 - pos != string::npos

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//***************** 함수 정의
// target : 잘라낼 문자열 . del : 끊어칠 기준 -> 끊어친 문자열 반환
vector<string> parse(const string &target, const string &del) {
    vector<string> result;
    int cur_pos = 0;                      // 문자열 덩어리 시작 위치
    int pos = 0;                          // 끊어칠 기준이 발견된 첫 인덱스 위치
    while((pos = (int)target.find(del, cur_pos)) != (int)string::npos) {     // pos에 끊어칠 기준이 발견된 첫 인덱스 위치값이 들어감
        int len = pos - cur_pos;
        result.push_back(target.substr(cur_pos, len));     // str.substr(시작 위치, 시작 위치 포함 잘라낼 길이)
        cur_pos = pos + (int)del.size();
    }
    result.push_back(target.substr(cur_pos));     // str.substr(마지막 시작 위치)
    return result;
}
//***************** 함수 정의


int main(void) {

    //***************** 함수 사용
    vector<string> res = parse("Hello X I'm X JUN", " X ");
    //***************** 함수 사용

    for(auto i : res) {
        cout << i << endl;
    }
    return 0;
}
```

## 한단어 기준 파싱
 - #include <sstream> 과 istringstream
 - getline(iss 문자열 스트림, 잘린 덩어리, 기준자)


```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//***************** 함수 정의
vector<string> parse(const string &target, const char &del) {
    vector<string> result;
    istringstream iss(target);        // string -> istringstream으로 변환
    string chunk;                   // 때마다 잘라낸 결과를 담을 변수
    while(getline(iss, chunk, del)) {     // pos에 끊어칠 기준이 발견된 첫 인덱스 위치값이 들어감
        result.push_back(chunk);
    }
    return result;
}
//***************** 함수 정의

int main(void) {

    //***************** 함수 사용
    vector<string> result = parse("HelloXI'mXJUN", 'X');
    //***************** 함수 사용
    
    for(auto iter : result) {
        cout << iter << endl;
    }

    return 0;
}

```

