# 해결 과정중 닥친 문제와 해결방안

## 1. 산술평균 구하기 / 중앙값 구하기 / 범위

- 중앙값
  - sort 후에 중간 index 값 반환
- 범위
   - 입력과 동시에 min, max 찾아가기
   - 모든 입력 후 max - mins
 - 산술평균
   - **round() 함수를 이용하기**
     - round() 함수는 **소수 첫째자리에서 반올림을 진행**하여, 입력할때의 자료형 그대로를 반환한다.(template 형식)
       - **round(int형 / int형 == int 형) 하면 이미 안에서 소수점이 날아가 버림.**
       - **내부에서 실수로 형변환 해야함. -> round(int형 / double 형 == double 형)**
     - **음수의 반올림** : 절대값의 소수첫째자리에서 반올림한 값에 - 붙인 값을 반환한다.
     - 양수의 반올림 : 소수 첫째자리에서 반올림 진행하여 반환한다.
     - **원하는 자리에서의 반올림과 음수의 반올림하려면, 식의 변형이 필요하다.**
     
```cpp

#include <cmath>

// template double round(T x);

double round(double num); 
float round(float num); 
long double round(long double num); 

// 특정 소수점 자리에서의 반올림
// ex) 4번째 자리에서 반올림 하기

double PI = 3.141592;
cout << round(PI * pow(10, 3)) / pow(10 ,3) << endl;
// 출력 : 3.142

// round(int / int)와, round(int / double)

cout << round( 1 / 2 ) << " ";
cout << round( 1 / (double)2) << endl;
// 출력 : 0 1

```
  
## 2. 두번째로 작은 최빈값 구하기
    - 빈도를 저장하는 배열을 전역에 선언
    - 같은 빈도 중 제일 작은 수와, 다음으로 작은 수 저장할 배열[2] 선언.
      - **발생한 문제) -4000 ~ 4000사이의 값인 0을 특정 경우의 FLAG로 선언했더니 예외의 경우가 발생**
      - **문제 해결) FLAG 값을 설정할 때는, 상황에 구애받지 않는 완전 관계 없는 값으로 설정하자..**
    
```cpp

// FLAG 값을 0으로 설정했더니, -4000 ~ 4000 사이의 값과 연관되어 문제 발생
// 완전 관련없는 5000으로 설정 후, 오류 해결

// 최빈값
	if (mode[0] == FLAG)
		cout << mode[1] << '\n';
	else
		cout << mode[0] << '\n';
    
```
