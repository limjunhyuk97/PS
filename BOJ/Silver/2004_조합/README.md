# 1 ~ n 까지의 수 속에 존재하는 소인수 m의 갯수
  - (1 ~ n 까지 m의 수) + (1 ~ n 까지 m^2의 수) + (1 ~ n 까지 m^3의 수) + ... + (1 ~ n 까지 n보다 작은 m^k의 수)
  - (예) 1 ~ 5 까지의 수 속에 존재하는 소인수 2의 갯수
    - 2, 4 : 2 배수 (2개, + 2)
    - 4 : 4 배수 (1개, + 1)

```cpp
int numberOfDivisor(int n, int m) {
	if (n == 0) return 0;
	return n / m + numberOfDivisor(n / m, m);
}
```
