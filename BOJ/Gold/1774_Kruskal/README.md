## cout 소수점 이하 자리수 고정 방법
  - .precision(고정시킬 자리수 n) : 정수부 + 실수부 자리수의 갯수를 합해서 n개의 자리만큼 출력한다.
  - fixed + .precision(고정시킬 자리수 n) : 실수부 자리수의 갯수를 n개의 자리만큼 출력한다.

```cpp
cout.precision(5);
cout << 12.345567;
// 12.346 출력

cout << fixed;
cout.precision(5);
cout << 12.34557;
// 12.34557 출력

```
